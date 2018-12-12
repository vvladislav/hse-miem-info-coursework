#ifndef MAINDIALOGWINDOW_H
#define MAINDIALOGWINDOW_H

#include <QDialog>

namespace Ui {
class mainDialogWindow;
}

class mainDialogWindow : public QDialog
{
    Q_OBJECT

public:
    explicit mainDialogWindow(QWidget *parent = nullptr);
    ~mainDialogWindow();

private slots:
    void on_startGameButton_clicked();

    void on_quitButton_clicked();

private:
    Ui::mainDialogWindow *ui;
};

#endif // MAINDIALOGWINDOW_H
