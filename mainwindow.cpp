#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "statuswidget.h"
#include <QVBoxLayout>
#include <QHBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Create the StatusWidget
    StatusWidget *statusWidget = new StatusWidget(this);

    // Create a vertical layout for the central widget
    QVBoxLayout *vboxLayout = new QVBoxLayout(ui->centralwidget);

    // Create a horizontal layout for the bottom row
    QHBoxLayout *hboxLayout = new QHBoxLayout;

    // Add the horizontal layout to the vertical layout
    vboxLayout->addStretch(); // Pushes the widget to the bottom
    vboxLayout->addLayout(hboxLayout);

    // Add the status widget to the horizontal layout
    hboxLayout->addWidget(statusWidget);
    hboxLayout->addStretch(); // Pushes the widget to the left
}

MainWindow::~MainWindow()
{
    delete ui;
}
