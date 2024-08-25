// main.cpp
#include "./ui_main.h"
#include "main.h"
#include "console.h"
#include "status.h"
#include "connect.h"
#include "browser.h"
#include "directory.h"
#include "preferences.h"
#include "about.h"
#include "config.h"

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

Main::Main(QWidget* parent)
    : QMainWindow(parent),
    ui(new Ui::Main),
    consoleWindow(new Console(this)),
    timer(),
    connectionStatus(false),
    currentDirectoryLabel(new QLabel),
    deviceGraphic(nullptr),
    scan(),
    contentBrowser(new Browser(consoleWindow, currentDirectoryLabel, this)),
    configForm(new Config(this))
{
    ui->setupUi(this);

    defaultDirectory = QDir::currentPath();

    // Create the device graphic
    deviceGraphic = new Status(this);

    // Create a vertical layout for the central widget
    QVBoxLayout *vboxLayout = new QVBoxLayout(ui->centralwidget);

    // Create a horizontal layout for the contentBrowser and configForm
    QHBoxLayout *contentLayout = new QHBoxLayout;
    contentBrowser->setMinimumSize(150, 150);
    contentBrowser->setMaximumWidth(deviceGraphic->width());
    contentBrowser->setMinimumWidth(deviceGraphic->width());
    contentLayout->addWidget(contentBrowser);

    // Add the configForm to the contentLayout
    contentLayout->addWidget(configForm);

    // Add the contentLayout to the vboxLayout
    vboxLayout->addLayout(contentLayout);

    // Create a horizontal layout for the status display and console window
    QHBoxLayout *statusDisplayLayout = new QHBoxLayout;

    // Create a vertical layout for the device graphic and status label
    QVBoxLayout *deviceStatusLayout = new QVBoxLayout;
    deviceStatusLayout->addWidget(deviceGraphic);

    // Create a label to display "Status: connection"
    statusLabel = new QLabel("<b>Status: <font color='red'>Disconnected</font></b>");
    statusLabel->setTextFormat(Qt::RichText);
    deviceStatusLayout->addWidget(statusLabel);
    deviceStatusLayout->setAlignment(statusLabel, Qt::AlignHCenter);

    // Add the device graphic and status label to the deviceLayout
    QVBoxLayout *deviceLayout = new QVBoxLayout;
    deviceLayout->addStretch();
    deviceLayout->addLayout(deviceStatusLayout);
    deviceLayout->addStretch();

    statusDisplayLayout->addLayout(deviceLayout);

    // Create a vertical layout for the console window
    QVBoxLayout *consoleLayout = new QVBoxLayout;
    consoleWindow->setFixedHeight(deviceGraphic->height());
    consoleLayout->addWidget(consoleWindow);

    // Add the console layout to the statusDisplayLayout
    statusDisplayLayout->addLayout(consoleLayout);

    // Add the statusDisplayLayout to the vboxLayout
    vboxLayout->addLayout(statusDisplayLayout);

    // Create a label to display "Current Directory: "
    QLabel *directoryPrefixLabel = new QLabel("<b>Current Directory:</b>");

    // Create a widget to display the current directory
    QWidget *statusBarWidget = new QWidget;
    QHBoxLayout *statusBarLayout = new QHBoxLayout(statusBarWidget);
    statusBarLayout->addWidget(directoryPrefixLabel);
    statusBarLayout->addWidget(currentDirectoryLabel);
    ui->statusbar->addWidget(statusBarWidget);

    connectionStatus = scan.verifyConnection();
    scan.displayConnection(connectionStatus, consoleWindow->getConsoleTextEdit());
    if (connectionStatus) {
        directory(currentDirectoryLabel, connectionStatus, contentBrowser, configForm, consoleWindow);
        statusLabel->setText("<b>Status: </b><font color='lime'>Connected</font>");
    } else {
        currentDirectoryLabel->setText(QDir::currentPath());
        contentBrowser->populateList(QDir::currentPath());
        configForm->updateCurrentDirectory(QDir::currentPath());
        statusLabel->setText("<b>Status: </b><font color='red'>Disconnected</font>");
    }

    timer.setInterval(1000); // Check every second
    connect(&timer, &QTimer::timeout, this, &Main::deviceConnection);
    timer.start();

    connect(ui->actionOpen, &QAction::triggered, this, [this]() {
        openFolder(currentDirectoryLabel, this, contentBrowser, configForm, consoleWindow);
    });

    connect(ui->actionPreferences, &QAction::triggered, this, &Main::showPreferences);
    connect(ui->actionAbout, &QAction::triggered, this, &Main::showAbout);
}

void Main::deviceConnection() {
    bool newConnectionStatus = scan.verifyConnection();
    if (newConnectionStatus != connectionStatus) {
        connectionStatus = newConnectionStatus;
        scan.displayConnection(connectionStatus, consoleWindow->getConsoleTextEdit());
        if (connectionStatus) {
            directory(currentDirectoryLabel, connectionStatus, contentBrowser, configForm, consoleWindow);
            statusLabel->setText("<b>Status: </b><font color='lime'>Connected</font>");
        } else {
            currentDirectoryLabel->setText(defaultDirectory);
            contentBrowser->populateList(defaultDirectory);
            configForm->updateCurrentDirectory(defaultDirectory);
            statusLabel->setText("<b>Status: </b><font color='red'>Disconnected</font>");
        }
    }
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

Main::~Main()
{
    delete ui;
}
