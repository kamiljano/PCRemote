#ifndef MEDIACONTROLLER_H
#define MEDIACONTROLLER_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>

#include <Windows.h>

#define ICON_WIDTH 30
#define ICON_HEIGHT 30

class MediaController : public QWidget
{
    Q_OBJECT
    QHBoxLayout * layout;
    QPushButton * prev, *play, *next;
protected:
    QLabel * image;
public:
    explicit MediaController(QWidget *parent = 0);
    virtual ~MediaController();
protected slots:
    virtual void Play();
    virtual void Next();
    virtual void Previous();
    virtual void LoadLogo();
};

#endif // MEDIACONTROLLER_H
