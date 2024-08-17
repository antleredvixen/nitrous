#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "statuswidget.h"
#include <libusb.h>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTextEdit>
#include <QTimer>
#include <QStorageInfo>
#include <QDateTime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , stemPlayerConnected(false) // Initialize the connection status to false
{
    ui->setupUi(this);

    consoleWindow = new QTextEdit(this);
    consoleWindow->setReadOnly(true);

    // Create the StatusWidget
    StatusWidget *statusWidget = new StatusWidget(this);

    // Create a vertical layout for the central widget
    QVBoxLayout *vboxLayout = new QVBoxLayout(ui->centralwidget);

    // Add a stretch to push the widgets below to the bottom
    vboxLayout->addStretch();

    // Create a horizontal layout for the statusWidget and consoleWindow
    QHBoxLayout *statusHBoxLayout = new QHBoxLayout;
    statusHBoxLayout->addWidget(statusWidget);
    statusHBoxLayout->addWidget(consoleWindow);

    // Set a fixed height for the consoleWindow widget
    consoleWindow->setFixedHeight(80); // Replace with desired height

    // Create a vertical layout for the statusWidget to push it to the bottom
    QVBoxLayout *statusVBoxLayout = new QVBoxLayout;
    statusVBoxLayout->addStretch();
    statusVBoxLayout->addWidget(statusWidget);

    // Create a vertical layout for the consoleWindow to push it to the bottom
    QVBoxLayout *consoleVBoxLayout = new QVBoxLayout;
    consoleVBoxLayout->addStretch();
    consoleVBoxLayout->addWidget(consoleWindow);

    // Replace the widgets in the statusHBoxLayout with the new vertical layouts
    statusHBoxLayout->removeWidget(statusWidget);
    statusHBoxLayout->removeWidget(consoleWindow);
    statusHBoxLayout->addLayout(statusVBoxLayout);
    statusHBoxLayout->addLayout(consoleVBoxLayout);

    // Add the statusHBoxLayout to the central widget layout
    vboxLayout->addLayout(statusHBoxLayout);

    // Check if the stem player is connected on initialization
    checkStemPlayerConnection();

    timer.setInterval(1000); // Check every second
    connect(&timer, &QTimer::timeout, this, &MainWindow::checkForStemPlayer);
    timer.start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::checkStemPlayerConnection()
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

    stemPlayerConnected = isConnected;

    QString timestamp = QDateTime::currentDateTime().toString("[yyyy-MM-dd HH:mm:ss] ");
    if (isConnected) {
        consoleWindow->append(timestamp + "<font color='lime'>Stem Player connected!</font>");
    } else {
        consoleWindow->append(timestamp + "<font color='red'>Stem Player not connected.</font>");
    }
}

void MainWindow::checkForStemPlayer()
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
