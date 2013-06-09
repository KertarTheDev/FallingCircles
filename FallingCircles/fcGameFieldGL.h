#pragma once

#include "fcGameField.h"
#include <QVector>

class CfcGameFieldGL
{
private:
    CfcGameFieldGL(){}

public:
    CfcGameFieldGL(CfcGameField* gameField);

    void updateArrays();
    QSharedPointer<QVector<float> > vertexArray(){return this->mVertexArray;}
    QSharedPointer<QVector<float> > colorArray(){return this->mColorArray;}

protected:
    CfcGameField* mField;

    QSharedPointer<QVector<float> > mVertexArray;
    QSharedPointer<QVector<float> > mColorArray;
};

