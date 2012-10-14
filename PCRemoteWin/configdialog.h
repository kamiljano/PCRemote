#ifndef CONFIGDIALOG_H
#define CONFIGDIALOG_H

#include <QDialog>
#include "configuration.h"
#include <iostream>
using namespace std;
namespace Ui {
class ConfigDialog;
}

class ConfigDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit ConfigDialog(QWidget *parent = 0);
    ~ConfigDialog();
    void setVisible(bool visible);
    

private slots:
    void on_checkPasswd_stateChanged(int arg1);

    void on_pushButton_clicked();

private:
    void setValues();
    Ui::ConfigDialog *ui;
};

#endif // CONFIGDIALOG_H
