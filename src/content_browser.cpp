// content_browser.cpp
#include "content_browser.h"

ContentBrowser::ContentBrowser(QWidget *parent) : QWidget(parent)
{
    listWidget = new QListWidget(this);
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(listWidget);
    setLayout(layout);
}

void ContentBrowser::populateList(const QString &directory)
{
    QDir dir(directory);
    dir.setFilter(QDir::Dirs | QDir::NoDotAndDotDot);
    listWidget->clear();
    foreach (const QFileInfo &file, dir.entryInfoList()) {
        listWidget->addItem(file.fileName());
    }
}
