/********************************************************************************
** Form generated from reading UI file 'dialoginsidegame.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGINSIDEGAME_H
#define UI_DIALOGINSIDEGAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_dialogInsideGame
{
public:
    QPushButton *backToGame;
    QPushButton *settingsButton;
    QPushButton *backToMenu;

    void setupUi(QDialog *dialogInsideGame)
    {
        if (dialogInsideGame->objectName().isEmpty())
            dialogInsideGame->setObjectName(QStringLiteral("dialogInsideGame"));
        dialogInsideGame->resize(200, 250);
        dialogInsideGame->setMinimumSize(QSize(200, 250));
        dialogInsideGame->setMaximumSize(QSize(200, 250));
        backToGame = new QPushButton(dialogInsideGame);
        backToGame->setObjectName(QStringLiteral("backToGame"));
        backToGame->setGeometry(QRect(50, 40, 101, 28));
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(9);
        backToGame->setFont(font);
        settingsButton = new QPushButton(dialogInsideGame);
        settingsButton->setObjectName(QStringLiteral("settingsButton"));
        settingsButton->setGeometry(QRect(50, 100, 101, 28));
        settingsButton->setFont(font);
        backToMenu = new QPushButton(dialogInsideGame);
        backToMenu->setObjectName(QStringLiteral("backToMenu"));
        backToMenu->setGeometry(QRect(50, 160, 101, 28));
        backToMenu->setFont(font);

        retranslateUi(dialogInsideGame);

        QMetaObject::connectSlotsByName(dialogInsideGame);
    } // setupUi

    void retranslateUi(QDialog *dialogInsideGame)
    {
        dialogInsideGame->setWindowTitle(QApplication::translate("dialogInsideGame", "Pause", nullptr));
        backToGame->setText(QApplication::translate("dialogInsideGame", "\320\222\320\265\321\200\320\275\321\203\321\202\321\214\321\201\321\217", nullptr));
        settingsButton->setText(QApplication::translate("dialogInsideGame", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270", nullptr));
        backToMenu->setText(QApplication::translate("dialogInsideGame", "\320\222\321\213\320\271\321\202\320\270 \320\262 \320\274\320\265\320\275\321\216", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dialogInsideGame: public Ui_dialogInsideGame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGINSIDEGAME_H
