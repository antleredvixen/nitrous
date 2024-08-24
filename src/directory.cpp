// directory.cpp
#include "directory.h"
#include "browser.h"
#include "config.h"
#include <QFileDialog>

void directory(QLabel *label, bool connectionStatus, Browser *browser, Config *config) {
    // Get a list of all storage drives
    QList<QStorageInfo> storageDrives = QStorageInfo::mountedVolumes();

    // Iterate over the drives and check if the drive is labeled
    for (const QStorageInfo &drive : storageDrives) {
        if (drive.name() == "STEM PLAYER") {
            // Update the current directory label with the root directory of the drive
            QString directoryPath = drive.rootPath();
            directoryPath = directoryPath.replace("://", ":/"); // Replace any occurrence of "://" with ":/"
            label->setText(directoryPath);

            // Populate the list with the contents of the root directory
            browser->populateList(drive.rootPath());

            // Check if a CONFIG.TXT file is present in the current directory
            QString configFilePath = drive.rootPath() + "/CONFIG.TXT";
            if (QFile::exists(configFilePath)) {
                config->updateCurrentDirectory(drive.rootPath());
                config->setVisible(true);
            } else {
                config->setVisible(false);
            }
            return;
        }
    }
}

QString getCurrentDirectoryLocation() {
    return QDir::currentPath();
}

void openFolder(QLabel *label, QMainWindow *mainWindow, Browser *browser) {
    QString folderPath = QFileDialog::getExistingDirectory(mainWindow, "Open Folder");
    if (!folderPath.isEmpty()) {
        label->setText(folderPath);
        browser->populateList(folderPath);
    }
}
