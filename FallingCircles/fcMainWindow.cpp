#include "fcMainWindow.h"
#include <QVBoxLayout>
#include "fcGameSettings.h"
#include <QResizeEvent>
#include <QLCDNumber>

using namespace NfcGameSettings;
//==========================================================================
CfcMainWindow::CfcMainWindow(QWidget *parent): QWidget(parent)
{
    //vertical controls alignement
    QVBoxLayout* mainLayout = new QVBoxLayout;

    //playing field renderer
    mRenderer = QSharedPointer<CfcRendererGL>(new CfcRendererGL());
    mainLayout->addWidget(mRenderer.data(),7);

    QLCDNumber* scoreWidget = new QLCDNumber(6);
    scoreWidget->display(999999);
    mainLayout->addWidget(scoreWidget,1);

    //set up window properties
    this->setLayout(mainLayout);
    this->resize(500*gameFieldWidth,500*gameFieldHeight);
}
//==========================================================================
CfcMainWindow::~CfcMainWindow()
{
}
//==========================================================================
