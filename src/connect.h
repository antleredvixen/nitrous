// connect.h
#ifndef CONNECT_H
#define CONNECT_H

#include <QDateTime>
#include <QTextEdit>
#include <libusb.h>

class Connect
{
public:
    void displayConnection(bool &connectionStatus, QTextEdit* consoleWindow);
    bool verifyConnection();
};

#endif // CONNECT_H
