// preferences.cpp
#include "preferences.h"

Preferences::Preferences(QWidget *parent) : QDialog(parent)
{
    setWindowTitle("Preferences");

    label = new QLabel("Device Color: ");
    QFont font = label->font();
    font.setBold(true);
    label->setFont(font);

    comboBox = new QComboBox;
    comboBox->setFixedWidth(100); // Set the width of the dropdown to 100 pixels
    comboBox->addItem("Tan");
    comboBox->addItem("Green");
    comboBox->addItem("Clear");
    comboBox->addItem("Black");

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addStretch();
    layout->addWidget(label);
    layout->addWidget(comboBox);
    layout->addStretch();

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addStretch();
    mainLayout->addLayout(layout);
    mainLayout->addStretch();

    setLayout(mainLayout);
    setFixedSize(300, 100);
}
