#include "fcFallingObject.h"
#include "fcFallingObjectGL.h"

//==========================================================================
CfcFallingObject::CfcFallingObject(): mPosition(0,0), mFallSpeed(1.0), mScorePoints(1)
{
}
//==========================================================================
CfcFallingObject::CfcFallingObject(QPointF position, float speed, int scoreValue)
    : mPosition(position), mFallSpeed(speed), mScorePoints(scoreValue)
{
}
//==========================================================================
void CfcFallingObject::move(QPointF movementVector)
{
    this->mPosition+=movementVector;
}
//==========================================================================
CfcFallingObjectGlSP CfcFallingObject::renderingData()
{
    if(this->mRenderingData.isNull())
        this->mRenderingData = CfcFallingObjectGlSP(new CfcFallingObjectGL());

    return this->mRenderingData;
}
//==========================================================================
