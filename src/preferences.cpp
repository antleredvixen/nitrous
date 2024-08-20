// preferences.cpp
#include "preferences.h"

Preferences::Preferences(Status *status, QWidget *parent) : QDialog(parent)
{
    mStatus = status;
    setWindowTitle("Preferences");

    label = new QLabel("Status Color: ");
    QFont font = label->font();
    font.setBold(true);
    label->setFont(font);

    comboBox = new QComboBox;
    comboBox->setFixedWidth(100);
    comboBox->addItem("Tan");
    comboBox->addItem("Green");
    comboBox->addItem("Clear");
    comboBox->addItem("Black");

    // Load the previously applied color index
    QSettings settings("YourCompany", "YourApp");
    int previousIndex = settings.value("colorIndex", 0).toInt();
    comboBox->setCurrentIndex(previousIndex);

    applyButton = new QPushButton("Apply");
    okButton = new QPushButton("OK");
    cancelButton = new QPushButton("Cancel");

    // Disable the Apply button if the current index matches the previous index
    applyButton->setEnabled(comboBox->currentIndex()!= previousIndex);

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
        QSettings settings("YourCompany", "YourApp");
        int previousIndex = settings.value("colorIndex", 0).toInt();
        applyButton->setEnabled(comboBox->currentIndex()!= previousIndex);
    });
}

void Preferences::applyChanges()
{
    int index = comboBox->currentIndex();
    switch (index) {
    case 0:
        mStatus->setColorOption(Status::ColorOption::Tan);
        break;
    case 1:
        mStatus->setColorOption(Status::ColorOption::Green);
        break;
    case 2:
        mStatus->setColorOption(Status::ColorOption::Clear);
        break;
    case 3:
        mStatus->setColorOption(Status::ColorOption::Black);
        break;
    }

    // Save the current color index
    QSettings settings("YourCompany", "YourApp");
    settings.setValue("colorIndex", index);

    applyButton->setEnabled(false);
}

void Preferences::okButtonClicked()
{
    applyChanges();
    accept();
}
