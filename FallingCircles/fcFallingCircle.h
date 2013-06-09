#pragma once

#include "fcFallingObject.h"

class CfcFallingCircle : public CfcFallingObject
{
public:
    CfcFallingCircle(): CfcFallingObject(), mRadius(1.0){}

    CfcFallingCircle(QPointF position, float speed, int scoreValue, float radius)
        : CfcFallingObject(position, speed, scoreValue), mRadius(radius){}

    virtual ~CfcFallingCircle(){}

    float radius() const {return this->mRadius;}
    void setRadius(float radius) {this->mRadius = radius;}

    /*virtual*/ CfcFallingObjectGlSP renderingData();

protected:
    float mRadius;
};
