#include "fcMainWindow.h"
#include <QVBoxLayout>
#include "fcGameSettings.h"
#include <QResizeEvent>
#include <QLCDNumber>
#include <QString>

using namespace NfcGameSettings;
//==========================================================================
CfcMainWindow::CfcMainWindow(QWidget *parent): QWidget(parent)
{
    //vertical controls alignement
    QVBoxLayout* mainLayout = new QVBoxLayout;

    //playing field renderer
    mRenderer = QSharedPointer<CfcRendererGL>(new CfcRendererGL());
    mainLayout->addWidget(mRenderer.data(),7);

    mScoreWidget = new QLCDNumber(6);
    mScoreWidget->display(0);
    mainLayout->addWidget(mScoreWidget,1);

    //set up window properties
    this->setLayout(mainLayout);
    this->resize(500*gameFieldWidth,500*gameFieldHeight);
}
//==========================================================================
void CfcMainWindow::slotSetScore(int score)
{
    this->mScoreWidget->display(QString("%1").arg(uint(score), 6, 10 ,QChar('0')));
}
//==========================================================================
