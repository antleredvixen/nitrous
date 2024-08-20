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

void directory(QLabel *label, bool connectionStatus, Browser *browser);
QString getCurrentDirectoryLocation();
void openFolder(QLabel *label, QMainWindow *mainWindow, Browser *browser);

#endif // DIRECTORY_H
