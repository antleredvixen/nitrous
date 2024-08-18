#include "about_window.h"

AboutWindow::AboutWindow(QWidget *parent) :
    QDialog(parent)
{
    setWindowTitle("About Nitrous");
    setWindowIcon(QIcon());

    QVBoxLayout *mainLayout = new QVBoxLayout;
    setLayout(mainLayout);

    tabWidget = new QTabWidget;
    mainLayout->addWidget(tabWidget);

    // Nitrous tab
    nitrousTab = new QWidget;
    tabWidget->addTab(nitrousTab, "Nitrous");

    QVBoxLayout *nitrousLayout = new QVBoxLayout;
    nitrousTab->setLayout(nitrousLayout);

    nitrousImage = new QLabel;
    nitrousImage->setPixmap(QPixmap(":/images/nitrous.png"));
    nitrousLayout->addWidget(nitrousImage);

    nitrousHeading = new QLabel("Nitrous alpha_0.5");
    nitrousLayout->addWidget(nitrousHeading);

    nitrousLabel = new QLabel("Nitrous is a device content manager for Kano Stem Player written in C++ using Qt.");
    nitrousLayout->addWidget(nitrousLabel);

    nitrousLabel = new QLabel("Copyright © 2024 Katherine North");
    nitrousLayout->addWidget(nitrousLabel);

    // Legal tab
    legalTab = new QWidget;
    tabWidget->addTab(legalTab, "Legal");

    QVBoxLayout *legalLayout = new QVBoxLayout;
    legalTab->setLayout(legalLayout);

    legalText = new QTextEdit;
    legalText->setReadOnly(true);
    legalLayout->addWidget(legalText);

    // Load LGPL license text
    QFile licenseFile(":/licenses/lgpl.txt");
    if (licenseFile.open(QFile::ReadOnly)) {
        QTextStream in(&licenseFile);
        legalText->setText(in.readAll());
        licenseFile.close();
    }
}

AboutWindow::~AboutWindow()
{
}
