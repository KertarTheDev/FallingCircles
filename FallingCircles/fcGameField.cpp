#include "fcGameField.h"
#include "fcGameSettings.h"

using namespace NfcGameSettings;

//==========================================================================
CfcGameField::CfcGameField()
{
    mCoords = QRectF(QPointF(0,0),QSizeF(gameFieldWidth,gameFieldHeight));
}
//==========================================================================
CfcFallingObjectSP CfcGameField::object(int index)
{
    if(qBound(0,index,this->mFallingObjects.size())==index)
        return this->mFallingObjects[index];

    return CfcFallingObjectSP();
}
//==========================================================================
void CfcGameField::addObject(CfcFallingObjectSP newObject)
{
    if(newObject)
        this->mFallingObjects.push_back(newObject);
}
//==========================================================================
void CfcGameField::deleteObject(int index)
{
    if(qBound(0,index,this->mFallingObjects.size()))
        this->mFallingObjects.removeAt(index);
}
//==========================================================================
