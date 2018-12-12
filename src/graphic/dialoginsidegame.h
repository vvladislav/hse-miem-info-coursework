#ifndef DIALOGINSIDEGAME_H
#define DIALOGINSIDEGAME_H

#include <QDialog>

namespace Ui {
class dialogInsideGame;
}

class dialogInsideGame : public QDialog
{
    Q_OBJECT

public:
    explicit dialogInsideGame(QWidget *parent = nullptr);
    ~dialogInsideGame();

private slots:
    void on_backToGame_clicked();

    void on_backToMenu_clicked();

    void on_settingsButton_clicked();

private:
    Ui::dialogInsideGame *ui;
};

#endif // DIALOGINSIDEGAME_H
