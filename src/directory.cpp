// directory.cpp
#include "directory.h"
#include "browser.h"

void directory(QLabel *label, bool connectionStatus, Browser *browser) {
    // Get a list of all storage drives
    QList<QStorageInfo> storageDrives = QStorageInfo::mountedVolumes();

    // Iterate over the drives and check if the drive is labeled
    for (const QStorageInfo &drive : storageDrives) {
        if (drive.name() == "STEM PLAYER") {
            // Update the current directory label with the root directory of the drive
            QString directoryPath = drive.rootPath();
            directoryPath = directoryPath.replace("://", ":/"); // Replace any occurrence of "://" with ":/"
            label->setText(directoryPath); // Remove the extra slash

            // Populate the list with the contents of the root directory
            browser->populateList(drive.rootPath());
            return;
        }
    }
}

void openFolder(QLabel *label, QMainWindow *mainWindow, Browser *browser) {
    QString folderPath = QFileDialog::getExistingDirectory(mainWindow, "Open Folder");
    if (!folderPath.isEmpty()) {
        label->setText(folderPath); // Remove the extra slash

        // Populate the list with the contents of the selected directory
        browser->populateList(folderPath);
    }
}
