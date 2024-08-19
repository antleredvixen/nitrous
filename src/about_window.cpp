#include "about_window.h"

AboutWindow::AboutWindow(QWidget *parent) : QDialog(parent)
{
    setWindowTitle("About");

    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    tabWidget = new QTabWidget;
    mainLayout->addWidget(tabWidget);

    // Version tab
    versionTab = new QWidget;
    tabWidget->addTab(versionTab, "Version");
    QVBoxLayout *versionLayout = new QVBoxLayout(versionTab);

    QWidget *topContainer = new QWidget;
    QHBoxLayout *topLayout = new QHBoxLayout(topContainer);
    versionLayout->addWidget(topContainer);

    topLayout->addStretch();

    versionImage = new QLabel;
    QPixmap pixmap(":/nitrous.png");
    if (!pixmap.isNull()) {
        versionImage->setPixmap(pixmap.scaled(50, 50, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    } else {
        qDebug() << "Failed to load image";
        versionImage->setText("Image not found");
    }
    topLayout->addWidget(versionImage);

    versionLabel = new QLabel("Nitrous 0.5");
    versionLabel->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    versionLabel->setStyleSheet("font-size: 18pt; font-weight: bold; margin-left: 10px;");
    topLayout->addWidget(versionLabel);

    topLayout->addStretch();

    QWidget *bottomContainer = new QWidget;
    QVBoxLayout *bottomLayout = new QVBoxLayout(bottomContainer);
    versionLayout->addWidget(bottomContainer);

    aboutLabel = new QLabel("A content manager for the Stem Player\n written in C++ using Qt.");
    aboutLabel->setAlignment(Qt::AlignCenter);
    aboutLabel->setWordWrap(true);
    bottomLayout->addWidget(aboutLabel);

    copyrightLabel = new QLabel("© 2024 Katherine North");
    copyrightLabel->setAlignment(Qt::AlignCenter);
    bottomLayout->addWidget(copyrightLabel);

    // Legal tab
    legalTab = new QWidget;
    tabWidget->addTab(legalTab, "Legal");
    QVBoxLayout *legalLayout = new QVBoxLayout(legalTab);

    legalText = new QTextEdit;
    legalText->setReadOnly(true);
    legalLayout->addWidget(legalText);

    // Load MIT license text and disclaimer
    QFile licenseFile(":/LICENSE");
    if (licenseFile.open(QFile::ReadOnly)) {
        QTextStream in(&licenseFile);
        QString licenseText = in.readAll();
        licenseFile.close();

        QStringList lines = licenseText.split("\n");
        lines.removeFirst();
        lines.removeFirst();
        licenseText = lines.join("<br>");

        QString disclaimerText = "THIS TOOL IS AN INDEPENDENT PROJECT AND IS NOT AFFILIATED WITH, ENDORSED BY, OR ASSOCIATED WITH KANO COMPUTING OR YEEZY TECH. ALL TRADEMARKS AND PRODUCT NAMES ARE THE PROPERTY OF THEIR RESPECTIVE OWNERS.";
        QString formattedText = QString("<h2 style='text-align: center; margin-bottom: 10px;'>DISCLAIMER</h2>") +
                                QString("<p>") + disclaimerText + QString("</p>") +
                                QString("<h2 style='text-align: center; margin-top: 10px; margin-bottom: 10px;'>MIT License</h2>") +
                                QString("<p>") + licenseText + QString("</p>");

        legalText->setHtml(formattedText);
    } else {
        qDebug() << "Failed to open LICENSE file";
        legalText->setText("License information not available.");
    }
}

AboutWindow::~AboutWindow()
{
}
