#include "tray.h"

Tray::Tray(QWidget *parent) :
    QObject(parent)
{
    QIcon i("icon.svg");
    //aboutw = NULL;
    icon = new QSystemTrayIcon((QObject*)parent);
    icon->setIcon(i);
    trayMenu = new QMenu();
    trayMenu->addAction(tr("Options"), this, SLOT(optionsClicked()));
    trayMenu->addAction(tr("Server info"), this, SLOT(getInfoClicked()));
    trayMenu->addAction(tr("About"),this, SLOT(aboutClicked()));
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
    //if (aboutw != NULL)
      //  delete aboutw;
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
            window->setVisible(true);
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

void Tray::setClientsView(ClientsView *cv)
{
    communicator->setClientsView(cv);
}

void Tray::aboutClicked()
{
    /*if (aboutw == NULL)
        aboutw = new AboutWindow();
    aboutw->show();*/
}
