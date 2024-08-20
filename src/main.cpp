// main.cpp
#include "./ui_main.h"
#include "main.h"
#include "status.h"
#include "connect.h"
#include "directory.h"
#include "preferences.h"
#include "about.h"
#include "browser.h"
#include "console.h"
#include <QApplication>
#include <QLocale>
#include <QStyleFactory>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    a.setStyle(QStyleFactory::create("fusion"));

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "nitrous_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    Main w;
    w.show();
    return a.exec();
}

void Main::showPreferences()
{
    Preferences preferences(deviceGraphic);
    preferences.exec();
}

void Main::showAbout() {
    About aboutWindow;
    aboutWindow.exec();
}

Main::Main(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Main),
    consoleWindow(new Console(this)),
    timer(),
    connectionStatus(false),
    currentDirectoryLabel(new QLabel),
    deviceGraphic(nullptr),
    scan(),
    contentBrowser(new Browser(consoleWindow, currentDirectoryLabel, this)) // Pass the required parameters to the Browser constructor
{
    ui->setupUi(this);

    // Create the device graphic
    deviceGraphic = new Status(this);

    // Create a vertical layout for the central widget
    QVBoxLayout *vboxLayout = new QVBoxLayout(ui->centralwidget);

    // Create a vertical layout for the contentBrowser
    QVBoxLayout *contentBrowserLayout = new QVBoxLayout;
    contentBrowser->setMinimumSize(150, 150);
    contentBrowser->setMaximumWidth(deviceGraphic->width());
    contentBrowser->setMinimumWidth(deviceGraphic->width());
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
    consoleWindow->setFixedHeight(deviceGraphic->height() / 2); // Set the console height to half the height of the status
    consoleLayout->addWidget(consoleWindow);

    // Add the console layout to the statusDisplayLayout
    statusDisplayLayout->addLayout(consoleLayout);

    // Add the statusDisplayLayout to the vboxLayout
    vboxLayout->addLayout(statusDisplayLayout);

    // Create a label to display the current directory
    currentDirectoryLabel = new QLabel;

    // Add the label to the vboxLayout
    vboxLayout->addWidget(currentDirectoryLabel);

    connectionStatus = scan.verifyConnection();
    scan.displayConnection(connectionStatus, consoleWindow);
    directory(currentDirectoryLabel, connectionStatus, contentBrowser);

    timer.setInterval(1000); // Check every second
    connect(&timer, &QTimer::timeout, this, &Main::deviceConnection);
    timer.start();

    connect(ui->actionOpen, &QAction::triggered, this, [this]() {
        openFolder(currentDirectoryLabel, this, contentBrowser);
    });

    connect(ui->actionPreferences, &QAction::triggered, this, &Main::showPreferences);
    connect(ui->actionAbout, &QAction::triggered, this, &Main::showAbout);

    // Connect the backClicked signal to the currentDirectory function
    connect(contentBrowser, &Browser::backClicked, this, [this]() {
        directory(currentDirectoryLabel, connectionStatus, contentBrowser);
    });
}

void Main::deviceConnection() {
    bool newConnectionStatus = scan.verifyConnection();
    if (newConnectionStatus!= connectionStatus) {
        connectionStatus = newConnectionStatus;
        scan.displayConnection(connectionStatus, consoleWindow);
        directory(currentDirectoryLabel, connectionStatus, contentBrowser);
    }
}

Main::~Main()
{
    delete ui;
}
