#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QDialog>
#include <vector>
#include <QPushButton>
#include <QLayout>

namespace Ui {
class gameWindow;
}

class gameWindow : public QDialog
{
    Q_OBJECT
public:
    explicit gameWindow(QWidget *parent = nullptr);
    ~gameWindow();
private slots:
    void showMenu();
    void showMatrix();
private:
    Ui::gameWindow *ui;
};


#endif // GAMEWINDOW_H
