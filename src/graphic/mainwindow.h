#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Game.h"
#include "Game.h"
#include <QShortcut>
#include <QLabel>
#include "All-include.h"
#include "QPushButton"
#include "QTimer"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    Game* game_;
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void updateTime();

    void showMenu();

    void on_startGameButton_clicked();

    void on_quitButton_clicked();

    void on_loadButton_clicked();

    void on_saveButton_clicked();

    void on_editorButton_clicked();

    void on_backToMenu_clicked();

    void on_backToGame_clicked();

    void on_editorUnitsButton_clicked();

    void on_editorBuildingsButton_clicked();

    void on_editorBackButton_clicked();

    void on_backButton_clicked();

    void on_backButton_2_clicked();

    void on_settingsMainButton_clicked();

    void on_settingsDialogButton_clicked();

    void on_closeWindow_clicked();

    void on_recordsButton_clicked();

    void on_editorMapsButton_clicked();

private:
    QShortcut* escButton_;
    int gameMatrixX_ = 8;
    int gameMatrixY_ = 8;
    std::vector<std::vector<QLabel*>> gameMatrix_;
    std::vector<std::vector<QLabel*>> choosedMatrix_;
    std::vector<std::vector<QLabel*>> trainMatrix_;
    QTimer* timer_;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
