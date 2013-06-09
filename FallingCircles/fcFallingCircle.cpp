#include "fcFallingCircle.h"
#include "fcFallingCircleGL.h"

//==========================================================================
bool CfcFallingCircle::contains(QPointF point)
{
    QPointF vectorToCenter = this->mPosition + QPointF(this->mRadius,this->mRadius) - point;
    float squaredNorm = vectorToCenter.rx()*vectorToCenter.rx() + vectorToCenter.ry()*vectorToCenter.ry();
    //compare distance to center vector's squared norm to circle's squared radius
    return ((this->mRadius*this->mRadius - squaredNorm) > 0);
}

CfcFallingObjectGlSP CfcFallingCircle::renderingData()
{
    if(this->mRenderingData.isNull())
        this->mRenderingData = CfcFallingObjectGlSP(new CfcFallingCircleGL(this));

    return this->mRenderingData;
}
//==========================================================================
