#include "All-include.h"
#include "Game.h"
#include "mainwindow.h"
#include "maindialogwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    mainDialogWindow g;
    g.show();

    return a.exec();
}
