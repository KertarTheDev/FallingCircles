#pragma once

#include "fcFallingObject.h"

class CfcFallingCircle : public CfcFallingObject
{
public:
    CfcFallingCircle(): CfcFallingObject(), mRadius(1.0){}

    CfcFallingCircle(float speed, int scoreValue, float radius)
        : CfcFallingObject(speed, scoreValue), mRadius(radius){}

protected:
    float mRadius;
};
