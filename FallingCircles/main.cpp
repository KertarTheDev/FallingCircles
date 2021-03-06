#include "fcMainWindow.h"
#include "fcGameEngine.h"
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

    CfcGameEngine gameEngine(w.getRenderer());
    QObject::connect(&gameEngine, SIGNAL(signalCurrentScore(int)), &w, SLOT(slotSetScore(int)), Qt::UniqueConnection);
    gameEngine.start();
    
    return a.exec();
}
//==========================================================================
