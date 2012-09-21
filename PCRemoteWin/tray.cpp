#include "tray.h"

Tray::Tray(QWidget *parent) :
    QObject(parent)
{
    QIcon i("icon.svg");
    icon = new QSystemTrayIcon((QObject*)parent);
    icon->setIcon(i);
    trayMenu = new QMenu();
    trayMenu->addAction(tr("Options"), this, SLOT(optionsClicked()));
    trayMenu->addAction(tr("Server info"), this, SLOT(getInfoClicked()));
    trayMenu->addAction(tr("Exit"), this, SLOT(exitClicked()));
    icon->setContextMenu(trayMenu);
    //config = new ConfigWindow;
    connect(icon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this, SLOT(activate(QSystemTrayIcon::ActivationReason)));

    communicator = new TcpCommunicator;
    communicator->Listen();
}

Tray::~Tray()
{
    delete trayMenu;
    delete icon;
    delete communicator;
    //delete config;
}

void Tray::Show()
{
    icon->show();
}

void Tray::Hide()
{
    icon->hide();
}

void Tray::activate(QSystemTrayIcon::ActivationReason reason)
{
    QWidget * window = (QWidget*)this->parent();
    if (reason == QSystemTrayIcon::Trigger)
    {
        if (window->isVisible())
            window->setVisible(false);
        else
        {
            /*QPoint p = QCursor::pos();
            QRect available = QApplication::desktop()->availableGeometry(p);
            QRect all = QApplication::desktop()->screenGeometry(p);
            ScreenSize = all;
            int barHeight = all.height() - available.height();
            if (p.x()>available.width() / 2)
            {
                if (p.y()<available.height()/2)
                {
                    pos = TOP;
                    TaskBarSize = all.height() - available.height();
                    TaskBarLength = all.width();
                }
                else if (all.height() == available.height())
                {
                    pos = RIGHT;
                    TaskBarSize = all.width() - available.width();
                    TaskBarLength = all.height();
                }
                else
                {
                    pos = BOTTOM;
                    TaskBarSize = all.height() - available.height();
                    TaskBarLength = all.width();
                }

            }
            else
            {
                pos = LEFT;
                TaskBarSize = all.width() - available.width();
                TaskBarLength = all.height();
            }*/
            window->setVisible(true);
            //window->setFocus();
        }
    }
    else
        window->setVisible(false);
}

void Tray::exitClicked()
{
    Hide();
    exit(0);
}

void Tray::optionsClicked()
{
    //communicator->moveMouse(10,10);
    //config->setVisible(true);
}

void Tray::getInfoClicked()
{
    icon->showMessage(tr("Server info"), communicator->getLocalhostInfo());
}
