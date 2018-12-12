/********************************************************************************
** Form generated from reading UI file 'gamewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEWINDOW_H
#define UI_GAMEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_gameWindow
{
public:

    void setupUi(QDialog *gameWindow)
    {
        if (gameWindow->objectName().isEmpty())
            gameWindow->setObjectName(QStringLiteral("gameWindow"));
        gameWindow->resize(400, 300);

        retranslateUi(gameWindow);

        QMetaObject::connectSlotsByName(gameWindow);
    } // setupUi

    void retranslateUi(QDialog *gameWindow)
    {
        gameWindow->setWindowTitle(QApplication::translate("gameWindow", "Real Time Strategy", nullptr));
    } // retranslateUi

};

namespace Ui {
    class gameWindow: public Ui_gameWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEWINDOW_H
