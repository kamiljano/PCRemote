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
    ui->tname->setText(Configuration::getServerName());
    ui->tport->setText(QString::number(Configuration::getPort()));

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

void ConfigDialog::on_pushButton_3_clicked()
{
    ui->tname->setText(Configuration::getComputerName());
}

void ConfigDialog::on_pushButton_4_clicked()
{
    ui->tport->setText(QString::number(Configuration::getDefaultPort()));
}

void ConfigDialog::on_pushButton_2_clicked()
{
    Configuration::setAcceptAndroidClients(ui->checkAcceptAndroid->checkState());
    Configuration::setAcceptWPClients(ui->checkWPAccept->checkState());
    Configuration::setRequirePassword(ui->checkPasswd->checkState());
    Configuration::setPassword(ui->tpass->text());
    Configuration::save();
    this->setVisible(false);
}
