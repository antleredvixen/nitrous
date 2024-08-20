// browser.h
#ifndef BROWSER_H
#define BROWSER_H

#include <QWidget>
#include <QListWidget>
#include <QVBoxLayout>
#include <QDir>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QLabel>
#include "console.h"

class Browser : public QWidget
{
    Q_OBJECT

public:
    Browser(Console *console, QLabel *currentDirectoryLabel, QWidget *parent = nullptr);
    void populateList(const QString &directory);
    void populateList(const QStringList &albumTitles);

signals:
    void backClicked();

private slots:
    void handleItemDoubleClick(QListWidgetItem *item);

private:
    QListWidget *listWidget;
    Console *console;
    QLabel *currentDirectoryLabel;
};

#endif // BROWSER_H
