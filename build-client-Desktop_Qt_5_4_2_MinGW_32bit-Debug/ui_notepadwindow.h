/********************************************************************************
** Form generated from reading UI file 'notepadwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOTEPADWINDOW_H
#define UI_NOTEPADWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "texteditor.h"

QT_BEGIN_NAMESPACE

class Ui_notepadWindow
{
public:
    QAction *save;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_5;
    QWidget *settings;
    QVBoxLayout *verticalLayout_4;
    QGroupBox *connectionBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *ip;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QSpinBox *port;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *login;
    QPushButton *connectDisConnect;
    QGroupBox *filesBox;
    QVBoxLayout *verticalLayout_2;
    QListWidget *files;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *createB;
    QPushButton *deleteB;
    QGroupBox *usersBox;
    QVBoxLayout *verticalLayout_3;
    QListWidget *users;
    textEditor *plainTextEdit;
    QMenuBar *menuBar;
    QMenu *menu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *notepadWindow)
    {
        if (notepadWindow->objectName().isEmpty())
            notepadWindow->setObjectName(QStringLiteral("notepadWindow"));
        notepadWindow->resize(778, 648);
        save = new QAction(notepadWindow);
        save->setObjectName(QStringLiteral("save"));
        centralWidget = new QWidget(notepadWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout_5 = new QHBoxLayout(centralWidget);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        settings = new QWidget(centralWidget);
        settings->setObjectName(QStringLiteral("settings"));
        settings->setMinimumSize(QSize(250, 0));
        settings->setMaximumSize(QSize(250, 16777215));
        verticalLayout_4 = new QVBoxLayout(settings);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setSizeConstraint(QLayout::SetMinimumSize);
        connectionBox = new QGroupBox(settings);
        connectionBox->setObjectName(QStringLiteral("connectionBox"));
        verticalLayout = new QVBoxLayout(connectionBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(connectionBox);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        ip = new QLineEdit(connectionBox);
        ip->setObjectName(QStringLiteral("ip"));

        horizontalLayout->addWidget(ip);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(connectionBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        port = new QSpinBox(connectionBox);
        port->setObjectName(QStringLiteral("port"));
        port->setMaximumSize(QSize(16777215, 16777210));
        port->setMaximum(2000);
        port->setValue(1234);

        horizontalLayout_2->addWidget(port);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(connectionBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        login = new QLineEdit(connectionBox);
        login->setObjectName(QStringLiteral("login"));

        horizontalLayout_3->addWidget(login);


        verticalLayout->addLayout(horizontalLayout_3);

        connectDisConnect = new QPushButton(connectionBox);
        connectDisConnect->setObjectName(QStringLiteral("connectDisConnect"));

        verticalLayout->addWidget(connectDisConnect);

        connectDisConnect->raise();

        verticalLayout_4->addWidget(connectionBox);

        filesBox = new QGroupBox(settings);
        filesBox->setObjectName(QStringLiteral("filesBox"));
        filesBox->setMinimumSize(QSize(0, 0));
        verticalLayout_2 = new QVBoxLayout(filesBox);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        files = new QListWidget(filesBox);
        files->setObjectName(QStringLiteral("files"));

        verticalLayout_2->addWidget(files);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        createB = new QPushButton(filesBox);
        createB->setObjectName(QStringLiteral("createB"));

        horizontalLayout_4->addWidget(createB);

        deleteB = new QPushButton(filesBox);
        deleteB->setObjectName(QStringLiteral("deleteB"));

        horizontalLayout_4->addWidget(deleteB);


        verticalLayout_2->addLayout(horizontalLayout_4);


        verticalLayout_4->addWidget(filesBox);

        usersBox = new QGroupBox(settings);
        usersBox->setObjectName(QStringLiteral("usersBox"));
        verticalLayout_3 = new QVBoxLayout(usersBox);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        users = new QListWidget(usersBox);
        users->setObjectName(QStringLiteral("users"));

        verticalLayout_3->addWidget(users);


        verticalLayout_4->addWidget(usersBox);


        horizontalLayout_5->addWidget(settings);

        plainTextEdit = new textEditor(centralWidget);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        plainTextEdit->setEnabled(false);
        plainTextEdit->setMinimumSize(QSize(250, 0));

        horizontalLayout_5->addWidget(plainTextEdit);

        notepadWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(notepadWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 778, 21));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        notepadWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(notepadWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        notepadWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(notepadWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        notepadWindow->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menu->addAction(save);

        retranslateUi(notepadWindow);

        QMetaObject::connectSlotsByName(notepadWindow);
    } // setupUi

    void retranslateUi(QMainWindow *notepadWindow)
    {
        notepadWindow->setWindowTitle(QApplication::translate("notepadWindow", "notepadWindow", 0));
        save->setText(QApplication::translate("notepadWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\272\320\260\320\272...", 0));
        connectionBox->setTitle(QApplication::translate("notepadWindow", "\320\237\320\276\320\264\320\272\320\273\321\216\321\207\320\265\320\275\320\270\320\265", 0));
        label->setText(QApplication::translate("notepadWindow", "IP", 0));
        ip->setInputMask(QString());
        ip->setText(QApplication::translate("notepadWindow", "127.0.0.1", 0));
        label_2->setText(QApplication::translate("notepadWindow", "\320\237\320\276\321\200\321\202", 0));
        label_3->setText(QApplication::translate("notepadWindow", "\320\233\320\276\320\263\320\270\320\275", 0));
        login->setText(QApplication::translate("notepadWindow", "User1", 0));
        connectDisConnect->setText(QApplication::translate("notepadWindow", "\320\237\320\276\320\264\320\272\320\273\321\216\321\207\320\270\321\202\321\214\321\201\321\217", 0));
        filesBox->setTitle(QApplication::translate("notepadWindow", "\320\244\320\260\320\271\320\273\321\213", 0));
        createB->setText(QApplication::translate("notepadWindow", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214...", 0));
        deleteB->setText(QApplication::translate("notepadWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", 0));
        usersBox->setTitle(QApplication::translate("notepadWindow", "\320\237\320\276\320\273\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\320\270", 0));
        menu->setTitle(QApplication::translate("notepadWindow", "\320\244\320\260\320\271\320\273", 0));
    } // retranslateUi

};

namespace Ui {
    class notepadWindow: public Ui_notepadWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOTEPADWINDOW_H
