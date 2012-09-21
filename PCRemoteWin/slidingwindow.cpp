#include "slidingwindow.h"

SlidingWindow::SlidingWindow(QWidget *parent) :
    QWidget(parent,Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowStaysOnTopHint | Qt::Tool)
{
    init();
}

void SlidingWindow::init()
{
    //tray = new Tray(this);
    this->resize(DEFAULT_WIDTH, DEFAULT_HEIGHT);
    animation = new QPropertyAnimation(this, "geometry", this);
    animation->setDuration(ANIMATION_DURATION);
    animation->setStartValue(QRect(0,0,10,10));
    animation->setEndValue(QRect(50,50,200,100));
}

SlidingWindow::~SlidingWindow()
{
    delete animation;
    //delete tray;
}

SlidingWindow::TaskbarData SlidingWindow::getTaskbarData()
{
    HWND hwnd =  FindWindowA("Shell_TrayWnd", NULL );
    APPBARDATA barData;
    barData.cbSize           =  sizeof(APPBARDATA);
    barData.hWnd             =  hwnd;
    SHAppBarMessage( ABM_GETTASKBARPOS, &barData );
    TaskbarData td;
    if (barData.rc.left == 0)//albo na górze, albo po lewej, albo na dole
    {
        if (barData.rc.right > barData.rc.bottom)
        {
            if (barData.rc.top == 0)
                td.position = TaskbarData::TOP;
            else
                td.position = TaskbarData::BOTTOM;
        }
        else
            td.position = TaskbarData::LEFT;
    }
    else
        td.position = TaskbarData::RIGHT;
    td.x1 = barData.rc.left;
    td.y1 = barData.rc.top;
    td.x2 = barData.rc.right;
    td.y2 = barData.rc.bottom;
    return td;
}

void SlidingWindow::Show()
{
    QWidget::setVisible(true);
    TaskbarData td = getTaskbarData();
    switch (td.position)
    {
    case TaskbarData::TOP:
        animation->setStartValue(QRect(td.x2 - this->width() - MARGIN_X, 0 - this->height(),this->width(),this->height()));
        animation->setEndValue(QRect(td.x2 - this->width() - MARGIN_X,MARGIN_Y + td.y2,this->width(),this->height()));
        //animation->setStartValue(QRect(td.x2, MARGIN_Y + td.y2,this->width(),MARGIN_Y + td.y2 + this->height()));
        //animation->setEndValue(QRect(td.x2 - this->width() - MARGIN_X, MARGIN_Y + td.y2,td.x2 - MARGIN_X,MARGIN_Y + td.y2 + this->height()));
        break;
    case TaskbarData::BOTTOM:
        animation->setStartValue(QRect(td.x2 - this->width() - MARGIN_X, td.y2, this->width(), this->height()));
        animation->setEndValue(QRect(td.x2 - this->width() - MARGIN_X, td.y2 - this->height() - MARGIN_Y - (td.y2 - td.y1), this->width(), this->height()));
        break;
    case TaskbarData::LEFT:
        animation->setStartValue(QRect(0 - this->width(), td.y2 - this->height() - MARGIN_Y,this->width(), this->height()));
        animation->setEndValue(QRect(td.x2 + MARGIN_X, td.y2 - this->height() - MARGIN_Y,this->width(), this->height()));
        break;
    case TaskbarData::RIGHT:
        animation->setStartValue(QRect(td.x2,td.y2 - this->height() - MARGIN_Y,this->width(),this->height()));
        animation->setEndValue(QRect(td.x1 - MARGIN_X - this->width(),td.y2 - this->height() - MARGIN_Y,this->width(),this->height()));
        break;
    }
    animation->start();
}

void SlidingWindow::Hide()
{
    connect(animation, SIGNAL(finished()), this, SLOT(killWindow()));
    TaskbarData td = getTaskbarData();
    switch (td.position)
    {
    case TaskbarData::TOP:
        animation->setEndValue(QRect(td.x2 - this->width() - MARGIN_X, 0 - this->height(),this->width(),this->height()));
        animation->setStartValue(QRect(td.x2 - this->width() - MARGIN_X,MARGIN_Y + td.y2,this->width(),this->height()));
        break;
    case TaskbarData::BOTTOM:
        animation->setEndValue(QRect(td.x2 - this->width() - MARGIN_X, td.y2, this->width(), this->height()));
        animation->setStartValue(QRect(td.x2 - this->width() - MARGIN_X, td.y2 - this->height() - MARGIN_Y - (td.y2 - td.y1), this->width(), this->height()));
        break;
    case TaskbarData::LEFT:
        animation->setEndValue(QRect(0 - this->width(), td.y2 - this->height() - MARGIN_Y,this->width(), this->height()));
        animation->setStartValue(QRect(td.x2 + MARGIN_X, td.y2 - this->height() - MARGIN_Y,this->width(), this->height()));
        break;
    case TaskbarData::RIGHT:
        animation->setEndValue(QRect(td.x2,td.y2 - this->height() - MARGIN_Y,this->width(),this->height()));
        animation->setStartValue(QRect(td.x1 - MARGIN_X - this->width(),td.y2 - this->height() - MARGIN_Y,this->width(),this->height()));
        break;
    }

    animation->start();

}

void SlidingWindow::killWindow()
{
    QWidget::setVisible(false);
    disconnect(animation, SIGNAL(finished()), this, SLOT(killWindow()));
}

void SlidingWindow::setVisible(bool visible)
{
    if (visible)
        Show();
    else
        Hide();
}
