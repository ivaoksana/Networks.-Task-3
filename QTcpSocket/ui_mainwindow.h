/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QTextBrowser *textinfo;
    QLineEdit *ServerPort_LE;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *ConectToServer;
    QPushButton *OpenTheFile;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer;
    QLabel *label;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(425, 256);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        textinfo = new QTextBrowser(centralWidget);
        textinfo->setObjectName(QString::fromUtf8("textinfo"));

        gridLayout->addWidget(textinfo, 0, 0, 1, 8);

        ServerPort_LE = new QLineEdit(centralWidget);
        ServerPort_LE->setObjectName(QString::fromUtf8("ServerPort_LE"));

        gridLayout->addWidget(ServerPort_LE, 3, 3, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 3, 4, 1, 1);

        ConectToServer = new QPushButton(centralWidget);
        ConectToServer->setObjectName(QString::fromUtf8("ConectToServer"));

        gridLayout->addWidget(ConectToServer, 3, 1, 1, 1);

        OpenTheFile = new QPushButton(centralWidget);
        OpenTheFile->setObjectName(QString::fromUtf8("OpenTheFile"));

        gridLayout->addWidget(OpenTheFile, 3, 5, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 3, 0, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 3, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 3, 6, 1, 1);

        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 2, 3, 1, 1);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
#if QT_CONFIG(whatsthis)
        ServerPort_LE->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Write there a server port</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        ServerPort_LE->setText(QCoreApplication::translate("MainWindow", "33333", nullptr));
        ConectToServer->setText(QCoreApplication::translate("MainWindow", "Conect to server", nullptr));
        OpenTheFile->setText(QCoreApplication::translate("MainWindow", "Open the file", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Server Port", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
