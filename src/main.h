// main.h
#ifndef MAIN_H
#define MAIN_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDateTime>
#include <QTimer>
#include <QStorageInfo>
#include <QLabel>
#include "status.h"
#include "connect.h"
#include "browser.h"
#include "about.h"
#include "console.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Main;
}
QT_END_NAMESPACE

class Main : public QMainWindow
{
    Q_OBJECT

public:
    Main(QWidget *parent = nullptr);
    ~Main();

private slots:
    void deviceConnection();
    void showPreferences();
    void showAbout();

private:
    Ui::Main *ui;
    Console *consoleWindow;
    QTimer timer;
    bool connectionStatus;
    QLabel *currentDirectoryLabel;
    Status *deviceGraphic;
    Connect scan;
    Browser *contentBrowser;
    About *aboutWindow;
};

#endif // MAIN_H
