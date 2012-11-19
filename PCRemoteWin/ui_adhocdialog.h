/********************************************************************************
** Form generated from reading UI file 'adhocdialog.ui'
**
** Created: Sat Nov 17 23:51:55 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADHOCDIALOG_H
#define UI_ADHOCDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AdHocDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *ssid;
    QLabel *label_2;
    QLineEdit *passwd;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_2;
    QPushButton *pushButton;

    void setupUi(QDialog *AdHocDialog)
    {
        if (AdHocDialog->objectName().isEmpty())
            AdHocDialog->setObjectName(QString::fromUtf8("AdHocDialog"));
        AdHocDialog->resize(246, 135);
        verticalLayout = new QVBoxLayout(AdHocDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(AdHocDialog);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        ssid = new QLineEdit(AdHocDialog);
        ssid->setObjectName(QString::fromUtf8("ssid"));
        ssid->setMaxLength(50);

        verticalLayout->addWidget(ssid);

        label_2 = new QLabel(AdHocDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        passwd = new QLineEdit(AdHocDialog);
        passwd->setObjectName(QString::fromUtf8("passwd"));
        passwd->setMaxLength(30);
        passwd->setEchoMode(QLineEdit::Password);

        verticalLayout->addWidget(passwd);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_2 = new QPushButton(AdHocDialog);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);

        pushButton = new QPushButton(AdHocDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(AdHocDialog);

        QMetaObject::connectSlotsByName(AdHocDialog);
    } // setupUi

    void retranslateUi(QDialog *AdHocDialog)
    {
        AdHocDialog->setWindowTitle(QApplication::translate("AdHocDialog", "Ad hoc", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("AdHocDialog", "SSID", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("AdHocDialog", "Password", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("AdHocDialog", "Start", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("AdHocDialog", "Cancel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AdHocDialog: public Ui_AdHocDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADHOCDIALOG_H
