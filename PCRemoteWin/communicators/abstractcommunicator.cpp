#include "abstractcommunicator.h"

AbstractCommunicator::AbstractCommunicator()
{
}

void AbstractCommunicator::moveMouse(int x, int y)
{
    static int oldx = cursor.pos().x(), oldy = cursor.pos().y();
    cout<<"move: "<<x<<"   "<<y<<endl;
    //oldx += (x * MOUSE_MULTIPLY);
    //oldy += (y * MOUSE_MULTIPLY);
    //cursor.setPos(oldx, oldy);
    int destx = oldx + (x * MOUSE_MULTIPLY);
    int desty = oldy + (y * MOUSE_MULTIPLY);
    int xdx = destx > oldx ? 1 : -1;
    int ydy = desty > oldy ? 1 : -1;
    while (oldx != destx || oldy != desty)
    {
        if (oldx != destx)
            oldx += xdx;
        if (oldy != desty)
            oldy += ydy;
        cursor.setPos(oldx, oldy);
        //mouse_event(MOUSEEVENTF_MOVE, oldx, oldy,0,0);
        //QThread::usleep(5);
    }
}

void AbstractCommunicator::scroll(char o, char v)
{
    cout<<"scroll: "<<(int)o<<"   "<<(int)v<<endl;
    if (o == 1)
        mouse_event(MOUSEEVENTF_WHEEL,0,0, v * SCROLL_MULTIPLY, 0);
    else
        mouse_event(MOUSEEVENTF_HWHEEL,0,0, v * SCROLL_MULTIPLY, 0);
}

void AbstractCommunicator::leftMouseButton()
{
    cout<<"left mouse button click"<<endl;
    mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
    mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);
}

void AbstractCommunicator::leftMouseButtonDown()
{
    cout<<"left mouse button down"<<endl;
    mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
}
void AbstractCommunicator::leftMouseButtonUp()
{
    cout<<"left mouse button up"<<endl;
    mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);
}

void AbstractCommunicator::rightMouseButton()
{
    mouse_event(MOUSEEVENTF_RIGHTDOWN,0,0,0,0);
    mouse_event(MOUSEEVENTF_RIGHTUP,0,0,0,0);
}

void AbstractCommunicator::newClientInformation(char type)
{
    if (type == 1)
        message.showAndroidClientAddedMessage();
}

