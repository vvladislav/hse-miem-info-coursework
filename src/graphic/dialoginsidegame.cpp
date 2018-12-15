#include "dialoginsidegame.h"
#include "ui_dialoginsidegame.h"
#include "mainwindow.h"
#include "gamewindow.h"
#include "maindialogwindow.h"
#include <QMessageBox>
#include <QDebug>
#include <QToolBar>
#include <QMenuBar>
#include <QAction>
#include <QShortcut>

dialogInsideGame::dialogInsideGame(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialogInsideGame)
{
    new QShortcut(QKeySequence(Qt::Key_Escape), this, SLOT(showMenu()));
    ui->setupUi(this);
}

dialogInsideGame::~dialogInsideGame()
{
    delete ui;
}

void dialogInsideGame::on_backToGame_clicked()
{
    hide();
}

void dialogInsideGame::on_backToMenu_clicked()
{
    gameWindow gameWin;
    mainDialogWindow mainDialog;
    dialogInsideGame dialogInside;
    QMessageBox::StandardButton proof = QMessageBox::question(this, "Information", "Are you sure? Information about session will be lost", QMessageBox::Yes | QMessageBox::No);
    if (proof == QMessageBox::Yes)
    {
        closeDialogInside();
        closeGameWindow();
        mainDialog.exec();
    }
    else
    {
        dialogInside.hide();
    }
}

void dialogInsideGame::closeDialogInside()
{
    dialogInsideGame dialogInside;
    dialogInside.close();
}

void dialogInsideGame::closeGameWindow()
{
    gameWindow gameWin;
    gameWin.close();
}

void dialogInsideGame::on_settingsButton_clicked()
{
}
