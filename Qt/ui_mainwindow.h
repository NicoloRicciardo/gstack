/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNuovo;
    QAction *actionApri;
    QAction *actionSalva;
    QAction *actionSalva_con_nome;
    QAction *actionEsci;
    QAction *actionFont;
    QAction *actionGrassetto;
    QAction *actionCorsivo;
    QAction *actionSottolineato;
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QTextEdit *textEditBox;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuModifica;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 500);
        MainWindow->setMinimumSize(QSize(800, 500));
        actionNuovo = new QAction(MainWindow);
        actionNuovo->setObjectName(QString::fromUtf8("actionNuovo"));
        actionApri = new QAction(MainWindow);
        actionApri->setObjectName(QString::fromUtf8("actionApri"));
        actionSalva = new QAction(MainWindow);
        actionSalva->setObjectName(QString::fromUtf8("actionSalva"));
        actionSalva_con_nome = new QAction(MainWindow);
        actionSalva_con_nome->setObjectName(QString::fromUtf8("actionSalva_con_nome"));
        actionEsci = new QAction(MainWindow);
        actionEsci->setObjectName(QString::fromUtf8("actionEsci"));
        actionFont = new QAction(MainWindow);
        actionFont->setObjectName(QString::fromUtf8("actionFont"));
        actionGrassetto = new QAction(MainWindow);
        actionGrassetto->setObjectName(QString::fromUtf8("actionGrassetto"));
        actionCorsivo = new QAction(MainWindow);
        actionCorsivo->setObjectName(QString::fromUtf8("actionCorsivo"));
        actionSottolineato = new QAction(MainWindow);
        actionSottolineato->setObjectName(QString::fromUtf8("actionSottolineato"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(9, 39, 781, 371));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        textEditBox = new QTextEdit(verticalLayoutWidget);
        textEditBox->setObjectName(QString::fromUtf8("textEditBox"));
        QFont font;
        font.setPointSize(11);
        textEditBox->setFont(font);

        verticalLayout->addWidget(textEditBox);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 20));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuModifica = new QMenu(menubar);
        menuModifica->setObjectName(QString::fromUtf8("menuModifica"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuModifica->menuAction());
        menuFile->addAction(actionNuovo);
        menuFile->addAction(actionApri);
        menuFile->addAction(actionSalva);
        menuFile->addAction(actionSalva_con_nome);
        menuFile->addSeparator();
        menuFile->addAction(actionEsci);
        menuModifica->addAction(actionFont);
        menuModifica->addAction(actionGrassetto);
        menuModifica->addAction(actionCorsivo);
        menuModifica->addAction(actionSottolineato);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionNuovo->setText(QCoreApplication::translate("MainWindow", "Nuovo", nullptr));
        actionApri->setText(QCoreApplication::translate("MainWindow", "Apri", nullptr));
        actionSalva->setText(QCoreApplication::translate("MainWindow", "Salva", nullptr));
        actionSalva_con_nome->setText(QCoreApplication::translate("MainWindow", "Salva con nome", nullptr));
        actionEsci->setText(QCoreApplication::translate("MainWindow", "Esci", nullptr));
        actionFont->setText(QCoreApplication::translate("MainWindow", "Font", nullptr));
        actionGrassetto->setText(QCoreApplication::translate("MainWindow", "Grassetto", nullptr));
        actionCorsivo->setText(QCoreApplication::translate("MainWindow", "Corsivo", nullptr));
        actionSottolineato->setText(QCoreApplication::translate("MainWindow", "Sottolineato", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuModifica->setTitle(QCoreApplication::translate("MainWindow", "Modifica", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
