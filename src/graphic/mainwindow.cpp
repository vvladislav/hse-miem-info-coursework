#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mainwindow.h"
#include "gamewindow.h"
#include <QMessageBox>
#include <QPixmap>
#include "Game.h"
#include <QFileDialog>
#include "editor.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix(":/new/images/images/forMainWindow.jpg");
    int width = ui->label->width();
    int height = ui->label->height();
    ui->label->setPixmap(pix.scaled(width,height,Qt::KeepAspectRatio));
}

void MainWindow::setGame( Game* game ) {
    game_ = game;
}

const Game* MainWindow::getGame() {
    return game_;
}

MainWindow::~MainWindow()
{
    delete ui;
}

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

void MainWindow::on_loadButton_clicked()
{
#ifdef __unix__
    char result[256];
    ssize_t count = readlink("/proc/self/exe", result, 256);
    std::string path;
    path = std::string(result , (count > 0) ? count : 0);
    for (int i = path.size() - 1 ; path[i] != '/' ; --i)
        path.pop_back();
        path += "../common/save/";
#endif
// There must be code for Windows
    auto fileName = QFileDialog::getOpenFileName(this,tr("Save"), QString::fromStdString(path),
                                                 tr("Save Files (*.save)"));
    game_->load(fileName.toUtf8().constData());
}

void MainWindow::on_saveButton_clicked()
{
#ifdef __unix__
    char result[256];
    ssize_t count = readlink("/proc/self/exe", result, 256);
    std::string path;
    path = std::string(result , (count > 0) ? count : 0);
    for (int i = path.size() - 1 ; path[i] != '/' ; --i)
        path.pop_back();
        path += "../common/save/";
#endif
// There must be code for Windows
    auto fileName = QFileDialog::getSaveFileName(this,tr("Save"), QString::fromStdString(path),
                                                 tr("Save Files (*.save)"));
    game_->save(fileName.toUtf8().constData());
}

void MainWindow::on_editorButton_clicked()
{
    Editor editor;
    editor.setModal(true);
    editor.exec();
}
