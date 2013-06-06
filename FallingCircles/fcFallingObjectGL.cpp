#include "fcFallingObjectGL.h"

CfcFallingObjectGL::CfcFallingObjectGL(): mObject(0)
{
    this->mVertexArray  = QSharedPointer<QVector<float> >(new QVector<float>);
    this->mColorArray   = QSharedPointer<QVector<float> >(new QVector<float>);

    prepareArrays();
}

//! \brief This virtual function converts a CfcFallingObject into geometry
//! and colour arrays required by the renderer and should be reimplemented in every subclass
//! This default implementation just draws a test triangle and ignores associated object.
void CfcFallingObjectGL::prepareArrays()
{
    //Set up vertex array to contain a test triangle
    *this->mVertexArray << 0.0 << 1.0
                        << 0.5 << 0.0
                        << 1.0 << 0.5;

    //Colour up the test triangle
    *this->mColorArray  << 1.0 << 0.0 << 0.0
                        << 0.0 << 1.0 << 0.0
                        << 0.0 << 0.0 << 1.0;
}

