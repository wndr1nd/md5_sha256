#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    if (argc > 1)
    {      
       QDir dr(argv[1]);
       qDebug() << argv[1];
       std::string str = "";

       if (argc > 2)
       {
           str = argv[2];
           if (str != "sha256" && str != "md5")
           {
               return 0;
           }
       }
       w.generate_hash(&dr, str);
       return 0;
    }
    else
    {
    w.show();
    }
    return a.exec();
}
