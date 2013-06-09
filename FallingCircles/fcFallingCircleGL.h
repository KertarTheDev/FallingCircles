#pragma once

#include "fcFallingObjectGL.h"
class CfcFallingCircle;

class CfcFallingCircleGL : public CfcFallingObjectGL
{
private:
    CfcFallingCircleGL(){} // no default circle geometry

public:
    CfcFallingCircleGL(CfcFallingCircle* circle);
    virtual ~CfcFallingCircleGL(){}

    /*virtual*/ void prepareArrays();

private:
    void prepareColorArray();
    void prepareVertexArray();
};
