#pragma once

#include "fcRendererGL.h"
class QLCDNumber;

class CfcMainWindow : public QWidget
{
    Q_OBJECT
    
public:
    CfcMainWindow(QWidget *parent = 0);
    ~CfcMainWindow(){}

    QSharedPointer<CfcRendererGL> getRenderer(){return this->mRenderer;}

public slots:
    void slotSetScore(int score);

protected:
    QSharedPointer<CfcRendererGL> mRenderer;
    QLCDNumber* mScoreWidget;
};
