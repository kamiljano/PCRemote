#ifndef ABOUTWINDOW_H
#define ABOUTWINDOW_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

class AboutWindow : public QWidget
{
    Q_OBJECT
    QPushButton *bClose;
    QVBoxLayout *layout;
    QLabel *image, *label;
public:
    explicit AboutWindow(QWidget *parent = 0) : QWidget (parent)
    {
        layout = new QVBoxLayout();
        bClose = new QPushButton(tr("Close"));
        image = new QLabel();
        label = new QLabel();

        image->setPixmap(":resources/me.JPG");
        label->setText("asdfsfsadf");

        layout->addWidget(image,1, Qt::AlignHCenter);
        layout->addWidget(label,0, Qt::AlignHCenter);
        layout->addWidget(bClose,0, Qt::AlignHCenter);
        this->setLayout(layout);
    }

    ~AboutWindow()
    {
        delete layout;
        delete bClose;
        delete image;
        delete label;
    }

#endif // ABOUTWINDOW_H
