#include "aboutdialog.h"
#include "ui_aboutdialog.h"

AboutDialog::AboutDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutDialog)
{
    ui->setupUi(this);
    ui->image->setPixmap(QPixmap(":resources/me.JPG"));
    ui->image->setScaledContents(true);
    ui->text->setText(tr("This piece of software is totally awesome, isn't it? :D\n"
                         "OK, maybe it's not that perfect but still...\n"
                         "Developed by Kamil Janowski"
                         "All right reserved   2012"));
}

AboutDialog::~AboutDialog()
{
    delete ui;
}

void AboutDialog::on_pushButton_clicked()
{
    this->setVisible(false);
}
