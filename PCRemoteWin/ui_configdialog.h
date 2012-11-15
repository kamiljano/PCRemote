/********************************************************************************
** Form generated from reading UI file 'configdialog.ui'
**
** Created: Wed Nov 14 20:15:08 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIGDIALOG_H
#define UI_CONFIGDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTabWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ConfigDialog
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab_3;
    QVBoxLayout *verticalLayout_4;
    QCheckBox *checkAutodetect;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLineEdit *tname;
    QPushButton *pushButton_3;
    QLabel *label_3;
    QLineEdit *tport;
    QPushButton *pushButton_4;
    QWidget *tab_4;
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *checkAcceptAndroid;
    QCheckBox *checkWPAccept;
    QHBoxLayout *horizontalLayout_3;
    QCheckBox *checkPasswd;
    QLineEdit *tpass;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_2;
    QPushButton *pushButton;

    void setupUi(QDialog *ConfigDialog)
    {
        if (ConfigDialog->objectName().isEmpty())
            ConfigDialog->setObjectName(QString::fromUtf8("ConfigDialog"));
        ConfigDialog->resize(450, 178);
        verticalLayout = new QVBoxLayout(ConfigDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tabWidget = new QTabWidget(ConfigDialog);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        verticalLayout_4 = new QVBoxLayout(tab_3);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        checkAutodetect = new QCheckBox(tab_3);
        checkAutodetect->setObjectName(QString::fromUtf8("checkAutodetect"));

        verticalLayout_4->addWidget(checkAutodetect);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_2 = new QLabel(tab_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        tname = new QLineEdit(tab_3);
        tname->setObjectName(QString::fromUtf8("tname"));

        gridLayout->addWidget(tname, 0, 1, 1, 1);

        pushButton_3 = new QPushButton(tab_3);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        gridLayout->addWidget(pushButton_3, 0, 2, 1, 1);

        label_3 = new QLabel(tab_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        tport = new QLineEdit(tab_3);
        tport->setObjectName(QString::fromUtf8("tport"));

        gridLayout->addWidget(tport, 1, 1, 1, 1);

        pushButton_4 = new QPushButton(tab_3);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        gridLayout->addWidget(pushButton_4, 1, 2, 1, 1);


        verticalLayout_4->addLayout(gridLayout);

        tabWidget->addTab(tab_3, QString());
        checkAutodetect->raise();
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        verticalLayout_3 = new QVBoxLayout(tab_4);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label = new QLabel(tab_4);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_3->addWidget(label);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        checkAcceptAndroid = new QCheckBox(tab_4);
        checkAcceptAndroid->setObjectName(QString::fromUtf8("checkAcceptAndroid"));

        horizontalLayout_2->addWidget(checkAcceptAndroid);

        checkWPAccept = new QCheckBox(tab_4);
        checkWPAccept->setObjectName(QString::fromUtf8("checkWPAccept"));

        horizontalLayout_2->addWidget(checkWPAccept);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        checkPasswd = new QCheckBox(tab_4);
        checkPasswd->setObjectName(QString::fromUtf8("checkPasswd"));

        horizontalLayout_3->addWidget(checkPasswd);

        tpass = new QLineEdit(tab_4);
        tpass->setObjectName(QString::fromUtf8("tpass"));
        tpass->setMaxLength(30);
        tpass->setEchoMode(QLineEdit::Password);

        horizontalLayout_3->addWidget(tpass);


        verticalLayout_3->addLayout(horizontalLayout_3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        tabWidget->addTab(tab_4, QString());

        verticalLayout->addWidget(tabWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_2 = new QPushButton(ConfigDialog);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);

        pushButton = new QPushButton(ConfigDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(ConfigDialog);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ConfigDialog);
    } // setupUi

    void retranslateUi(QDialog *ConfigDialog)
    {
        ConfigDialog->setWindowTitle(QApplication::translate("ConfigDialog", "Options", 0, QApplication::UnicodeUTF8));
        checkAutodetect->setText(QApplication::translate("ConfigDialog", "Allow clients to autodetect", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ConfigDialog", "Name", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("ConfigDialog", "Default", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("ConfigDialog", "Port", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("ConfigDialog", "Default", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("ConfigDialog", "Netork", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ConfigDialog", "Accept clients:", 0, QApplication::UnicodeUTF8));
        checkAcceptAndroid->setText(QApplication::translate("ConfigDialog", "Android", 0, QApplication::UnicodeUTF8));
        checkWPAccept->setText(QApplication::translate("ConfigDialog", "WindowsPhone", 0, QApplication::UnicodeUTF8));
        checkPasswd->setText(QApplication::translate("ConfigDialog", "Restrict access with password", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("ConfigDialog", "Clients", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("ConfigDialog", "OK", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("ConfigDialog", "Cancel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ConfigDialog: public Ui_ConfigDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIGDIALOG_H
