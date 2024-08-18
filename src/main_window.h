// mainwindow.h
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDateTime>
#include <QTextEdit>
#include <QTimer>
#include <QStorageInfo>
#include <QLabel>
#include "status_display.h"
#include "device_connection.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void deviceConnection();

private:
    Ui::MainWindow *ui;
    QTextEdit *consoleWindow;
    QTimer timer;
    bool connectionStatus;
    QLabel *currentDirectoryLabel;
    StatusDisplay *deviceGraphic;
    DeviceConnection scan;
};

#endif // MAINWINDOW_H
