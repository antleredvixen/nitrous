// about_window.h
#ifndef ABOUT_WINDOW_H
#define ABOUT_WINDOW_H

#include <QDialog>
#include <QTabWidget>
#include <QLabel>
#include <QTextEdit>
#include <QPixmap>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFile>
#include <QTextStream>

class AboutWindow : public QDialog
{
    Q_OBJECT

public:
    AboutWindow(QWidget *parent = nullptr);
    ~AboutWindow();

private:
    QTabWidget *tabWidget;
    QWidget *versionTab;
    QWidget *legalTab;
    QLabel *versionImage;
    QLabel *versionLabel;
    QLabel *aboutLabel;
    QLabel *copyrightLabel;
    QLabel *disclaimerLabel;
    QTextEdit *legalText;
};

#endif // ABOUT_WINDOW_H
