#include "editor.h"
#include "ui_editor.h"
#include "buildingeditor.h"
#include "uniteditor.h"

Editor::Editor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Editor)
{
    ui->setupUi(this);
    showFullScreen();
}

Editor::~Editor()
{
    delete ui;
}


void Editor::on_pushButton_clicked()
{
    unitEditor editor;
    editor.setModal(true);
    //hide();
    editor.exec();
    showFullScreen();
}

void Editor::on_pushButton_2_clicked()
{
    buildingEditor editor;
    editor.setModal(true);
    editor.exec();
    showFullScreen();
}

void Editor::on_pushButton_3_clicked()
{
    close();
}
