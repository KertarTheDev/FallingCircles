#include "fcFallingCircleGL.h"
#include "fcFallingCircle.h"
#include "fcGameSettings.h"
#include "fcUtilities.h"
#include <cmath>
#include <QVector3D>

using namespace NfcGameSettings;
using namespace NfcUtilities;

//==========================================================================
CfcFallingCircleGL::CfcFallingCircleGL(CfcFallingCircle *circle)
{
    this->mObject = circle;

    this->mVertexArray  = QSharedPointer<QVector<float> >(new QVector<float>);
    this->mColorArray   = QSharedPointer<QVector<float> >(new QVector<float>);

    prepareArrays();
}
//==========================================================================
//! \brief Converts a circle to triangles and randomly colors them
void CfcFallingCircleGL::prepareArrays()
{
// Prepare geometry
    prepareVertexArray();

// Add some random colours
    prepareColorArray();
}
//==========================================================================
void CfcFallingCircleGL::prepareColorArray()
{
    //update colour array only if the number of vertices changed to avoid colour flickering
    if((this->mColorArray->size()/valuesPerColor) != (this->mVertexArray->size()/coordsPerVertex))
    {
        QVector3D centerColor(uniformRandomVal(),uniformRandomVal(), uniformRandomVal());
        QVector3D previousColor(uniformRandomVal(),uniformRandomVal(), uniformRandomVal());
        for(int i=1;i<samplesPerCircle+1;++i)
        {
            QVector3D nextColor(uniformRandomVal(),uniformRandomVal(), uniformRandomVal());

            this->mColorArray->push_back(centerColor.x());
            this->mColorArray->push_back(centerColor.y());
            this->mColorArray->push_back(centerColor.z());

            this->mColorArray->push_back(previousColor.x());
            this->mColorArray->push_back(previousColor.y());
            this->mColorArray->push_back(previousColor.z());

            this->mColorArray->push_back(nextColor.x());
            this->mColorArray->push_back(nextColor.y());
            this->mColorArray->push_back(nextColor.z());

            previousColor = nextColor;
        }
        //last vertex is special, color has to coincide with the second vertex (first one is center)
        int lastColorStartIndex = this->mColorArray->size()-3;
        (*this->mColorArray)[lastColorStartIndex] = this->mColorArray->at(3);
        (*this->mColorArray)[lastColorStartIndex+1] = this->mColorArray->at(4);
        (*this->mColorArray)[lastColorStartIndex+2] = this->mColorArray->at(5);
    }
}
//==========================================================================
void CfcFallingCircleGL::prepareVertexArray()
{
    this->mVertexArray->clear();

    // aux variables
    CfcFallingCircle* circle = static_cast<CfcFallingCircle*>(this->mObject);
    float radius = circle->radius();
    QPointF center = circle->position()+QPointF(radius,radius);
    float angleStep = 360.0 / samplesPerCircle;

    // calculate vertex coords
    QPointF previousVertex(center+QPointF(radius,0));
    for(int i=1;i<samplesPerCircle+1;++i)
    {
        QPointF vertex(center+radius*QPointF(cos(i*angleStep*M_PI/180.0), sin(i*angleStep*M_PI/180.0)));

        this->mVertexArray->push_back(center.rx());
        this->mVertexArray->push_back(center.ry());

        this->mVertexArray->push_back(previousVertex.rx());
        this->mVertexArray->push_back(previousVertex.ry());

        this->mVertexArray->push_back(vertex.rx());
        this->mVertexArray->push_back(vertex.ry());

        previousVertex = vertex;
    }
}
//==========================================================================