AbstractCommunicator::KeyRep AbstractCommunicator::translateKeycode(char c)
{
    switch(c)
    {
    case A:
        return KeyRep(0x41, 0x9e);
    case B:
        return KeyRep(0x42, 0xb0);
    case C:
        return KeyRep(0x43, 0xae);
    case D:
        return KeyRep(0x44, 0xA0);
    case E:
        return KeyRep(0x45, 0x92);
    case F:
        return KeyRep(0x46, 0xA1);
    case G:
        return KeyRep(0x47, 0xA2);
    case H:
        return KeyRep(0x48, 0xA3);
    case I:
        return KeyRep(0x49, 0x97);
    case J:
        return KeyRep(0x4A, 0xA4);
    case K:
        return KeyRep(0x4B, 0xA5);
    case L:
        return KeyRep(0x4C, 0xA6);
    case M:
        return KeyRep(0x4D, 0xB2);
    case N:
        return KeyRep(0x4E, 0);
    case O:
        return KeyRep(0x4F, 0);
    case P:
        return KeyRep(0x50, 0);
    case Q:
        return KeyRep(0x51,0);
    case R:
        return KeyRep(0x52,0);
    case S:
        return KeyRep(0x53,0);
    case T:
        return KeyRep(0x54,0);
    case U:
        return KeyRep(0x55,0);
    case V:
        return KeyRep(0x56,0);
    case W:
        return KeyRep(0x57,0);
    case X:
        return KeyRep(0x58,0);
    case Y:
        return KeyRep(0x59,0);
    case Z:
        return KeyRep(0x5A,0);
    case B0:
        return KeyRep(0x30,0);
    case B1:
        return KeyRep(0x31,0);
    case B2:
        return KeyRep(0x32,0);
    case B3:
        return KeyRep(0x33,0);
    case B4:
        return KeyRep(0x34,0);
    case B5:
        return KeyRep(0x35,0);
    case B6:
        return KeyRep(0x36,0);
    case B7:
        return KeyRep(0x37,0);
    case B8:
        return KeyRep(0x38,0);
    case B9:
        return KeyRep(0x39,0);
    case DOT:
        return KeyRep(VK_OEM_PERIOD, 0);
    case SEMICOLON:
        return KeyRep(VK_OEM_1,0);
    case SLASH:
        return KeyRep(VK_OEM_2,0);
    case BACKSPACE:
        return KeyRep(VK_BACK,0);
    case ENTER:
        return KeyRep(VK_RETURN, 0);
    case COMA:
        return KeyRep(VK_OEM_COMMA, 0);
    case MINUS:
        return KeyRep(VK_OEM_MINUS,0);
    case TILDA:
        return KeyRep(VK_OEM_3,0);
    case SQUAREBRACKET1:
        return KeyRep(VK_OEM_4,0);
    case BACKSLASH:
        return KeyRep(VK_OEM_5, 0);
    case SQUAREBRACKET2:
        return KeyRep(VK_OEM_6,0);
    case QUOTATION:
        return KeyRep(VK_OEM_7,0);
    case SPACE:
        return KeyRep(VK_SPACE, 0);
    case LCTRL:
        return KeyRep(VK_LCONTROL,0);
    case RCTRL:
        return KeyRep(VK_RCONTROL,0);
    case EQUALS:
        return KeyRep(VkKeyScan('='),0);//doesn't work :(
    case TAB:
        return KeyRep(VK_TAB, 0);
    case LSHIFT:
        return KeyRep(VK_LSHIFT,0);
    case RSHIFT:
        return KeyRep(VK_RSHIFT, 0);
    case LALT:
        return KeyRep(VK_LMENU, 0);
    case RALT:
        return KeyRep(VK_RMENU, 0);
    case CAPSLOCK:
        return KeyRep(VK_CAPITAL, 0);
    case VOLUP:
        return KeyRep(VK_VOLUME_UP, 0);
    case VOLDOWN:
        return KeyRep(VK_VOLUME_DOWN, 0);
    case MEDIAPREV:
        return KeyRep(VK_MEDIA_PREV_TRACK, 0);
    case MEDIANEXT:
        return KeyRep(VK_MEDIA_NEXT_TRACK, 0);
    case MEDIAPLAY:
        return KeyRep(VK_MEDIA_PLAY_PAUSE, 0);
    }
    return KeyRep(-1,-1);
}
void AbstractCommunicator::useKeyboard(char state, char key)
{

    static bool shift = false;
    static KeyRep lastShift(-1,-1);
    KeyRep k = translateKeycode(key);
    if (k.code == -1 && k.scan == -1)
    {
        cout<<"Unknown key entered"<<endl;
        return;
    }
    if (state == 3)
    {
        keybd_event(k.code, k.scan,0,0);
        keybd_event(k.code, k.scan,KEYEVENTF_KEYUP,0);
    }
    else if (state == 1)
    {
        if (key == LSHIFT || key == RSHIFT)
        {
            if (!shift)
            {
                shift = true;
                lastShift = k;
                keybd_event(k.code, k.scan,0,0);
            }
            else
            {
                shift = false;
                keybd_event(lastShift.code, lastShift.scan,KEYEVENTF_KEYUP,0);
            }
        }
        else
            keybd_event(k.code, k.scan,0,0);
    }
    else
    {
        if (key == LSHIFT || key == RSHIFT)
        {
            shift = false;
            keybd_event(lastShift.code, lastShift.scan,KEYEVENTF_KEYUP,0);
        }
        else
            keybd_event(k.code, k.scan,KEYEVENTF_KEYUP,0);
    }
}
