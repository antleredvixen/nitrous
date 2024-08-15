#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "statuswidget.h"
#include <libusb.h>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTextEdit>
#include <QTimer>
#include <QStorageInfo>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , stemPlayerConnected(false) // Initialize the connection status to false
{
    ui->setupUi(this);

    consoleWindow = new QTextEdit(this);
    consoleWindow->setReadOnly(true);
    consoleWindow->insertHtml("<font color='red'>Stem Player not connected.</font>");

    // Create the StatusWidget
    StatusWidget *statusWidget = new StatusWidget(this);

    // Create a vertical layout for the central widget
    QVBoxLayout *vboxLayout = new QVBoxLayout(ui->centralwidget);

    // Create a horizontal layout for the bottom row
    QHBoxLayout *hboxLayout = new QHBoxLayout;

    // Add the horizontal layout to the vertical layout
    vboxLayout->addStretch(); // Pushes the widget to the bottom
    vboxLayout->addWidget(consoleWindow);

    vboxLayout->addLayout(hboxLayout);

    // Add the status widget to the horizontal layout
    hboxLayout->addWidget(statusWidget);
    hboxLayout->addStretch(); // Pushes the widget to the left

    timer.setInterval(1000); // Check every second
    connect(&timer, &QTimer::timeout, this, &MainWindow::checkForStemPlayer);
    timer.start();
}

MainWindow::~MainWindow()
{
    delete ui;
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
        consoleWindow->clear(); // Clear the console window
        if (isConnected) {
            consoleWindow->insertHtml("<font color='lime'>Stem Player connected!</font>");
        } else {
            consoleWindow->insertHtml("<font color='red'>Stem Player not connected.</font>");
        }
    }
}
