// directory.h
#ifndef DIRECTORY_H
#define DIRECTORY_H

#include <QLabel>
#include <QMainWindow>
#include <QDir>
#include <QStorageInfo>
#include <QFileDialog>
#include <QJsonDocument>
#include <QJsonObject>
#include <QSettings>
#include <QRegularExpression>
#include "browser.h"
#include "config.h"
#include "console.h"

void directory(QLabel *label, bool connectionStatus, Browser *browser, Config *config, Console *console);
QString getCurrentDirectoryLocation();
void openFolder(QLabel *label, QMainWindow *mainWindow, Browser *browser, Config *config, Console *console);
void loadConfig(Config *config, const QString &directory, Console *console);

#endif // DIRECTORY_H
