// device_connection.h
#ifndef DEVICE_CONNECTION_H
#define DEVICE_CONNECTION_H

#include <QDateTime>
#include <QTextEdit>
#include <libusb.h>

class DeviceConnection
{
public:
    void displayConnection(bool &connectionStatus, QTextEdit* consoleWindow);
    bool verifyConnection();
};
#endif // DEVICE_CONNECTION_H
