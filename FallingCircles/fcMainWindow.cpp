#include "fcMainWindow.h"
#include "fcRendererGL.h"

#include <QVBoxLayout>

//==========================================================================
CfcMainWindow::CfcMainWindow(QWidget *parent): QWidget(parent)
{
    //vertical controls alignement
    QVBoxLayout* mainLayout = new QVBoxLayout;

    //playing field renderer
    CfcRendererGL* playingField = new CfcRendererGL();
    mainLayout->addWidget(playingField);

    //set up window properties
    this->setLayout(mainLayout);
    this->resize(400,600);
}
//==========================================================================
CfcMainWindow::~CfcMainWindow()
{
}
//==========================================================================
