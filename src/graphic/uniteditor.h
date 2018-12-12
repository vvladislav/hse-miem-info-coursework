#ifndef UNITEDITOR_H
#define UNITEDITOR_H

#include <QDialog>

namespace Ui {
class unitEditor;
}

class unitEditor : public QDialog
{
    Q_OBJECT

public:
    explicit unitEditor(QWidget *parent = nullptr);
    ~unitEditor();

private slots:
    void on_addObjButton_clicked();

    void on_backButton_clicked();

private:
    Ui::unitEditor *ui;
};

#endif // UNITEDITOR_H
