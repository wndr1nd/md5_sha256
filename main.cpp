#include "mainwindow.h"

#include <QApplication>
//E:/Riot Games/Calc.exe

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    if (argc == 2)
    {
       QDir dr(argv[1]);
       w.generate_hash(dr);
       return 0;
    }
    else
    {
    w.show();
    }
    return a.exec();
}
