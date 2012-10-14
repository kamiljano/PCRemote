#include "configdialog.h"
#include "ui_configdialog.h"

ConfigDialog::ConfigDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConfigDialog)
{
    ui->setupUi(this);
}

ConfigDialog::~ConfigDialog()
{
    delete ui;
}

void ConfigDialog::setValues()
{
    ui->checkAcceptAndroid->setChecked(Configuration::acceptAndroidClients());
    ui->checkWPAccept->setChecked(Configuration::acceptWPClients());
    ui->checkPasswd->setChecked(Configuration::requirePassword());
    ui->checkAutodetect->setChecked(Configuration::allowAutodetect());
    if (Configuration::requirePassword())
    {
        ui->tpass->setText(Configuration::getPassword());
    }
}

void ConfigDialog::setVisible(bool visible)
{
    QDialog::setVisible(visible);
    if (visible)
        setValues();
}

void ConfigDialog::on_checkPasswd_stateChanged(int arg1)
{
    if (arg1 == Qt::Checked)
        ui->tpass->setReadOnly(false);
    else
        ui->tpass->setReadOnly(false);
    cout<<"lol"<<endl;
}

void ConfigDialog::on_pushButton_clicked()
{
    this->setVisible(false);
}
