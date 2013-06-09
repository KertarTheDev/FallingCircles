#pragma once

#include <QPoint>
#include <QSharedPointer>

class CfcFallingObject;
typedef QSharedPointer<CfcFallingObject> CfcFallingObjectSP;

class CfcFallingObjectGL;
typedef QSharedPointer<CfcFallingObjectGL> CfcFallingObjectGlSP;

//==========================================================================
class CfcFallingObject
{

public:
    //Constructors
    CfcFallingObject();
    CfcFallingObject(QPointF position, float speed, int scoreValue);
    virtual ~CfcFallingObject(){}

    //Manipulation functions
    void move(QPointF movementVector);
    virtual bool contains(QPointF /*point*/){return false;}

    //Getters/setters
    QPointF position() const {return this->mPosition;}
    void setPosition(QPointF position) {this->mPosition = position;}

    float fallSpeed() const {return this->mFallSpeed;}
    void setFallSpeed(float speed) {this->mFallSpeed = speed;}

    int scorePoints()const{return this->mScorePoints;}
    void setScorePoints(int scoreValue){this->mScorePoints = scoreValue;}

    virtual CfcFallingObjectGlSP renderingData();

protected:
    QPointF mPosition;   //coordinates of top left corner of the objects bounding box
    float mFallSpeed;
    int mScorePoints;
    CfcFallingObjectGlSP mRenderingData; //should be different for different falling objects
};
//==========================================================================
