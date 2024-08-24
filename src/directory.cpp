// directory.cpp
#include "directory.h"
#include "config.h"
#include "config_load.h"
#include "config_update.h"

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
            config->updateCurrentDirectory(directoryPath);

            // Populate the list with the contents of the root directory
            browser->populateList(drive.rootPath());

            // Check if a CONFIG.TXT file is present in the current directory
            QString configFilePath = drive.rootPath() + "/CONFIG.TXT";
            if (QFile::exists(configFilePath)) {
                ConfigData configData;
                if (ConfigLoad::loadConfig(configData)) {
                    ConfigUpdate update;
                    update.updateUIFromConfig(configData, config->getNameLineEdit(), config->getSeekJumpPeriodSpinBox(),
                                              config->getSeekBuffersToPlaySpinBox(), config->getIsolationRampPeriodSpinBox(),
                                              config->getIsolationHitBoxSizeSpinBox(), config->getMinStemBackgroundLevelSpinBox(),
                                              config->getFast2playDoubleSpinBox(), config->getFast1playDoubleSpinBox(),
                                              config->getSlow1playDoubleSpinBox(), config->getRecordPeriodSpinBox());
                }
                config->setVisible(true);
            } else {
                config->setVisible(false);
            }
            return;
        }
    }

    // If no STEM PLAYER drive is found, use the current directory
    QString currentDir = QDir::currentPath();
    label->setText(currentDir);
    browser->populateList(currentDir);

    // Check for CONFIG.TXT in the current directory
    QString configFilePath = currentDir + "/CONFIG.TXT";
    if (QFile::exists(configFilePath)) {
        ConfigData configData;
        if (ConfigLoad::loadConfig(configData)) {
            ConfigUpdate update;
            update.updateUIFromConfig(configData, config->getNameLineEdit(), config->getSeekJumpPeriodSpinBox(),
                                      config->getSeekBuffersToPlaySpinBox(), config->getIsolationRampPeriodSpinBox(),
                                      config->getIsolationHitBoxSizeSpinBox(), config->getMinStemBackgroundLevelSpinBox(),
                                      config->getFast2playDoubleSpinBox(), config->getFast1playDoubleSpinBox(),
                                      config->getSlow1playDoubleSpinBox(), config->getRecordPeriodSpinBox());
        }
        config->setVisible(true);
    } else {
        config->setVisible(false);
    }
}

QString getCurrentDirectoryLocation() {
    return QDir::currentPath();
}

void openFolder(QLabel *label, QMainWindow *mainWindow, Browser *browser, Config *config) {
    QString folderPath = QFileDialog::getExistingDirectory(mainWindow, "Open Folder");
    if (!folderPath.isEmpty()) {
        label->setText(folderPath);
        browser->populateList(folderPath);
        config->updateCurrentDirectory(folderPath);

        // Check if a CONFIG.TXT file is present in the selected directory
        QString configFilePath = folderPath + "/CONFIG.TXT";
        if (QFile::exists(configFilePath)) {
            ConfigData configData;
            if (ConfigLoad::loadConfig(configData)) {
                ConfigUpdate update;
                update.updateUIFromConfig(configData, config->getNameLineEdit(), config->getSeekJumpPeriodSpinBox(),
                                          config->getSeekBuffersToPlaySpinBox(), config->getIsolationRampPeriodSpinBox(),
                                          config->getIsolationHitBoxSizeSpinBox(), config->getMinStemBackgroundLevelSpinBox(),
                                          config->getFast2playDoubleSpinBox(), config->getFast1playDoubleSpinBox(),
                                          config->getSlow1playDoubleSpinBox(), config->getRecordPeriodSpinBox());
            }
            config->setVisible(true);
        } else {
            config->setVisible(false);
        }
    }
}

void loadConfig(Config *config, const QString &filePath) {
    ConfigData configData;
    if (ConfigLoad::loadConfig(configData)) {
        ConfigUpdate update;
        update.updateUIFromConfig(configData, config->getNameLineEdit(), config->getSeekJumpPeriodSpinBox(),
                                  config->getSeekBuffersToPlaySpinBox(), config->getIsolationRampPeriodSpinBox(),
                                  config->getIsolationHitBoxSizeSpinBox(), config->getMinStemBackgroundLevelSpinBox(),
                                  config->getFast2playDoubleSpinBox(), config->getFast1playDoubleSpinBox(),
                                  config->getSlow1playDoubleSpinBox(), config->getRecordPeriodSpinBox());
    }
}
