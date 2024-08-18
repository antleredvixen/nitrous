// device_connection.cpp
#include "device_connection.h"

void DeviceConnection::displayConnection(bool &connectionStatus, QTextEdit* consoleWindow)
{
    QString timestamp = QDateTime::currentDateTime().toString("[yyyy-MM-dd HH:mm:ss] ");
    if (connectionStatus == true) {
        consoleWindow->append(timestamp + "<font color='lime'>Stem Player connected!</font>");
    } else {
        consoleWindow->append(timestamp + "<font color='red'>Stem Player not connected.</font>");
    }
}

bool DeviceConnection::verifyConnection()
{
    // Initialize libusb
    libusb_init(NULL);

    // Get a list of all USB devices
    libusb_device **devices;
    ssize_t device_count = libusb_get_device_list(NULL, &devices);

    // Iterate over the devices and check if the Stem Player is connected
    bool isConnected = false;
    for (ssize_t i = 0; i < device_count; i++) {
        libusb_device *device = devices[i];
        libusb_device_descriptor descriptor;
        libusb_get_device_descriptor(device, &descriptor);

        // Check if the device matches the Stem Player's product and vendor ID
        if (descriptor.idVendor == 4617 &&
            descriptor.idProduct == 22314) {
            isConnected = true;
            break;
        }
    }

    // Clean up
    libusb_free_device_list(devices, 1);
    libusb_exit(NULL);

    return isConnected;
}
