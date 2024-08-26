// config.cpp
#include "config.h"
#include "config_load.h"
#include "config_save.h"
#include "config_update.h"
#include <QGridLayout>
#include <QLabel>
#include <QFile>

Config::Config(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *mainLayout = new QVBoxLayout;

    // Add the Configuration label
    QLabel *configLabel = new QLabel("<b>Configuration</b>");
    mainLayout->addWidget(configLabel, 0, Qt::AlignLeft);

    // Name
    QHBoxLayout *nameLayout = new QHBoxLayout;
    nameLayout->addWidget(new QLabel("Name:"));
    nameLineEdit = new QLineEdit;
    nameLineEdit->setFixedWidth(150);
    nameLayout->addWidget(nameLineEdit);
    nameLayout->addStretch();
    mainLayout->addLayout(nameLayout);

    QGridLayout *gridLayout = new QGridLayout;
    gridLayout->setColumnStretch(0, 1);  // Left column
    gridLayout->setColumnStretch(1, 0);  // Left column input
    gridLayout->setColumnStretch(2, 1);  // Spacer
    gridLayout->setColumnStretch(3, 1);  // Right column
    gridLayout->setColumnStretch(4, 0);  // Right column input
    gridLayout->setHorizontalSpacing(10);

    // Left Column
    int row = 0;

    // Seek Jump Period
    gridLayout->addWidget(new QLabel("Seek Jump Period:"), row, 0, Qt::AlignRight);
    QHBoxLayout *seekJumpLayout = new QHBoxLayout;
    seekJumpPeriodSpinBox = new QSpinBox;
    seekJumpPeriodSpinBox->setMaximum(9999);
    seekJumpPeriodSpinBox->setFixedWidth(50);
    seekJumpPeriodSpinBox->setAlignment(Qt::AlignRight);
    seekJumpLayout->addWidget(seekJumpPeriodSpinBox);
    seekJumpLayout->addWidget(new QLabel("ms"));
    seekJumpLayout->addStretch();
    gridLayout->addLayout(seekJumpLayout, row, 1);
    row++;

    // Seek Buffers To Play
    gridLayout->addWidget(new QLabel("Seek Buffers To Play:"), row, 0, Qt::AlignRight);
    seekBuffersToPlaySpinBox = new QSpinBox;
    seekBuffersToPlaySpinBox->setFixedWidth(50);
    seekBuffersToPlaySpinBox->setAlignment(Qt::AlignRight);
    gridLayout->addWidget(seekBuffersToPlaySpinBox, row, 1);
    row++;

    // Isolation Ramp Period
    gridLayout->addWidget(new QLabel("Isolation Ramp Period:"), row, 0, Qt::AlignRight);
    QHBoxLayout *isolationRampLayout = new QHBoxLayout;
    isolationRampPeriodSpinBox = new QSpinBox;
    isolationRampPeriodSpinBox->setFixedWidth(50);
    isolationRampPeriodSpinBox->setAlignment(Qt::AlignRight);
    isolationRampLayout->addWidget(isolationRampPeriodSpinBox);
    isolationRampLayout->addWidget(new QLabel("ms"));
    isolationRampLayout->addStretch();
    gridLayout->addLayout(isolationRampLayout, row, 1);
    row++;

    // Isolation Hit Box Size
    gridLayout->addWidget(new QLabel("Isolation Hit Box Size:"), row, 0, Qt::AlignRight);
    isolationHitBoxSizeSpinBox = new QSpinBox;
    isolationHitBoxSizeSpinBox->setFixedWidth(50);
    isolationHitBoxSizeSpinBox->setAlignment(Qt::AlignRight);
    gridLayout->addWidget(isolationHitBoxSizeSpinBox, row, 1);

    // Right Column
    row = 0;

    // Min Stem Background Level
    gridLayout->addWidget(new QLabel("Min Stem Background Level:"), row, 3, Qt::AlignRight);
    minStemBackgroundLevelSpinBox = new QSpinBox;
    minStemBackgroundLevelSpinBox->setMaximum(9999);
    minStemBackgroundLevelSpinBox->setFixedWidth(50);
    minStemBackgroundLevelSpinBox->setAlignment(Qt::AlignRight);
    gridLayout->addWidget(minStemBackgroundLevelSpinBox, row, 4);
    row++;

    // Fast 2 Play
    gridLayout->addWidget(new QLabel("Fast 2 Play:"), row, 3, Qt::AlignRight);
    fast2playDoubleSpinBox = new QDoubleSpinBox;
    fast2playDoubleSpinBox->setFixedWidth(50);
    fast2playDoubleSpinBox->setAlignment(Qt::AlignRight);
    gridLayout->addWidget(fast2playDoubleSpinBox, row, 4);
    row++;

    // Fast 1 Play
    gridLayout->addWidget(new QLabel("Fast 1 Play:"), row, 3, Qt::AlignRight);
    fast1playDoubleSpinBox = new QDoubleSpinBox;
    fast1playDoubleSpinBox->setFixedWidth(50);
    fast1playDoubleSpinBox->setAlignment(Qt::AlignRight);
    gridLayout->addWidget(fast1playDoubleSpinBox, row, 4);
    row++;

    // Slow 1 Play
    gridLayout->addWidget(new QLabel("Slow 1 Play:"), row, 3, Qt::AlignRight);
    slow1playDoubleSpinBox = new QDoubleSpinBox;
    slow1playDoubleSpinBox->setFixedWidth(50);
    slow1playDoubleSpinBox->setAlignment(Qt::AlignRight);
    gridLayout->addWidget(slow1playDoubleSpinBox, row, 4);
    row++;

    // Record Period
    gridLayout->addWidget(new QLabel("Record Period:"), row, 3, Qt::AlignRight);
    recordPeriodSpinBox = new QSpinBox;
    recordPeriodSpinBox->setFixedWidth(50);
    recordPeriodSpinBox->setAlignment(Qt::AlignRight);
    gridLayout->addWidget(recordPeriodSpinBox, row, 4);

    mainLayout->addLayout(gridLayout);

    applyButton = new QPushButton("Apply");
    okButton = new QPushButton("OK");

    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addStretch();
    okButton->setFixedWidth(80);
    applyButton->setFixedWidth(80);
    buttonLayout->addWidget(okButton);
    buttonLayout->addWidget(applyButton);

    QVBoxLayout *mainVBoxLayout = new QVBoxLayout;
    mainVBoxLayout->addLayout(mainLayout);
    mainVBoxLayout->addStretch();
    mainVBoxLayout->addLayout(buttonLayout);

    setLayout(mainVBoxLayout);

    connect(applyButton, &QPushButton::clicked, this, &Config::onApplyClicked);
    connect(okButton, &QPushButton::clicked, this, &Config::onOkClicked);
}

