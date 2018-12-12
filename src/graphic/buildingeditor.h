#ifndef BUILDINGEDITOR_H
#define BUILDINGEDITOR_H

#include <QDialog>

namespace Ui {
class buildingEditor;
}

class buildingEditor : public QDialog
{
    Q_OBJECT

public:
    explicit buildingEditor(QWidget *parent = nullptr);
    ~buildingEditor();

private slots:
    void on_addObjButton_clicked();

private:
    Ui::buildingEditor *ui;
};

#endif // BUILDINGEDITOR_H
