/********************************************************************************
** Form generated from reading UI file 'videogame.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIDEOGAME_H
#define UI_VIDEOGAME_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_videogameClass
{
public:
    QAction *create;
    QAction *open;
    QAction *save;
    QAction *saveas;
    QWidget *centralWidget;
    QListWidget *List;
    QGroupBox *gbgame;
    QGroupBox *gpplatform;
    QRadioButton *rbtnX1;
    QRadioButton *rbtnPS4;
    QRadioButton *rbtnPC;
    QGroupBox *gpspecs;
    QCheckBox *flagmp;
    QCheckBox *flagcrossplatform;
    QCheckBox *flagsplit;
    QLabel *label_specs;
    QTextEdit *otherspecs;
    QCheckBox *flagavailability;
    QLabel *label;
    QLineEdit *title;
    QLabel *label_7;
    QSpinBox *price;
    QPushButton *remove;
    QPushButton *add;
    QMenuBar *menuBar;
    QMenu *menu;
    QToolBar *mainToolBar;
    QToolBar *toolBar;
    QToolBar *toolBar_2;

    void setupUi(QMainWindow *videogameClass)
    {
        if (videogameClass->objectName().isEmpty())
            videogameClass->setObjectName(QString::fromUtf8("videogameClass"));
        videogameClass->resize(636, 602);
        videogameClass->setMinimumSize(QSize(636, 602));
        videogameClass->setMaximumSize(QSize(636, 602));
        create = new QAction(videogameClass);
        create->setObjectName(QString::fromUtf8("create"));
        open = new QAction(videogameClass);
        open->setObjectName(QString::fromUtf8("open"));
        save = new QAction(videogameClass);
        save->setObjectName(QString::fromUtf8("save"));
        saveas = new QAction(videogameClass);
        saveas->setObjectName(QString::fromUtf8("saveas"));
        centralWidget = new QWidget(videogameClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        List = new QListWidget(centralWidget);
        List->setObjectName(QString::fromUtf8("List"));
        List->setGeometry(QRect(9, 9, 311, 541));
        gbgame = new QGroupBox(centralWidget);
        gbgame->setObjectName(QString::fromUtf8("gbgame"));
        gbgame->setGeometry(QRect(330, 10, 296, 501));
        gpplatform = new QGroupBox(gbgame);
        gpplatform->setObjectName(QString::fromUtf8("gpplatform"));
        gpplatform->setGeometry(QRect(10, 72, 281, 91));
        rbtnX1 = new QRadioButton(gpplatform);
        rbtnX1->setObjectName(QString::fromUtf8("rbtnX1"));
        rbtnX1->setGeometry(QRect(10, 20, 35, 17));
        rbtnPS4 = new QRadioButton(gpplatform);
        rbtnPS4->setObjectName(QString::fromUtf8("rbtnPS4"));
        rbtnPS4->setGeometry(QRect(10, 40, 41, 17));
        rbtnPC = new QRadioButton(gpplatform);
        rbtnPC->setObjectName(QString::fromUtf8("rbtnPC"));
        rbtnPC->setGeometry(QRect(10, 60, 36, 17));
        gpspecs = new QGroupBox(gbgame);
        gpspecs->setObjectName(QString::fromUtf8("gpspecs"));
        gpspecs->setGeometry(QRect(10, 176, 281, 221));
        flagmp = new QCheckBox(gpspecs);
        flagmp->setObjectName(QString::fromUtf8("flagmp"));
        flagmp->setGeometry(QRect(10, 30, 161, 17));
        flagcrossplatform = new QCheckBox(gpspecs);
        flagcrossplatform->setObjectName(QString::fromUtf8("flagcrossplatform"));
        flagcrossplatform->setGeometry(QRect(10, 50, 171, 17));
        flagsplit = new QCheckBox(gpspecs);
        flagsplit->setObjectName(QString::fromUtf8("flagsplit"));
        flagsplit->setGeometry(QRect(10, 70, 181, 17));
        label_specs = new QLabel(gpspecs);
        label_specs->setObjectName(QString::fromUtf8("label_specs"));
        label_specs->setGeometry(QRect(10, 100, 106, 16));
        otherspecs = new QTextEdit(gpspecs);
        otherspecs->setObjectName(QString::fromUtf8("otherspecs"));
        otherspecs->setGeometry(QRect(10, 120, 261, 91));
        flagavailability = new QCheckBox(gbgame);
        flagavailability->setObjectName(QString::fromUtf8("flagavailability"));
        flagavailability->setGeometry(QRect(10, 410, 119, 17));
        label = new QLabel(gbgame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(11, 24, 48, 16));
        title = new QLineEdit(gbgame);
        title->setObjectName(QString::fromUtf8("title"));
        title->setGeometry(QRect(12, 44, 133, 20));
        title->setLocale(QLocale(QLocale::Russian, QLocale::Russia));
        title->setMaxLength(30);
        label_7 = new QLabel(gbgame);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(11, 440, 26, 16));
        price = new QSpinBox(gbgame);
        price->setObjectName(QString::fromUtf8("price"));
        price->setGeometry(QRect(12, 460, 271, 20));
        remove = new QPushButton(centralWidget);
        remove->setObjectName(QString::fromUtf8("remove"));
        remove->setGeometry(QRect(500, 520, 121, 31));
        add = new QPushButton(centralWidget);
        add->setObjectName(QString::fromUtf8("add"));
        add->setGeometry(QRect(330, 520, 121, 31));
        videogameClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(videogameClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 636, 21));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        videogameClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(videogameClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        videogameClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        toolBar = new QToolBar(videogameClass);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        videogameClass->addToolBar(Qt::TopToolBarArea, toolBar);
        toolBar_2 = new QToolBar(videogameClass);
        toolBar_2->setObjectName(QString::fromUtf8("toolBar_2"));
        videogameClass->addToolBar(Qt::TopToolBarArea, toolBar_2);

        menuBar->addAction(menu->menuAction());
        menu->addAction(create);
        menu->addAction(open);
        menu->addAction(save);
        menu->addAction(saveas);

        retranslateUi(videogameClass);

        QMetaObject::connectSlotsByName(videogameClass);
    } // setupUi

    void retranslateUi(QMainWindow *videogameClass)
    {
        videogameClass->setWindowTitle(QApplication::translate("videogameClass", "\320\222\320\270\320\264\320\265\320\276\320\270\320\263\321\200\321\213", nullptr));
        create->setText(QApplication::translate("videogameClass", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214", nullptr));
        open->setText(QApplication::translate("videogameClass", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214...", nullptr));
        save->setText(QApplication::translate("videogameClass", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        saveas->setText(QApplication::translate("videogameClass", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\272\320\260\320\272...", nullptr));
        gbgame->setTitle(QApplication::translate("videogameClass", "\320\230\320\263\321\200\320\260", nullptr));
        gpplatform->setTitle(QApplication::translate("videogameClass", "\320\237\320\273\320\260\321\202\321\204\320\276\321\200\320\274\320\260", nullptr));
        rbtnX1->setText(QApplication::translate("videogameClass", "X1", nullptr));
        rbtnPS4->setText(QApplication::translate("videogameClass", "PS4", nullptr));
        rbtnPC->setText(QApplication::translate("videogameClass", "PC", nullptr));
        gpspecs->setTitle(QApplication::translate("videogameClass", "\320\245\320\260\321\200\320\260\320\272\321\202\320\265\321\200\320\270\321\201\321\202\320\270\320\272\320\270", nullptr));
        flagmp->setText(QApplication::translate("videogameClass", "\320\234\321\203\320\273\321\214\321\202\320\270\320\277\320\273\320\265\320\265\321\200", nullptr));
        flagcrossplatform->setText(QApplication::translate("videogameClass", "\320\232\321\200\320\276\321\201\321\201\320\277\320\273\320\260\321\202\321\204\320\276\321\200\320\274\320\260", nullptr));
        flagsplit->setText(QApplication::translate("videogameClass", "\320\241\320\277\320\273\320\270\321\202-\321\201\320\272\321\200\320\270\320\275", nullptr));
        label_specs->setText(QApplication::translate("videogameClass", "\320\237\320\276\320\264\321\200\320\276\320\261\320\275\320\276\320\265 \320\276\320\277\320\270\321\201\320\260\320\275\320\270\320\265", nullptr));
        flagavailability->setText(QApplication::translate("videogameClass", "\320\230\320\274\320\265\320\265\321\202\321\201\321\217 \320\262 \320\275\320\260\320\273\320\270\321\207\320\270\320\270", nullptr));
        label->setText(QApplication::translate("videogameClass", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265", nullptr));
        label_7->setText(QApplication::translate("videogameClass", "\320\246\320\265\320\275\320\260", nullptr));
        remove->setText(QApplication::translate("videogameClass", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        add->setText(QApplication::translate("videogameClass", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214", nullptr));
        menu->setTitle(QApplication::translate("videogameClass", "\320\244\320\260\320\271\320\273", nullptr));
        toolBar->setWindowTitle(QApplication::translate("videogameClass", "toolBar", nullptr));
        toolBar_2->setWindowTitle(QApplication::translate("videogameClass", "toolBar_2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class videogameClass: public Ui_videogameClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIDEOGAME_H
