// mainwindow.cpp
#include "./ui_mainwindow.h"
#include "mainwindow.h"
#include "statuswidget.h"
#include "stemplayerdetector.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , connectionStatus(false) // Initialize the connection status to false
{
    ui->setupUi(this);

    consoleWindow = new QTextEdit(this);
    consoleWindow->setReadOnly(true);

    // Create the StatusWidget
    statusWidget = new StatusWidget(this);

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

    // Create a label to display the current directory
    currentDirectoryLabel = new QLabel(this);
    currentDirectoryLabel->setText(QDir::currentPath());

    // Add the label to the main layout
    vboxLayout->addWidget(currentDirectoryLabel);

    Device detector;
    detector.displayConnection(connectionStatus, consoleWindow);

    timer.setInterval(1000); // Check every second
    connect(&timer, &QTimer::timeout, this, &MainWindow::deviceConnection);
    timer.start();
}

void MainWindow::deviceConnection()
{
    Device detector;
    detector.verifyConnection(connectionStatus, consoleWindow);
}

MainWindow::~MainWindow()
{
    delete ui;
}
