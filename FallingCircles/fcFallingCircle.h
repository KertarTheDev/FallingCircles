#pragma once

#include "fcFallingObject.h"

class CfcFallingCircle : public CfcFallingObject
{
public:
    CfcFallingCircle(): CfcFallingObject(), mRadius(1.0){}

    CfcFallingCircle(QPointF position, float speed, int scoreValue, float radius)
        : CfcFallingObject(position, speed, scoreValue), mRadius(radius){}

    float radius() const {return this->mRadius;}
    void setRadius(float radius) {this->mRadius = radius;}

protected:
    float mRadius;
};
