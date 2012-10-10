#ifndef CLIENTSVIEW_H
#define CLIENTSVIEW_H

#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>

class ClientsView : public QWidget
{
    Q_OBJECT
    int clients;
    QHBoxLayout * layout;
    QLabel *lAnd,*lAndNo;
public:
    explicit ClientsView(QWidget *parent = 0);
    virtual ~ClientsView();
    void addClient();
    void removeClient();
private:
    void setView();
};

#endif // CLIENTSVIEW_H
