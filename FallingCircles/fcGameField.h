#pragma once

#include <QList>
#include <QRect>
#include "fcFallingObject.h"

class CfcGameField
{
public:
    CfcGameField();

    int objectCount() {return mFallingObjects.size();}
    CfcFallingObjectSP object(int index);
    void addObject(CfcFallingObjectSP newObject);
    void deleteObject(int index);

    QRectF coords(){return this->mCoords;}
signals:


protected:
    QRectF mCoords;
    QList<CfcFallingObjectSP> mFallingObjects;
};
