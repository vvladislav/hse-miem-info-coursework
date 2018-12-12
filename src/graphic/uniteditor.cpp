#include "uniteditor.h"
#include "ui_uniteditor.h"

unitEditor::unitEditor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::unitEditor)
{
    ui->setupUi(this);
    showFullScreen();
}

unitEditor::~unitEditor()
{
    delete ui;
}

void unitEditor::on_addObjButton_clicked()
{
/*    game_.addUnit(ui->sizeSpinBox,
                  ui->speedSpinBox,
                  ui->attackSpinBox,
                  ui->healthSpinBox);*/
    ui->sizeSpinBox->setValue(0);
    ui->speedSpinBox->setValue(0);
    ui->attackSpinBox->setValue(0);
    ui->healthSpinBox->setValue(0);
    // add sound
    // add image
}

void unitEditor::on_backButton_clicked()
{
    close();
}
