#include "maindialogwindow.h"
#include "ui_maindialogwindow.h"
#include "mainwindow.h"
#include "gamewindow.h"
#include <QMessageBox>
#include <QPixmap>

mainDialogWindow::mainDialogWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mainDialogWindow)
{
    ui->setupUi(this);
    QPixmap pix(":/new/images/images/forMainWindow.jpg");
    int width = ui->label->width();
    int height = ui->label->height();
    ui->label->setPixmap(pix.scaled(width,height,Qt::KeepAspectRatio));
}

mainDialogWindow::~mainDialogWindow()
{
    delete ui;
}

void mainDialogWindow::on_startGameButton_clicked()
{
    gameWindow gameWin;
    gameWin.setModal(true);
    hide();
    gameWin.exec();
}

void mainDialogWindow::on_quitButton_clicked()
{
        close();
}
