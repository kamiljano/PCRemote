#ifndef SLIDINGWINDOW_H
#define SLIDINGWINDOW_H

#include <QWidget>
#include <QPropertyAnimation>
#include <QLabel>
//#include "tray.h"

#include <Windows.h>
#include <Shellapi.h>

#define DEFAULT_WIDTH 200
#define DEFAULT_HEIGHT 100
#define MARGIN_X 45
#define MARGIN_Y 5
#define ANIMATION_DURATION 150

class SlidingWindow : public QWidget
{
    Q_OBJECT
    QPropertyAnimation *animation;
    void init();
protected:
    struct TaskbarData {enum Positions {RIGHT, TOP, LEFT, BOTTOM }; Positions position; int x1, x2, y1, y2;};
    TaskbarData getTaskbarData();
    //Tray * tray;
public:
    SlidingWindow(QWidget *parent = 0);
    virtual ~SlidingWindow();
    void setVisible(bool visible);
public slots:
    void Show();
    void Hide();
private slots:
    void killWindow();
    
};

#endif // SLIDINGWINDOW_H
