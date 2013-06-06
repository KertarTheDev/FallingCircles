#include "fcMainWindow.h"
#include <QApplication>
#include <QDateTime>

//==========================================================================
int main(int argc, char *argv[])
{
    //initialise pseudo-random number generator
    qsrand(QDateTime::currentMSecsSinceEpoch());

    QApplication a(argc, argv);
    CfcMainWindow w;
    w.show();
    
    return a.exec();
}
//==========================================================================
