#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H

#include <QWidget>

namespace Ui {
class settingsWindow;
}

class settingsWindow : public QWidget
{
    Q_OBJECT
public:
    explicit settingsWindow(QWidget *parent = nullptr);
    ~settingsWindow();
private slots:
    void showValue();
    void on_closeWindow_clicked();
    void on_agreeButton_clicked();

private:
    Ui::settingsWindow *ui;
};

#endif // SETTINGSWINDOW_H
