#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mainwindow.h"
#include <QMessageBox>
#include <QPixmap>
#include "Game.h"
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    game_->readObjects();
    escButton_ = new QShortcut(QKeySequence(Qt::Key_Escape), this, SLOT(showMenu()));
    ui->setupUi(this);
    QPixmap pix(":/images/forMainWindow.jpg");
    int width = ui->label->width();
    int height = ui->label->height();
    ui->label->setPixmap(pix.scaled(width,height,Qt::KeepAspectRatio));
    ui->stackedWidget->setCurrentIndex(mainMenu);

    // from Mike's branch
    QObject::connect(ui->horizontalSlider, SIGNAL(valueChanged(int)), ui->lcdNumber, SLOT(display(int)));
    ui->radioButton1024->setChecked(true);
    ui->radioButton_2->setChecked(false);

    // for game menu
    for ( int i = 0; i < gameMatrixY_; ++i ) {
        std::vector<QLabel*> vec;
            for ( int j = 0; j < gameMatrixX_; ++j ) {
            QLabel* label = new QLabel;
            label->setText(".!.");
            ui->gameVision->addWidget(label,i,j);
            vec.push_back(label);
            }
        gameMatrix_.push_back(vec);
    }
    for ( int i = 0; i < 4; ++i ) {
        std::vector<QLabel*> vec;
            for ( int j = 0; j < 8; ++j ) {
            QLabel* label = new QLabel;
            ui->choosedLayout->addWidget(label,i,j);
            vec.push_back(label);
            }
        choosedMatrix_.push_back(vec);
    }
    // button up and down
    // late
    for ( int i = 0; i < 3; ++i ) {
        std::vector<QLabel*> vec;
            for ( int j = 0; j < 8; ++j ) {
            QLabel* label = new QLabel;
            ui->trainLayout->addWidget(label,i,j);
            vec.push_back(label);
            }
        trainMatrix_.push_back(vec);
    }
    // button up and down
    // late
    QPixmap pixColumn(":/images/column.jpg");
    ui->border->setPixmap(pixColumn.scaledToWidth(ui->border->width()));
    ui->border_2->setPixmap(pixColumn.scaledToWidth(ui->border_2->width()));

    // timer for real-time game
    timer_ = new QTimer(this);
    timer_->setInterval(1000);
    connect(timer_, SIGNAL(timeout()), this, SLOT(updateTime()));
    timer_->start();

}

MainWindow::~MainWindow()
{
    delete timer_;
    delete ui;
}

void MainWindow::updateTime() {
    game_->makeTurn();
    // refresh gameGui
    for ( int i = 0; i < gameMatrixY_; ++i ) {
        for ( int j = 0; j < gameMatrixX_; ++j ) {
            if ( game_->map_[i][j].getObject().second != -1 ) {
                gameMatrix_[i][j]
                    ->setPixmap(game_->players_[game_->map_[i][j].getObject().first.first]
                    .get// MARK
                    .image_->scaledToWidth(ui->border_2->width()));
            }
            else {
                gameMatrix_[i][j]
                    ->setPixmap(game_->map_[i][j].getTerrain()
                    .image_->scaledToWidth(ui->border_2->width()));
            }
        }
    }
}

void MainWindow::showMenu()
{
    if (ui->stackedWidget->currentIndex() == gameGui) {
        ui->stackedWidget->setCurrentIndex(gameMenu);
    }
    else {
        QMessageBox::StandardButton proof = QMessageBox::question(this, "Information", "Are you sure? Information about session will be lost", QMessageBox::Yes | QMessageBox::No);
        if (proof == QMessageBox::Yes)
        {
            close();
        }
    }
}

void MainWindow::on_startGameButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(gameGui);
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
    ui->stackedWidget->setCurrentIndex(editorMenu);
}

void MainWindow::on_backToMenu_clicked()
{
    ui->stackedWidget->setCurrentIndex(mainMenu);
}

void MainWindow::on_backToGame_clicked()
{
    ui->stackedWidget->setCurrentIndex(gameGui);
}

void MainWindow::on_editorUnitsButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(editorUnitMenu);
}

void MainWindow::on_editorBuildingsButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(editorBuildingMenu);
}

void MainWindow::on_editorBackButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(mainMenu);
}
void MainWindow::on_backButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(editorMenu);
}

void MainWindow::on_backButton_2_clicked()
{
     ui->stackedWidget->setCurrentIndex(editorMenu);
}

void MainWindow::on_settingsMainButton_clicked()
{
     ui->stackedWidget->setCurrentIndex(settingsMenu);
}

void MainWindow::on_settingsDialogButton_clicked()
{
     ui->stackedWidget->setCurrentIndex(settingsMenu);
}

void MainWindow::on_closeWindow_clicked()
{
     ui->stackedWidget->setCurrentIndex(mainMenu);
}

void MainWindow::on_recordsButton_clicked()
{
}

void MainWindow::on_editorMapsButton_clicked()
{
     ui->stackedWidget->setCurrentIndex(editorMapMenu);
}
