// browser.cpp
#include "browser.h"

Browser::Browser(Console *console, QLabel *currentDirectoryLabel, QWidget *parent) : QWidget(parent)
{
    this->console = console;
    this->currentDirectoryLabel = currentDirectoryLabel;

    listWidget = new QListWidget(this);
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(listWidget);
    setLayout(layout);

    // Connect the itemDoubleClicked signal to the handleItemDoubleClick slot
    connect(listWidget, &QListWidget::itemDoubleClicked, this, &Browser::handleItemDoubleClick);
}

void Browser::populateList(const QString &directory)
{
    QDir dir(directory);
    dir.setFilter(QDir::Dirs | QDir::NoDotAndDotDot);
    listWidget->clear();
    foreach (const QFileInfo &file, dir.entryInfoList()) {
        listWidget->addItem(file.fileName());
    }
    listWidget->insertItem(0, ".."); // Add a ".." item to navigate up
    currentDirectoryLabel->setText(directory); // Remove the extra slash
}

void Browser::handleItemDoubleClick(QListWidgetItem *item) {
    QString itemName = item->text();
    QString currentDirectory = currentDirectoryLabel->text();
    if (itemName == "..") {
        // Navigate up
        QDir dir(currentDirectory);
        dir.cdUp();
        currentDirectory = dir.path();
    } else {
        // Navigate down
        if (!currentDirectory.endsWith('/')) {
            currentDirectory += '/';
        }
        currentDirectory += itemName;
    }
    currentDirectoryLabel->setText(currentDirectory); // Update the directory label
    populateList(currentDirectory);
    qDebug() << "Current directory: " << currentDirectory; // Print the current directory to the console
}
