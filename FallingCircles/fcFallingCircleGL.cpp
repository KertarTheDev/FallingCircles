#include "fcFallingCircleGL.h"
#include <cmath>
#include <QVector3D>

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

// Add some random colours
    this->mColorArray->clear();
    QVector3D centerColor(randomColorVal(),randomColorVal(), randomColorVal());
    QVector3D previousColor(randomColorVal(),randomColorVal(), randomColorVal());
    for(int i=1;i<samplesPerCircle+1;++i)
    {
        QVector3D nextColor(randomColorVal(),randomColorVal(), randomColorVal());

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
//==========================================================================
//! \brief Returns a pseudo-random value in the range [0,1]
float CfcFallingCircleGL::randomColorVal()
{
    return static_cast<float>(qrand())/RAND_MAX;
}
//==========================================================================
