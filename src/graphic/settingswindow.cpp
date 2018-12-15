#include "settingswindow.h"
#include "ui_settingswindow.h"
#include "maindialogwindow.h"
#include "gamewindow.h"
#include <QObject>
#include <QMessageBox>

settingsWindow::settingsWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::settingsWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->horizontalSlider, SIGNAL(valueChanged(int)), ui->lcdNumber, SLOT(display(int)));
    ui->radioButton1024->setChecked(true);
    ui->radioButton_2->setChecked(false);
}

void settingsWindow::on_closeWindow_clicked()
{
    settingsWindow setWind;
    setWind.close();
}

settingsWindow::~settingsWindow()
{
    delete ui;
}

void settingsWindow::on_agreeButton_clicked()
{
    gameWindow gameWind;
    if(ui->radioButton1024->isChecked())
        gameWind.setGeometry(1024,768,1024,768);
    else
        gameWind.setGeometry(800,600,800,600);
}
