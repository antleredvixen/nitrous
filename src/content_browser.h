// content_browser.h
#ifndef CONTENT_BROWSER_H
#define CONTENT_BROWSER_H

#include <QWidget>
#include <QListWidget>
#include <QVBoxLayout>
#include <QDir>

class ContentBrowser : public QWidget
{
    Q_OBJECT

public:
    ContentBrowser(QWidget *parent = nullptr);
    void populateList(const QString &directory);

private:
    QListWidget *listWidget;
};

#endif // CONTENT_BROWSER_H
