#include <QApplication>
#include "mainwindow.h"

#include "globals.h"

MainOptions *mainOptions = new MainOptions();
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
