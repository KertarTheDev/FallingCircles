#pragma once

#include "fcRendererGL.h"

class CfcMainWindow : public QWidget
{
    Q_OBJECT
    
public:
    CfcMainWindow(QWidget *parent = 0);
    ~CfcMainWindow();

    QSharedPointer<CfcRendererGL> getRenderer(){return this->mRenderer;}

protected:
    QSharedPointer<CfcRendererGL> mRenderer;
};
