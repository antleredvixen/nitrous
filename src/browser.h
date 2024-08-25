// browser.h
#ifndef BROWSER_H
#define BROWSER_H

#include <QWidget>
#include <QListWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QDir>
#include "console.h"
#include "config.h"

class Browser : public QWidget
{
    Q_OBJECT

public:
    Browser(Console *console, QLabel *currentDirectoryLabel, Config *configForm, QWidget *parent = nullptr);
    void populateList(const QString &directory);

private slots:
    void handleItemDoubleClick(QListWidgetItem *item);

private:
    Console *console;
    QLabel *currentDirectoryLabel;
    QListWidget *listWidget;
    Config *configForm;
};

#endif // BROWSER_H
