#include "gamewindow.h"
#include "dialoginsidegame.h"
#include "ui_gamewindow.h"
#include <QMessageBox>
#include <string>
#include <fstream>
#include <QMessageBox>
#include <QDebug>
#include <QToolBar>
#include <QMenuBar>
#include <QAction>
#include <QShortcut>

gameWindow::gameWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gameWindow)
{
    new QShortcut(QKeySequence(Qt::Key_Escape), this, SLOT(showMenu()));
    ui->setupUi(this);
    //connect(open,SIGNAL(triggered()),this,Qt::AutoConnection);
    //connect(exit,SIGNAL(triggered()),this,SLOT(close()));
    /*QAction *exit = new QAction(tr("Exit"),this);
    QAction *Back_to_menu = new QAction(tr("Back to menu"),this);
    QAction *new_game = new QAction(tr("New Game"),this);
    exit->setShortcut(tr("Ctrl+F"));
    file->addAction(new_game);
    file->addAction(Back_to_menu);
    file->addAction(exit);
    connect(new_game,SIGNAL(triggered()),this,SLOT(new_game()));
    connect(exit,SIGNAL(triggered()),this,SLOT(close()));*/
}

void gameWindow::showMenu()
{
    dialogInsideGame dialog;
    dialog.setModal(true);
    hide();
    dialog.exec();
}

gameWindow::~gameWindow()
{
    delete ui;
}

