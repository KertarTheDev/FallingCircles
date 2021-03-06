#include "fcGameEngine.h"
#include "fcGameSettings.h"
#include "fcUtilities.h"
#include "fcFallingCircle.h"
#include "fcRendererGL.h"

using namespace NfcGameSettings;
using namespace NfcUtilities;

//==========================================================================
CfcGameEngine::CfcGameEngine(QSharedPointer<CfcRendererGL> renderer, QObject *parent) : QObject(parent)
{
    this->mRenderer = renderer;
    this->mGameFieldGL = QSharedPointer<CfcGameFieldGL>(new CfcGameFieldGL(&this->mGameField));
    this->mUpdateTimer.setInterval(gameStateUpdateInterval);
    this->mSpawnTimer.setInterval(objectSpawnInterval);
    this->mScore = 0;
}
//==========================================================================
void CfcGameEngine::start()
{
    emit signalCurrentScore(this->mScore);

    slotSpawnNewObjects();

    connect(&this->mSpawnTimer, SIGNAL(timeout()), this, SLOT(slotSpawnNewObjects()), Qt::UniqueConnection);
    this->mSpawnTimer.start();

    connect(&this->mUpdateTimer, SIGNAL(timeout()), this, SLOT(slotUpdateGameState()), Qt::UniqueConnection);
    this->mUpdateTimer.start();

    connect(this->mRenderer.data(), SIGNAL(signalClicked(QPointF)), this, SLOT(slotHandleClick(QPointF)), Qt::UniqueConnection);
}
//==========================================================================
void CfcGameEngine::slotUpdateGameState()
{
    updateExistingObjects();
    renderCurrentState();
}
//==========================================================================
//! \todo parallelise the code
void CfcGameEngine::updateExistingObjects()
{
    int objectsToUpdate = this->mGameField.objectCount();
    //going backwards to be able to delete objects
    for(int i=objectsToUpdate-1;i>-1;--i)
    {
        //for convenience
        CfcFallingObjectSP currObject = this->mGameField.object(i);
        //update objects position
        currObject->move(QPointF(0,currObject->fallSpeed()));
        //delete the object if it is outside of the game field
        if(currObject->position().ry()>this->mGameField.coords().bottom())
        {
            //decreasing score is disabled until I get parameters right
            //decreaseScore(currObject->scorePoints());
            this->mGameField.deleteObject(i);
        }
    }
}
//==========================================================================
void CfcGameEngine::slotSpawnNewObjects()
{
    for(int i=0;i<objectsSpawnedAtOnce;++i)
    {
        CfcFallingObjectSP newObject = generateCircle();

        this->mGameField.addObject(newObject);
    }
}
//==========================================================================
void CfcGameEngine::slotHandleClick(QPointF pos)
{
    int objectsToCheck = this->mGameField.objectCount();
    //going backwards to destroy most recent objects first
    for(int i=objectsToCheck-1;i>-1;--i)
    {
        //for convenience
        CfcFallingObjectSP currObject = this->mGameField.object(i);
        //update objects position
        if(currObject->contains(pos))
        {
            increaseScore(currObject->scorePoints());
            this->mGameField.deleteObject(i);
            renderCurrentState();
            break;
        }
    }
}
//==========================================================================
void CfcGameEngine::renderCurrentState()
{
    this->mGameFieldGL->updateArrays();
    this->mRenderer->setVertexArray(this->mGameFieldGL->vertexArray());
    this->mRenderer->setColorArray(this->mGameFieldGL->colorArray());
    this->mRenderer->updateGL();
}
//==========================================================================
CfcFallingObjectSP CfcGameEngine::generateCircle()
{
    //main parameter that determines all others
    float radius(uniformRandomVal(0.02, 0.1));

    //starting position. we make sure circle fits to screen completely
    //circles should be spawned outside of rendered area to appear smoothly
    QPointF pos(uniformRandomVal()*(gameFieldWidth-2*radius), -0.2);

    //falling speed: larger radius should result in slower fall
    float speed((gameStateUpdateInterval/1000.0)*(0.01/radius));

    //smaller circles give more score points
    int score = static_cast<int>(0.1/(radius*radius));

    CfcFallingObjectSP newCircle(new CfcFallingCircle(pos,speed,score,radius));
    return newCircle;
}
//==========================================================================
void CfcGameEngine::increaseScore(int pointsToAdd)
{
    this->mScore+=pointsToAdd;
    emit signalCurrentScore(this->mScore);
}
//==========================================================================
void CfcGameEngine::decreaseScore(int pointsToRemove)
{
    this->mScore-=pointsToRemove;
    if(this->mScore<0) this->mScore = 0;
    emit signalCurrentScore(this->mScore);
}
//==========================================================================
