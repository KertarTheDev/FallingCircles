#pragma once

#include <QVector>
#include <QSharedPointer>
class CfcFallingObject;

class CfcFallingObjectGL
{
public:
    CfcFallingObjectGL();
    virtual ~CfcFallingObjectGL(){}

    QSharedPointer<QVector<float> > getVertexArray() {return this->mVertexArray;}
    QSharedPointer<QVector<float> > getColorArray() {return this->mColorArray;}

    virtual void prepareArrays();

protected:
    //! An associated game object to visualise.
    //! Ignored in the default implementation.
    CfcFallingObject* mObject;

    //! Geometrical representation of mObject
    QSharedPointer<QVector<float> > mVertexArray;

    //! Coloring corresponding to mVertexArray
    QSharedPointer<QVector<float> > mColorArray;
};
