// about.h
#ifndef ABOUT_H
#define ABOUT_H

#include <QDialog>
#include <QTabWidget>
#include <QLabel>
#include <QTextEdit>
#include <QPixmap>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFile>
#include <QTextStream>
#include <QPushButton>

class About : public QDialog
{
    Q_OBJECT

public:
    About(QWidget *parent = nullptr);
    ~About();

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

#endif // ABOUT_H
