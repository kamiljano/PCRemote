#include "mediacontroller.h"

MediaController::MediaController(QWidget *parent) :
    QWidget(parent)
{
    layout = new QHBoxLayout();
    image = new QLabel();
    prev = new QPushButton("<<");
    play = new QPushButton("Play/Pause");
    next = new QPushButton(">>");

    LoadLogo();

    connect(prev, SIGNAL(clicked()), this, SLOT(Previous()));
    connect(play, SIGNAL(clicked()), this, SLOT(Play()));
    connect(next, SIGNAL(clicked()), this, SLOT(Next()));

    layout->addWidget(image);
    layout->addWidget(prev);
    layout->addWidget(play);
    layout->addWidget(next);
    this->setLayout(layout);
}

MediaController::~MediaController()
{
    delete layout;
    delete image;
    delete prev;
    delete play;
    delete next;
}

void MediaController::Previous()
{
    keybd_event(0xB1, 0,0,0);
    keybd_event(0xB1, 0,KEYEVENTF_KEYUP,0);
}

void MediaController::Play()
{
    keybd_event(0xB3, 0,0,0);
    keybd_event(0xB3, 0,KEYEVENTF_KEYUP,0);
}

void MediaController::Next()
{
    keybd_event(0xB0, 0,0,0);
    keybd_event(0xB0, 0,KEYEVENTF_KEYUP,0);
}

void MediaController::LoadLogo()
{
    QPixmap p(":resources/play.png");
    image->setPixmap(p.scaled(ICON_WIDTH,ICON_HEIGHT));
}
