/********************************************************************************
** Form generated from reading UI file'main.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAIN_H
#define UI_MAIN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Main
{
public:
    QAction *actionAbout;
    QAction *actionPreferences;
    QAction *actionOpen;
    QAction *actionExport_PRODDATA_DAT;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuHelp;
    QMenu *menuEdit;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Main)
    {
        if (Main->objectName().isEmpty())
            Main->setObjectName("Main");
        Main->resize(600, 340);
        actionAbout = new QAction(Main);
        actionAbout->setObjectName("actionAbout");
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::HelpAbout));
        actionAbout->setIcon(icon);
        actionPreferences = new QAction(Main);
        actionPreferences->setObjectName("actionPreferences");
        actionOpen = new QAction(Main);
        actionOpen->setObjectName("actionOpen");
        actionExport_PRODDATA_DAT = new QAction(Main);
        actionExport_PRODDATA_DAT->setObjectName("actionExport_PRODDATA_DAT");
        centralwidget = new QWidget(Main);
        centralwidget->setObjectName("centralwidget");
        Main->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Main);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 600, 21));
        menubar->setDefaultUp(false);
        menuFile = new QMenu(menubar);
        menuFile->setObjectName("menuFile");
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName("menuHelp");
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName("menuEdit");
        Main->setMenuBar(menubar);
        statusbar = new QStatusBar(Main);
        statusbar->setObjectName("statusbar");
        Main->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addSeparator();
        menuFile->addAction(actionExport_PRODDATA_DAT);
        menuHelp->addAction(actionAbout);
        menuEdit->addAction(actionPreferences);

        retranslateUi(Main);

        QMetaObject::connectSlotsByName(Main);
    } // setupUi

    void retranslateUi(QMainWindow *Main)
    {
        Main->setWindowTitle(QCoreApplication::translate("Main", "Nitrous", nullptr));
        actionAbout->setText(QCoreApplication::translate("Main", "About", nullptr));
        actionPreferences->setText(QCoreApplication::translate("Main", "Preferences...", nullptr));
        actionOpen->setText(QCoreApplication::translate("Main", "Open", nullptr));
        actionExport_PRODDATA_DAT->setText(QCoreApplication::translate("Main", "Export PRODDATA.DAT", nullptr));
        menuFile->setTitle(QCoreApplication::translate("Main", "File", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("Main", "Help", nullptr));
        menuEdit->setTitle(QCoreApplication::translate("Main", "Edit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Main: public Ui_Main {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_H