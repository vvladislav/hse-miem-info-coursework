#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mainwindow.h"
#include "gamewindow.h"
#include <QMessageBox>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //QPixmap pix(":/new/images/images/forMainWindow.jpg");
    //int width = ui->label->width();
    //int height = ui->label->height();
    //ui->label->setPixmap(pix.scaled(width,height,Qt::KeepAspectRatio));
}


MainWindow::~MainWindow()
{
    delete ui;
}
/*
void MainWindow::on_startGameButton_clicked()
{
    gameWindow gameWin;
    gameWin.setModal(true);
    hide();
    gameWin.exec();
}

void MainWindow::on_quitButton_clicked()
{
    close();
}
*/
