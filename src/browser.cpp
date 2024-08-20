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
}

void Browser::populateList(const QStringList &albumTitles)
{
    listWidget->clear();
    foreach (const QString &title, albumTitles) {
        listWidget->addItem(title);
    }
}

void Browser::handleItemDoubleClick(QListWidgetItem *item)
{
    QString itemName = item->text();
    if (itemName == "Back") {
        emit backClicked();
    } else {
        // Get the album index from the list item
        int albumIndex = listWidget->row(item) + 1;

        QString timestamp = QDateTime::currentDateTime().toString("[yyyy-MM-dd HH:mm:ss] ");
        console->appendText(timestamp + "Album index: " + QString::number(albumIndex));

        if (albumIndex > 0) {
            // Get the current directory from the currentDirectoryLabel
            QString currentDirectory = currentDirectoryLabel->text();

            // Get the track titles from the TRACK.TXT files in the T[i] folders
            QStringList trackTitles;
            for (int i = 1; i <= 30; i++) {
                QString folderPath = currentDirectory + "/A" + QString::number(albumIndex) + "/T" + QString::number(i);
                timestamp = QDateTime::currentDateTime().toString("[yyyy-MM-dd HH:mm:ss] ");
                console->appendText(timestamp + "Checking folder: " + folderPath);
                if (QDir(folderPath).exists()) {
                    timestamp = QDateTime::currentDateTime().toString("[yyyy-MM-dd HH:mm:ss] ");
                    console->appendText(timestamp + "Folder exists!");
                    QString trackFilePath = folderPath + "/TRACK.TXT";
                    timestamp = QDateTime::currentDateTime().toString("[yyyy-MM-dd HH:mm:ss] ");
                    console->appendText(timestamp + "Checking file: " + trackFilePath);
                    if (QFile::exists(trackFilePath)) {
                        timestamp = QDateTime::currentDateTime().toString("[yyyy-MM-dd HH:mm:ss] ");
                        console->appendText(timestamp + "File exists!");
                        QFile trackFile(trackFilePath);
                        trackFile.open(QIODevice::ReadOnly);
                        QJsonDocument jsonDoc = QJsonDocument::fromJson(trackFile.readAll());
                        trackFile.close();

                        QJsonObject trackObject = jsonDoc.object();
                        QJsonObject metadata = trackObject.value("metadata").toObject();
                        QString trackTitle = metadata.value("title").toString();
                        trackTitles.append(trackTitle);
                        timestamp = QDateTime::currentDateTime().toString("[yyyy-MM-dd HH:mm:ss] ");
                        console->appendText(timestamp + "Added track title: " + trackTitle);
                    } else {
                        timestamp = QDateTime::currentDateTime().toString("[yyyy-MM-dd HH:mm:ss] ");
                        console->appendText(timestamp + "File does not exist!");
                    }
                } else {
                    timestamp = QDateTime::currentDateTime().toString("[yyyy-MM-dd HH:mm:ss] ");
                    console->appendText(timestamp + "Folder does not exist!");
                }
            }

            timestamp = QDateTime::currentDateTime().toString("[yyyy-MM-dd HH:mm:ss] ");
            console->appendText(timestamp + "Track titles: " + trackTitles.join(", "));

            // Add the "Back" item to the track titles
            trackTitles.prepend("Back");

            // Repopulate the list with the track titles
            populateList(trackTitles);
        }
    }
}
