// preferences.cpp
#include "preferences.h"

Preferences::Preferences(StatusDisplay* statusDisplay, QWidget *parent) : QDialog(parent)
{
    mStatusDisplay = statusDisplay;
    setWindowTitle("Preferences");

    label = new QLabel("Device Color: ");
    QFont font = label->font();
    font.setBold(true);
    label->setFont(font);

    comboBox = new QComboBox;
    comboBox->setFixedWidth(100);
    comboBox->addItem("Tan");
    comboBox->addItem("Green");
    comboBox->addItem("Clear");
    comboBox->addItem("Black");

    applyButton = new QPushButton("Apply");
    okButton = new QPushButton("OK");
    cancelButton = new QPushButton("Cancel");

    applyButton->setEnabled(false);

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addStretch();
    layout->addWidget(label);
    layout->addWidget(comboBox);
    layout->addStretch();

    QVBoxLayout *vboxLayout = new QVBoxLayout;
    vboxLayout->addStretch();
    vboxLayout->addLayout(layout);
    vboxLayout->addStretch();

    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addStretch();
    buttonLayout->addWidget(okButton);
    buttonLayout->addWidget(cancelButton);
    buttonLayout->addWidget(applyButton);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(vboxLayout);
    mainLayout->addStretch();
    mainLayout->addLayout(buttonLayout);
    mainLayout->setAlignment(buttonLayout, Qt::AlignRight);

    setLayout(mainLayout);
    setFixedSize(300, 150);

    connect(applyButton, &QPushButton::clicked, this, &Preferences::applyChanges);
    connect(okButton, &QPushButton::clicked, this, &Preferences::okButtonClicked);
    connect(cancelButton, &QPushButton::clicked, this, &QDialog::reject);
    connect(comboBox, &QComboBox::currentTextChanged, this, [this]() {
        applyButton->setEnabled(true);
    });
}

void Preferences::applyChanges()
{
    int index = comboBox->currentIndex();
    switch (index) {
    case 0:
        mStatusDisplay->setColorOption(StatusDisplay::ColorOption::Tan);
        break;
    case 1:
        mStatusDisplay->setColorOption(StatusDisplay::ColorOption::Green);
        break;
    case 2:
        mStatusDisplay->setColorOption(StatusDisplay::ColorOption::Clear);
        break;
    case 3:
        mStatusDisplay->setColorOption(StatusDisplay::ColorOption::Black);
        break;
    }
    applyButton->setEnabled(false);
}

void Preferences::okButtonClicked()
{
    applyChanges();
    accept();
}