Config::~Config()
{
}

void Config::updateCurrentDirectory(const QString &path)
{
    m_currentDirectory = path;
    loadConfig();
}

void Config::onApplyClicked()
{
    ConfigUpdate update;
    update.updateConfigFromUI(m_configData, nameLineEdit, seekJumpPeriodSpinBox,
                              seekBuffersToPlaySpinBox, isolationRampPeriodSpinBox,
                              isolationHitBoxSizeSpinBox, minStemBackgroundLevelSpinBox,
                              fast2playDoubleSpinBox, fast1playDoubleSpinBox,
                              slow1playDoubleSpinBox, recordPeriodSpinBox);
    ConfigSave::saveConfig(m_configData);
}

void Config::onOkClicked()
{
    onApplyClicked();
    close();
}

void Config::loadConfig()
{
    QString configFilePath = m_currentDirectory + "/CONFIG.TXT";
    if (QFile::exists(configFilePath)) {
        if (ConfigLoad::loadConfig(m_configData, m_currentDirectory)) {
            ConfigUpdate update;
            update.updateUIFromConfig(m_configData, nameLineEdit, seekJumpPeriodSpinBox,
                                      seekBuffersToPlaySpinBox, isolationRampPeriodSpinBox,
                                      isolationHitBoxSizeSpinBox, minStemBackgroundLevelSpinBox,
                                      fast2playDoubleSpinBox, fast1playDoubleSpinBox,
                                      slow1playDoubleSpinBox, recordPeriodSpinBox);
        }
    } else {
        clearConfigForm();
    }
}

void Config::clearConfigForm()
{
    nameLineEdit->clear();
    seekJumpPeriodSpinBox->setValue(0);
    seekBuffersToPlaySpinBox->setValue(0);
    isolationRampPeriodSpinBox->setValue(0);
    isolationHitBoxSizeSpinBox->setValue(0);
    minStemBackgroundLevelSpinBox->setValue(0);
    fast2playDoubleSpinBox->setValue(0.0);
    fast1playDoubleSpinBox->setValue(0.0);
    slow1playDoubleSpinBox->setValue(0.0);
    recordPeriodSpinBox->setValue(0);
}
