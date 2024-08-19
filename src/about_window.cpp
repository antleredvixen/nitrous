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

    nitrousLabel = new QLabel("A content manager for the Stem Player written in C++ using Qt.");
    nitrousLayout->addWidget(nitrousLabel);

    copyrightLabel = new QLabel("Copyright © 2024 Katherine North");
    nitrousLayout->addWidget(copyrightLabel);

    disclaimerLabel = new QLabel("DISCLAIMER: THIS TOOL IS AN INDEPENDENT PROJECT AND IS NOT AFFILIATED WITH, ENDORSED BY, OR ASSOCIATED WITH KANO COMPUTING OR YEEZY TECH. ALL TRADEMARKS AND PRODUCT NAMES ARE THE PROPERTY OF THEIR RESPECTIVE OWNERS.");
    disclaimerLabel->setWordWrap(true);
    nitrousLayout->addWidget(disclaimerLabel);

    // Legal tab
    legalTab = new QWidget;
    tabWidget->addTab(legalTab, "Legal");

    QVBoxLayout *legalLayout = new QVBoxLayout;
    legalTab->setLayout(legalLayout);

    legalText = new QTextEdit;
    legalText->setReadOnly(true);
    legalLayout->addWidget(legalText);

    // Load MIT license text
    QFile licenseFile(":/LICENSE");
    if (licenseFile.open(QFile::ReadOnly)) {
        QTextStream in(&licenseFile);
        legalText->setText(in.readAll());
        licenseFile.close();
    }
}

AboutWindow::~AboutWindow()
{
}
