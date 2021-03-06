#ifndef ABSTRACTCOMMUNICATOR_H
#define ABSTRACTCOMMUNICATOR_H
#include <QCursor>
#include <iostream>
#include "../messagewindow.h"
#include "../Widgets/clientsview.h"
#include "../configuration.h"

#include <Windows.h>

#define SCROLL_MULTIPLY -100
#define MOUSE_MULTIPLY 10

using namespace std;

class AbstractCommunicator : public QThread
{
    ClientsView *clientsView;
    QCursor cursor;
    enum Keys{LSHIFT=1,RSHIFT,LALT,RALT,SPACE,RCTRL,LCTRL,A, B, C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,
            S,T,U,V,W,X,Y,Z,COMA,DOT,SLASH,SEMICOLON,QUOTATION, SQUAREBRACKET1, SQUAREBRACKET2,
            BACKSLASH,TILDA,B1,B2, B3, B4, B5, B6, B7, B8, B9,B0,MINUS, EQUALS, BACKSPACE, ENTER, TAB, CAPSLOCK,
            VOLUP, VOLDOWN, MEDIAPREV, MEDIANEXT, MEDIAPLAY, ARROWLEFT, ARROWRIGHT};
    struct KeyRep{int code; int scan;
                  KeyRep(int a, int b)
                   {
                      code = a; scan = b;
                  }
                  };
    KeyRep translateKeycode(char c);

public:
    AbstractCommunicator();
    virtual void Listen() = 0;
    virtual QString getLocalhostInfo() = 0;
    virtual void setClientsView(ClientsView *cv);
protected:
    MessageWindow message;
    virtual void moveMouse(int x, int y);
    virtual void scroll(char orientation, char val);
    virtual void leftMouseButton();
    virtual void leftMouseButtonDown();
    virtual void leftMouseButtonUp();
    virtual void rightMouseButton();
    virtual void newClientInformation(char type);
    virtual void useKeyboard(char state, char key);
    virtual void addNoClient();
    virtual void removeNoClient();
    virtual bool scan(char clientType); //returns true if client can be informed about address of server
    virtual void useKeyboard(QChar c);
    bool isUpperCharacter(QChar c);
};

#endif // ABSTRACTCOMMUNICATOR_H
