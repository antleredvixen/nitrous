// directory.cpp
#include "directory.h"
#include "browser.h"

void directory(QLabel *label, bool connectionStatus, Browser *browser) {
    if (connectionStatus) {
        // Get a list of all storage drives
        QList<QStorageInfo> storageDrives = QStorageInfo::mountedVolumes();

        // Iterate over the drives and check if the drive is labeled
        for (const QStorageInfo &drive : storageDrives) {
            if (drive.name() == "STEM PLAYER") {
                // Update the current directory label with the root directory of the drive
                label->setText(drive.rootPath());

                // Store the current directory location
                QSettings settings("YourCompany", "YourApp");
                settings.setValue("currentDirectory", drive.rootPath());

                // Extract album titles from ALBUM.TXT files in A folders
                QStringList albumTitles;
                for (int i = 1; i <= 9; i++) {
                    QString folderPath = drive.rootPath() + "/A" + QString::number(i);
                    if (QDir(folderPath).exists()) {
                        QString albumFilePath = folderPath + "/ALBUM.TXT";
                        if (QFile::exists(albumFilePath)) {
                            QFile albumFile(albumFilePath);
                            albumFile.open(QIODevice::ReadOnly);
                            QJsonDocument jsonDoc = QJsonDocument::fromJson(albumFile.readAll());
                            albumFile.close();

                            QJsonObject albumObject = jsonDoc.object();
                            QString albumTitle = albumObject.value("title").toString();
                            albumTitles.append(albumTitle);
                        }
                    }
                }

                // Populate the list with album titles
                browser->populateList(albumTitles);
                return;
            }
        }

    } else {
        // Get the stored current directory location
        QSettings settings("YourCompany", "YourApp");
        QString currentDirectory = settings.value("currentDirectory", QDir::currentPath()).toString();

        // Display the current working directory
        label->setText(currentDirectory);

        // Extract album titles from ALBUM.TXT files in A folders
        QStringList albumTitles;
        for (int i = 1; i <= 9; i++) {
            QString folderPath = currentDirectory + "/A" + QString::number(i);
            if (QDir(folderPath).exists()) {
                QString albumFilePath = folderPath + "/ALBUM.TXT";
                if (QFile::exists(albumFilePath)) {
                    QFile albumFile(albumFilePath);
                    albumFile.open(QIODevice::ReadOnly);
                    QJsonDocument jsonDoc = QJsonDocument::fromJson(albumFile.readAll());
                    albumFile.close();

                    QJsonObject albumObject = jsonDoc.object();
                    QString albumTitle = albumObject.value("title").toString();
                    albumTitles.append(albumTitle);
                }
            }
        }

        // Populate the list with album titles
        browser->populateList(albumTitles);
    }
}

void openFolder(QLabel *label, QMainWindow *mainWindow, Browser *browser) {
    QString folderPath = QFileDialog::getExistingDirectory(mainWindow, "Open Folder");
    if (!folderPath.isEmpty()) {
        label->setText(folderPath);

        // Store the current directory location
        QSettings settings("YourCompany", "YourApp");
        settings.setValue("currentDirectory", folderPath);

        // Extract album titles from ALBUM.TXT files in A folders
        QStringList albumTitles;
        for (int i = 1; i <= 9; i++) {
            QString folderPathA = folderPath + "/A" + QString::number(i);
            if (QDir(folderPathA).exists()) {
                QString albumFilePath = folderPathA + "/ALBUM.TXT";
                if (QFile::exists(albumFilePath)) {
                    QFile albumFile(albumFilePath);
                    albumFile.open(QIODevice::ReadOnly);
                    QJsonDocument jsonDoc = QJsonDocument::fromJson(albumFile.readAll());
                    albumFile.close();

                    QJsonObject albumObject = jsonDoc.object();
                    QString albumTitle = albumObject.value("title").toString();
                    albumTitles.append(albumTitle);
                }
            }
        }

        // Populate the list with album titles
        browser->populateList(albumTitles);
    }
}
