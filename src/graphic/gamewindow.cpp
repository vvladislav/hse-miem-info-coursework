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
#include <vector>
#include <QLayout>
#include <QGridLayout>
#include <QLabel>
#include <QPixmap>

gameWindow::gameWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gameWindow)
{
    new QShortcut(QKeySequence(Qt::Key_Escape), this, SLOT(showMenu()));
    ui->setupUi(this);
    int n = 8;
    int m = 8;
    for ( int i = 0; i < n; ++i ) {
            for ( int j = 0; j < m; ++j ) {
            QLabel* but = new QLabel;
            but->setText(".!.");
            ui->gridLayout->addWidget(but,i,j);
            }
    }
}

void gameWindow::showMenu()
{
    dialogInsideGame* dialog = new dialogInsideGame;
    dialog->exec();
}

void gameWindow::showMatrix()
{/*
    int n = 69;
    int m = 69;
    gameWindow* action = new gameWindow;
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            QPushButton* but = new QPushButton;
        }
    }*/
}

gameWindow::~gameWindow()
{
    delete ui;
}

