#include "tray.h"

Tray::Tray(QWidget *parent) :
    QObject(parent)
{
    QIcon i("PCRemoteIcon.png");
    aboutw = NULL;
    configDial = NULL;
    adhocdial = NULL;
    icon = new QSystemTrayIcon((QObject*)parent);
    icon->setIcon(i);
    trayMenu = new QMenu();
    adhocSubMenu = new QMenu();
    adhocSubMenu->setTitle(tr("Ad Hoc Connection"));
    adhocSubMenu->addAction(tr("Start"), this, SLOT(adHocClicked()));
    adhocSubMenu->addAction(tr("Stop"), this, SLOT(closeAdHocClicked()));
    trayMenu->addAction(tr("Options"), this, SLOT(optionsClicked()));
    //trayMenu->addMenu(adhocSubMenu);
    trayMenu->addAction(tr("Server info"), this, SLOT(getInfoClicked()));
    trayMenu->addAction(tr("About"),this, SLOT(aboutClicked()));
    trayMenu->addAction(tr("Exit"), this, SLOT(exitClicked()));
    icon->setContextMenu(trayMenu);
    connect(icon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this, SLOT(activate(QSystemTrayIcon::ActivationReason)));
    communicator = new NetworkCommunicator;
    communicator->Listen();
}

Tray::~Tray()
{
    delete trayMenu;
    delete adhocSubMenu;
    delete icon;
    delete communicator;
    if (aboutw != NULL)
        delete aboutw;
    if (configDial != NULL)
        delete configDial;
    if (adhocdial != NULL)
        delete adhocdial;
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
    if (configDial == NULL)
        configDial = new ConfigDialog((QWidget*)this->parent());
    configDial->show();
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
    if (aboutw == NULL)
        aboutw = new AboutDialog((QWidget*)this->parent());
    aboutw->show();
}

void Tray::adHocClicked()
{
    if (adhocdial == NULL)
        adhocdial = new AdHocDialog((QWidget*)this->parent());
    adhocdial->show();
}

void Tray::closeAdHocClicked()
{
    if (adhocdial == NULL)
        adhocdial = new AdHocDialog((QWidget*)this->parent());
    adhocdial->CloseAdHoc();
}
