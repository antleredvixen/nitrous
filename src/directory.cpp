// directory.cpp
#include "directory.h"
#include "config.h"
#include "console.h"

void directory(QLabel *label, bool connectionStatus, Browser *browser, Config *config, Console *console) {
    // Get a list of all storage drives
    QList<QStorageInfo> storageDrives = QStorageInfo::mountedVolumes();
    // Iterate over the drives and check if the drive is labeled
    for (const QStorageInfo &drive : storageDrives) {
        if (drive.name() == "STEM PLAYER") {
            // Update the current directory label with the root directory of the drive
            QString directoryPath = drive.rootPath();
            directoryPath = directoryPath.replace("://", ":/"); // Replace any occurrence of "://" with ":/"
            label->setText(directoryPath);
            config->updateCurrentDirectory(directoryPath);
            // Populate the list with the contents of the root directory
            browser->populateList(drive.rootPath());
            return;
        }
    }
    // If no STEM PLAYER drive is found, use the current directory
    QString currentDir = QDir::currentPath();
    label->setText(currentDir);
    browser->populateList(currentDir);
    config->updateCurrentDirectory(currentDir);
}

QString getCurrentDirectoryLocation() {
    return QDir::currentPath();
}

void openFolder(QLabel *label, QMainWindow *mainWindow, Browser *browser, Config *config, Console *console) {
    QString folderPath = QFileDialog::getExistingDirectory(mainWindow, "Open Folder");
    if (!folderPath.isEmpty()) {
        label->setText(folderPath);
        browser->populateList(folderPath);
        config->updateCurrentDirectory(folderPath);
    }
}
