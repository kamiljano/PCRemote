#include "clientsview.h"

ClientsView::ClientsView(QWidget *parent) :
    QWidget(parent)
{
    this->clients = 0;
    layout = new QHBoxLayout();
    lAnd = new QLabel(tr("Clients connected: "));
    layout->addWidget(lAnd);
    lAndNo = new QLabel();
    layout->addWidget(lAndNo);
    this->setLayout(layout);
    setView();
}

ClientsView::~ClientsView()
{
    delete layout;
    delete lAnd;
    delete lAndNo;
}

void ClientsView::addClient()
{
    this->clients ++;
    setView();
}
void ClientsView::removeClient()
{
    this->clients--;
    setView();
}

void ClientsView::setView()
{
    lAndNo->setText(QString::number(clients));
}
