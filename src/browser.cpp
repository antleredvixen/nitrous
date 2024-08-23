// browser.cpp
#include "browser.h"

Browser::Browser(Console *console, QLabel *currentDirectoryLabel, QWidget *parent) : QWidget(parent)
{
    this->console = console;
    this->currentDirectoryLabel = currentDirectoryLabel;

    listWidget = new QListWidget(this);

    // Create a label to display "Browser"
    QLabel *browserLabel = new QLabel("<b>Browser</b>", this);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(browserLabel); // Add the label to the layout
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
    QFileInfoList fileInfoList = dir.entryInfoList();
    // Custom sorting function to prioritize numerical order
    static QRegularExpression regExp("([A-Za-z]+)(\\d+)");
    std::sort(fileInfoList.begin(), fileInfoList.end(), [](const QFileInfo &a, const QFileInfo &b) {
        QString aName = a.fileName();
        QString bName = b.fileName();
        QRegularExpressionMatch matchA = regExp.match(aName);
        QRegularExpressionMatch matchB = regExp.match(bName);
        if (matchA.hasMatch() && matchB.hasMatch()) {
            int aNumber = matchA.captured(2).toInt();
            int bNumber = matchB.captured(2).toInt();
            if (aName.startsWith(matchA.captured(1)) && bName.startsWith(matchB.captured(1))) {
                return aNumber < bNumber;
            }
        }
        return QString::localeAwareCompare(aName, bName) < 0;
    });
    foreach (const QFileInfo &file, fileInfoList) {
        listWidget->addItem(file.fileName());
    }

    // Check if the current directory is the root directory
    QString rootPath = dir.absolutePath();
    if (rootPath.length() > 3) {
        listWidget->insertItem(0, ".."); // Add a ".." item to navigate up
    }

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
