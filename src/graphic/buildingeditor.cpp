#include "buildingeditor.h"
#include "ui_buildingeditor.h"

buildingEditor::buildingEditor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::buildingEditor)
{
    ui->setupUi(this);
    showFullScreen();
}

buildingEditor::~buildingEditor()
{
    delete ui;
}

void buildingEditor::on_addObjButton_clicked()
{
/*    game_.addUnit(ui->sizeSpinBox,
                  ui->speedSpinBox,
                  ui->attackSpinBox,
                  ui->healthSpinBox); */ // And something do with dependencies
    ui->sizeSpinBox->setValue(0);
    ui->attackSpinBox->setValue(0);
    ui->healthSpinBox->setValue(0);

    // add sound
    // add image
}
