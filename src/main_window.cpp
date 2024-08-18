// main_window.cpp
#include "./ui_main_window.h"
#include "main_window.h"
#include "status_display.h"
#include "device_connection.h"
#include "current_directory.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    consoleWindow(new QTextEdit),
    timer(),
    connectionStatus(false),
    currentDirectoryLabel(new QLabel),
    deviceGraphic(new StatusDisplay),
    scan()
{
    ui->setupUi(this);

    consoleWindow = new QTextEdit(this);
    consoleWindow->setReadOnly(true);

    // Create the device graphic
    deviceGraphic = new StatusDisplay(this);

    // Create a vertical layout for the central widget
    QVBoxLayout *vboxLayout = new QVBoxLayout(ui->centralwidget);

    // Add a stretch to push the widgets below to the bottom
    vboxLayout->addStretch();

    // Create a horizontal layout for the statusWidget and consoleWindow
    QHBoxLayout *statusHBoxLayout = new QHBoxLayout;
    statusHBoxLayout->addWidget(deviceGraphic);
    statusHBoxLayout->addWidget(consoleWindow);

    // Set a fixed height for the consoleWindow widget
    consoleWindow->setFixedHeight(80); // Replace with desired height

    // Create a vertical layout for the statusWidget to push it to the bottom
    QVBoxLayout *statusVBoxLayout = new QVBoxLayout;
    statusVBoxLayout->addStretch();
    statusVBoxLayout->addWidget(deviceGraphic);

    // Create a vertical layout for the consoleWindow to push it to the bottom
    QVBoxLayout *consoleVBoxLayout = new QVBoxLayout;
    consoleVBoxLayout->addStretch();
    consoleVBoxLayout->addWidget(consoleWindow);

    // Replace the widgets in the statusHBoxLayout with the new vertical layouts
    statusHBoxLayout->removeWidget(deviceGraphic);
    statusHBoxLayout->removeWidget(consoleWindow);
    statusHBoxLayout->addLayout(statusVBoxLayout);
    statusHBoxLayout->addLayout(consoleVBoxLayout);

    // Add the statusHBoxLayout to the central widget layout
    vboxLayout->addLayout(statusHBoxLayout);

    // Create a label to display the current directory
    currentDirectoryLabel = new QLabel(this);

    // Add the label to the main layout
    vboxLayout->addWidget(currentDirectoryLabel);

    connectionStatus = scan.verifyConnection();
    scan.displayConnection(connectionStatus, consoleWindow);
    currentDirectory(currentDirectoryLabel, connectionStatus); // Call the currentDirectory function here

    timer.setInterval(1000); // Check every second
    connect(&timer, &QTimer::timeout, this, &MainWindow::deviceConnection);
    timer.start();

    connect(ui->actionOpen, &QAction::triggered, this, [this]() {
        openFolder(currentDirectoryLabel, this);
    });
}

void MainWindow::deviceConnection() {
    bool newConnectionStatus = scan.verifyConnection();
    if (newConnectionStatus!= connectionStatus) {
        connectionStatus = newConnectionStatus;
        scan.displayConnection(connectionStatus, consoleWindow);
        currentDirectory(currentDirectoryLabel, connectionStatus); // Pass the connectionStatus to currentDirectory
    }
}


MainWindow::~MainWindow()
{
    delete ui;
}
