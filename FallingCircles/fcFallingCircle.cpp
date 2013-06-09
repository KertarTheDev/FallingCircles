#include "fcFallingCircle.h"
#include "fcFallingCircleGL.h"

//==========================================================================
CfcFallingObjectGlSP CfcFallingCircle::renderingData()
{
    if(this->mRenderingData.isNull())
        this->mRenderingData = CfcFallingObjectGlSP(new CfcFallingCircleGL(this));

    return this->mRenderingData;
}
//==========================================================================
