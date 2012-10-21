#include "adhocdialog.h"
#include "ui_adhocdialog.h"

AdHocDialog::AdHocDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdHocDialog)
{
    ui->setupUi(this);
}

AdHocDialog::~AdHocDialog()
{
    delete ui;
}

void AdHocDialog::on_pushButton_clicked()
{
    this->setVisible(false);
}

void AdHocDialog::on_pushButton_2_clicked()
{
    if (isFilled())
    {
        QString params = ui->ssid->text() + " " + ui->passwd->text();
        wchar_t temp[82];
        params.toWCharArray(temp);
        ShellExecute( NULL, L"runas",L"AdHoc.exe",temp,NULL,SW_SHOW);
        this->setVisible(false);
    }
}

bool AdHocDialog::isFilled()
{
    bool ret = true;
    QString mes;
    if (ui->ssid->text().length() == 0)
    {
        ret = false;
        mes = "- No network identifier (SSID) entered\n";
    }
    if (ui->passwd->text().length() == 0)
    {
        ret = false;
        mes += "- No password for network entered";
    }
    if (!ret)
        QMessageBox::information(this, "Unfilled values", "In order to proceed, fix following problems:\n" + mes, QMessageBox::Ok);
    return ret;
}

void AdHocDialog::CloseAdHoc()
{
    ShellExecute( NULL, L"runas",L"AdHoc.exe",L"close",NULL,SW_SHOW);
}
