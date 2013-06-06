#pragma once

class CfcFallingObject
{

public:
    CfcFallingObject(): mFallSpeed(1.0), mScorePoints(1){}

    CfcFallingObject(float speed, int scoreValue)
        :mFallSpeed(speed), mScorePoints(scoreValue){}

    float fallSpeed() const {return this->mFallSpeed;}
    void setFallSpeed(float speed) {this->mFallSpeed = speed;}

    int scorePoints()const{return this->mScorePoints;}
    void setScorePoints(int scoreValue){this->mScorePoints = scoreValue;}

protected:
    float mFallSpeed;
    int mScorePoints;
};

