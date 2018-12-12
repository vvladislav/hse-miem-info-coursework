#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Game.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    void setGame( Game* game );
    const Game* getGame();
    ~MainWindow();

private slots:
    void on_startGameButton_clicked();
    void on_quitButton_clicked();

    void on_loadButton_clicked();

    void on_saveButton_clicked();

    void on_editorButton_clicked();

private:
    Ui::MainWindow *ui;
    Game* game_;
};

#endif // MAINWINDOW_H
