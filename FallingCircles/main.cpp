#include "fcMainWindow.h"
#include <QApplication>

//==========================================================================
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CfcMainWindow w;
    w.show();
    
    return a.exec();
}
//==========================================================================
