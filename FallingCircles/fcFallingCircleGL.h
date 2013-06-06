#pragma once

#include "fcFallingObjectGL.h"
#include "fcFallingCircle.h"

class CfcFallingCircleGL : public CfcFallingObjectGL
{
private:
    CfcFallingCircleGL(){} // no default circle geometry

public:
    CfcFallingCircleGL(CfcFallingCircle* circle);

protected:
    void prepareArrays();
    float randomColorVal();

protected:
    static const int samplesPerCircle = 36; //why not? :)
};
