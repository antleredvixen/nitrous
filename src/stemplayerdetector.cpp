// stemplayerdetector.cpp
#include "stemplayerdetector.h"

void StemPlayerDetector::checkStemPlayerConnection(QTextEdit* consoleWindow)
{
    // Initialize libusb
    libusb_init(NULL);

    // Get a list of all USB devices
    libusb_device **devices;
    ssize_t device_count = libusb_get_device_list(NULL, &devices);

    bool isConnected = false;

    // Iterate over the devices and check if the Stem Player is connected
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

    QString timestamp = QDateTime::currentDateTime().toString("[yyyy-MM-dd HH:mm:ss] ");
    if (isConnected) {
        consoleWindow->append(timestamp + "<font color='lime'>Stem Player connected!</font>");
    } else {
        consoleWindow->append(timestamp + "<font color='red'>Stem Player not connected.</font>");
    }
}

void StemPlayerDetector::checkForStemPlayer(bool &stemPlayerConnected, QTextEdit* consoleWindow)
{
    // Initialize libusb
    libusb_init(NULL);

    // Get a list of all USB devices
    libusb_device **devices;
    ssize_t device_count = libusb_get_device_list(NULL, &devices);

    bool isConnected = false;

    // Iterate over the devices and check if the Stem Player is connected
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

    // Check if the connection status has changed
    if (isConnected!= stemPlayerConnected) {
        stemPlayerConnected = isConnected;
        QString timestamp = QDateTime::currentDateTime().toString("[yyyy-MM-dd HH:mm:ss] ");
        if (isConnected) {
            consoleWindow->append(timestamp + "<font color='lime'>Stem Player connected!</font>");
        } else {
            consoleWindow->append(timestamp + "<font color='red'>Stem Player not connected.</font>");
        }
    }
}
