#ifndef ADHOCDIALOG_H
#define ADHOCDIALOG_H

#include <Windows.h>

#include <iostream>
#include <QDialog>
#include <QMessageBox>

using namespace std;

namespace Ui {
class AdHocDialog;
}

class AdHocDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit AdHocDialog(QWidget *parent = 0);
    ~AdHocDialog();

    void CloseAdHoc();
    
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::AdHocDialog *ui;
    bool isFilled();
};

#endif // ADHOCDIALOG_H
