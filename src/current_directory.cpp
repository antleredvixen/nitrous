// current_directory.cpp
#include "current_directory.h"
#include "content_browser.h"

void currentDirectory(QLabel *label, bool connectionStatus, ContentBrowser *contentBrowser) {
    if (connectionStatus) {
        // Get a list of all storage drives
        QList<QStorageInfo> storageDrives = QStorageInfo::mountedVolumes();

        // Iterate over the drives and check if the drive is labeled
        for (const QStorageInfo &drive : storageDrives) {
            if (drive.name() == "STEM PLAYER") {
                // Update the current directory label with the root directory of the drive
                label->setText(drive.rootPath());
                contentBrowser->populateList(drive.rootPath());
                return;
            }
        }

    } else {
        // Display the current working directory
        label->setText(QDir::currentPath());
        contentBrowser->populateList(QDir::currentPath());
    }
}

void openFolder(QLabel *label, QMainWindow *mainWindow, ContentBrowser *contentBrowser) {
    QString folderPath = QFileDialog::getExistingDirectory(mainWindow, "Open Folder");
    if (!folderPath.isEmpty()) {
        label->setText(folderPath);
        contentBrowser->populateList(folderPath);
    }
}
