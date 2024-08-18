// current_directory.h
#ifndef CURRENT_DIRECTORY_H
#define CURRENT_DIRECTORY_H

#include <QLabel>
#include <QMainWindow>
#include <QDir>
#include <QStorageInfo>
#include <QFileDialog>

void currentDirectory(QLabel *label, bool connectionStatus);
void openFolder(QLabel *label, QMainWindow *mainWindow);

#endif // CURRENT_DIRECTORY_H
