// main_window.h
#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

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
#include "content_browser.h"
#include "preferences.h"

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
    void showPreferences();

private:
    Ui::MainWindow *ui;
    QTextEdit *consoleWindow;
    QTimer timer;
    bool connectionStatus;
    QLabel *currentDirectoryLabel;
    StatusDisplay *deviceGraphic;
    DeviceConnection scan;
    ContentBrowser *contentBrowser;
};

#endif // MAIN_WINDOW_H
