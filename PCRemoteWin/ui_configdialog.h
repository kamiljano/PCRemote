/********************************************************************************
** Form generated from reading UI file 'configdialog.ui'
**
** Created: Sun Oct 14 15:59:19 2012
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
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ConfigDialog
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *checkAcceptAndroid;
    QCheckBox *checkWPAccept;
    QHBoxLayout *horizontalLayout_3;
    QCheckBox *checkPasswd;
    QLineEdit *tpass;
    QCheckBox *checkAutodetect;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_2;
    QPushButton *pushButton;

    void setupUi(QDialog *ConfigDialog)
    {
        if (ConfigDialog->objectName().isEmpty())
            ConfigDialog->setObjectName(QString::fromUtf8("ConfigDialog"));
        ConfigDialog->resize(363, 177);
        verticalLayout = new QVBoxLayout(ConfigDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox = new QGroupBox(ConfigDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_2->addWidget(label);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        checkAcceptAndroid = new QCheckBox(groupBox);
        checkAcceptAndroid->setObjectName(QString::fromUtf8("checkAcceptAndroid"));

        horizontalLayout_2->addWidget(checkAcceptAndroid);

        checkWPAccept = new QCheckBox(groupBox);
        checkWPAccept->setObjectName(QString::fromUtf8("checkWPAccept"));

        horizontalLayout_2->addWidget(checkWPAccept);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        checkPasswd = new QCheckBox(groupBox);
        checkPasswd->setObjectName(QString::fromUtf8("checkPasswd"));

        horizontalLayout_3->addWidget(checkPasswd);

        tpass = new QLineEdit(groupBox);
        tpass->setObjectName(QString::fromUtf8("tpass"));
        tpass->setMaxLength(30);
        tpass->setEchoMode(QLineEdit::Password);

        horizontalLayout_3->addWidget(tpass);


        verticalLayout_2->addLayout(horizontalLayout_3);

        checkAutodetect = new QCheckBox(groupBox);
        checkAutodetect->setObjectName(QString::fromUtf8("checkAutodetect"));

        verticalLayout_2->addWidget(checkAutodetect);


        verticalLayout->addWidget(groupBox);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton_2 = new QPushButton(ConfigDialog);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);

        pushButton = new QPushButton(ConfigDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(ConfigDialog);

        QMetaObject::connectSlotsByName(ConfigDialog);
    } // setupUi

    void retranslateUi(QDialog *ConfigDialog)
    {
        ConfigDialog->setWindowTitle(QApplication::translate("ConfigDialog", "Options", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("ConfigDialog", "Clients", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ConfigDialog", "Accept clients:", 0, QApplication::UnicodeUTF8));
        checkAcceptAndroid->setText(QApplication::translate("ConfigDialog", "Android", 0, QApplication::UnicodeUTF8));
        checkWPAccept->setText(QApplication::translate("ConfigDialog", "WindowsPhone", 0, QApplication::UnicodeUTF8));
        checkPasswd->setText(QApplication::translate("ConfigDialog", "Restrict access with password", 0, QApplication::UnicodeUTF8));
        checkAutodetect->setText(QApplication::translate("ConfigDialog", "Allow clients to autodetect", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("ConfigDialog", "OK", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("ConfigDialog", "Cancel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ConfigDialog: public Ui_ConfigDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIGDIALOG_H
