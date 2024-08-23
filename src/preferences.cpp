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

    // Load the previously applied color option
    QSettings settings("antleredvixen", "Nitrous");
    int previousOption = settings.value("colorOption", 0).toInt();
    comboBox->setCurrentIndex(previousOption);

    applyButton = new QPushButton("Apply");
    okButton = new QPushButton("OK");
    cancelButton = new QPushButton("Cancel");

    // Disable the Apply button if the current index matches the previous option
    applyButton->setEnabled(comboBox->currentIndex() != previousOption);
    applyButton->setFocusPolicy(Qt::NoFocus);
    cancelButton->setFocusPolicy(Qt::NoFocus);
    okButton->setFocusPolicy(Qt::NoFocus);

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
        QSettings settings("antleredvixen", "Nitrous");
        int previousOption = settings.value("colorOption", 0).toInt();
        applyButton->setEnabled(comboBox->currentIndex() != previousOption);
    });
}

void Preferences::applyChanges()
{
    int index = comboBox->currentIndex();
    Status::ColorOption option = static_cast<Status::ColorOption>(index);
    mStatus->setColorOption(option);

    // The setColorOption method now handles saving the setting

    applyButton->setEnabled(false);
}

void Preferences::okButtonClicked()
{
    applyChanges();
    accept();
}
