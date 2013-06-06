#pragma once

#include <QPoint>

class CfcFallingObject
{

public:
    CfcFallingObject(): mPosition(0,0), mFallSpeed(1.0), mScorePoints(1){}

    CfcFallingObject(QPointF position, float speed, int scoreValue)
        : mPosition(position), mFallSpeed(speed), mScorePoints(scoreValue){}

    QPointF position() const {return this->mPosition;}
    void setPosition(QPointF position) {this->mPosition = position;}

    float fallSpeed() const {return this->mFallSpeed;}
    void setFallSpeed(float speed) {this->mFallSpeed = speed;}

    int scorePoints()const{return this->mScorePoints;}
    void setScorePoints(int scoreValue){this->mScorePoints = scoreValue;}

protected:
    QPointF mPosition;   //coordinates of top left corner of the objects bounding box
    float mFallSpeed;
    int mScorePoints;
};

