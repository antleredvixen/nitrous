// deviceconnection.h
#ifndef DEVICECONNECTION_H
#define DEVICECONNECTION_H

#include <QDateTime>
#include <QTextEdit>
#include <libusb.h>

class Device
{
public:
    void displayConnection(bool &connectionStatus, QTextEdit* consoleWindow);
    void verifyConnection(bool &connectionStatus, QTextEdit* consoleWindow);
    bool isConnected = false;
};

#endif // DEVICECONNECTION_H
