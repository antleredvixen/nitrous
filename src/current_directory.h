// current_directory.h
#ifndef CURRENT_DIRECTORY_H
#define CURRENT_DIRECTORY_H

#include <QLabel>
#include <QMainWindow>
#include <QDir>
#include <QStorageInfo>
#include <QFileDialog>
#include "content_browser.h"

void currentDirectory(QLabel *label, bool connectionStatus, ContentBrowser *contentBrowser);
void openFolder(QLabel *label, QMainWindow *mainWindow, ContentBrowser *contentBrowser);

#endif // CURRENT_DIRECTORY_H
