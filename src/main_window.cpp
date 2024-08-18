// main_window.cpp
#include "./ui_main_window.h"
#include "main_window.h"
#include "status_display.h"
#include "device_connection.h"
#include "current_directory.h"
#include "preferences.h"

void MainWindow::showPreferences()
{
    Preferences preferences;
    preferences.exec();
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    consoleWindow(new QTextEdit),
    timer(),
    connectionStatus(false),
    currentDirectoryLabel(new QLabel),
    deviceGraphic(new StatusDisplay),
    scan(),
    contentBrowser(new ContentBrowser(this))
{
    ui->setupUi(this);

    consoleWindow = new QTextEdit(this);
    consoleWindow->setReadOnly(true);

    // Create the device graphic
    deviceGraphic = new StatusDisplay(this);

    // Create a vertical layout for the central widget
    QVBoxLayout *vboxLayout = new QVBoxLayout(ui->centralwidget);

    // Create a vertical layout for the contentBrowser
    QVBoxLayout *contentBrowserLayout = new QVBoxLayout;
    contentBrowser->setMinimumSize(150, 150);
    contentBrowser->setMaximumWidth(150);
    contentBrowser->setMinimumWidth(150);
    contentBrowserLayout->addWidget(contentBrowser);

    // Add the contentBrowser layout to the vboxLayout
    vboxLayout->addLayout(contentBrowserLayout);

    // Create a horizontal layout for the status display and console window
    QHBoxLayout *statusDisplayLayout = new QHBoxLayout;

    // Add the device graphic to the statusDisplayLayout
    statusDisplayLayout->addWidget(deviceGraphic);

    // Create a vertical layout for the console window
    QVBoxLayout *consoleLayout = new QVBoxLayout;
    consoleLayout->addStretch();
    consoleWindow->setFixedHeight(deviceGraphic->height() / 2);
    consoleLayout->addWidget(consoleWindow);

    // Add the console layout to the statusDisplayLayout
    statusDisplayLayout->addLayout(consoleLayout);

    // Add the statusDisplayLayout to the vboxLayout
    vboxLayout->addLayout(statusDisplayLayout);

    // Create a label to display the current directory
    currentDirectoryLabel = new QLabel(this);

    // Add the label to the vboxLayout
    vboxLayout->addWidget(currentDirectoryLabel);

    connectionStatus = scan.verifyConnection();
    scan.displayConnection(connectionStatus, consoleWindow);
    currentDirectory(currentDirectoryLabel, connectionStatus, contentBrowser);

    timer.setInterval(1000); // Check every second
    connect(&timer, &QTimer::timeout, this, &MainWindow::deviceConnection);
    timer.start();

    connect(ui->actionOpen, &QAction::triggered, this, [this]() {
        openFolder(currentDirectoryLabel, this, contentBrowser);
    });

    connect(ui->actionPreferences, SIGNAL(triggered()), this, SLOT(showPreferences()));
}

void MainWindow::deviceConnection() {
    bool newConnectionStatus = scan.verifyConnection();
    if (newConnectionStatus!= connectionStatus) {
        connectionStatus = newConnectionStatus;
        scan.displayConnection(connectionStatus, consoleWindow);
        currentDirectory(currentDirectoryLabel, connectionStatus, contentBrowser);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
