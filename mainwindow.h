#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>
#include <QTimer>
#include <QStorageInfo>

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
    void checkForStemPlayer();

private:
    Ui::MainWindow *ui;
    QTextEdit *consoleWindow;
    QTimer timer;
    bool stemPlayerConnected;
    void checkStemPlayerConnection();
};

#endif // MAINWINDOW_H
