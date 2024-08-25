// config.cpp
#include "config.h"
#include "config_load.h"
#include "config_save.h"
#include "config_update.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QFile>

Config::Config(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *mainLayout = new QVBoxLayout;

    // Add the Configuration label
    QLabel *configLabel = new QLabel("<b>Configuration</b>");
    mainLayout->addWidget(configLabel, 0, Qt::AlignLeft);

    QHBoxLayout *columnLayout = new QHBoxLayout;

    QVBoxLayout *leftColumn = new QVBoxLayout;
    QVBoxLayout *rightColumn = new QVBoxLayout;

    QHBoxLayout *nameLayout = new QHBoxLayout;
    QLabel *nameLabel = new QLabel("Name:");
    nameLabel->setAlignment(Qt::AlignRight);
    nameLayout->addWidget(nameLabel);
    nameLayout->addWidget(nameLineEdit = new QLineEdit);
    nameLineEdit->setFixedWidth(150);
    leftColumn->addLayout(nameLayout);

    QHBoxLayout *seekJumpPeriodLayout = new QHBoxLayout;
    QLabel *seekJumpPeriodLabel = new QLabel("Seek Jump Period:");
    seekJumpPeriodLabel->setAlignment(Qt::AlignRight);
    seekJumpPeriodLayout->addWidget(seekJumpPeriodLabel);
    seekJumpPeriodLayout->addWidget(seekJumpPeriodSpinBox = new QSpinBox);
    seekJumpPeriodSpinBox->setFixedWidth(50);
    leftColumn->addLayout(seekJumpPeriodLayout);

    QHBoxLayout *seekBuffersToPlayLayout = new QHBoxLayout;
    QLabel *seekBuffersToPlayLabel = new QLabel("Seek Buffers To Play:");
    seekBuffersToPlayLabel->setAlignment(Qt::AlignRight);
    seekBuffersToPlayLayout->addWidget(seekBuffersToPlayLabel);
    seekBuffersToPlayLayout->addWidget(seekBuffersToPlaySpinBox = new QSpinBox);
    seekBuffersToPlaySpinBox->setFixedWidth(50);
    leftColumn->addLayout(seekBuffersToPlayLayout);

    QHBoxLayout *isolationRampPeriodLayout = new QHBoxLayout;
    QLabel *isolationRampPeriodLabel = new QLabel("Isolation Ramp Period:");
    isolationRampPeriodLabel->setAlignment(Qt::AlignRight);
    isolationRampPeriodLayout->addWidget(isolationRampPeriodLabel);
    isolationRampPeriodLayout->addWidget(isolationRampPeriodSpinBox = new QSpinBox);
    isolationRampPeriodSpinBox->setFixedWidth(50);
    leftColumn->addLayout(isolationRampPeriodLayout);

    QHBoxLayout *isolationHitBoxSizeLayout = new QHBoxLayout;
    QLabel *isolationHitBoxSizeLabel = new QLabel("Isolation Hit Box Size:");
    isolationHitBoxSizeLabel->setAlignment(Qt::AlignRight);
    isolationHitBoxSizeLayout->addWidget(isolationHitBoxSizeLabel);
    isolationHitBoxSizeLayout->addWidget(isolationHitBoxSizeSpinBox = new QSpinBox);
    isolationHitBoxSizeSpinBox->setFixedWidth(50);
    leftColumn->addLayout(isolationHitBoxSizeLayout);

    QHBoxLayout *minStemBackgroundLevelLayout = new QHBoxLayout;
    QLabel *minStemBackgroundLevelLabel = new QLabel("Min Stem Background Level:");
    minStemBackgroundLevelLabel->setAlignment(Qt::AlignRight);
    minStemBackgroundLevelLayout->addWidget(minStemBackgroundLevelLabel);
    minStemBackgroundLevelLayout->addWidget(minStemBackgroundLevelSpinBox = new QSpinBox);
    minStemBackgroundLevelSpinBox->setFixedWidth(50);
    rightColumn->addLayout(minStemBackgroundLevelLayout);

    QHBoxLayout *fast2playLayout = new QHBoxLayout;
    QLabel *fast2playLabel = new QLabel("Fast 2 Play:");
    fast2playLabel->setAlignment(Qt::AlignRight);
    fast2playLayout->addWidget(fast2playLabel);
    fast2playLayout->addWidget(fast2playDoubleSpinBox = new QDoubleSpinBox);
    fast2playDoubleSpinBox->setFixedWidth(50);
    rightColumn->addLayout(fast2playLayout);

    QHBoxLayout *fast1playLayout = new QHBoxLayout;
    QLabel *fast1playLabel = new QLabel("Fast 1 Play:");
    fast1playLabel->setAlignment(Qt::AlignRight);
    fast1playLayout->addWidget(fast1playLabel);
    fast1playLayout->addWidget(fast1playDoubleSpinBox = new QDoubleSpinBox);
    fast1playDoubleSpinBox->setFixedWidth(50);
    rightColumn->addLayout(fast1playLayout);

    QHBoxLayout *slow1playLayout = new QHBoxLayout;
    QLabel *slow1playLabel = new QLabel("Slow 1 Play:");
    slow1playLabel->setAlignment(Qt::AlignRight);
    slow1playLayout->addWidget(slow1playLabel);
    slow1playLayout->addWidget(slow1playDoubleSpinBox = new QDoubleSpinBox);
    slow1playDoubleSpinBox->setFixedWidth(50);
    rightColumn->addLayout(slow1playLayout);

    QHBoxLayout *recordPeriodLayout = new QHBoxLayout;
    QLabel *recordPeriodLabel = new QLabel("Record Period:");
    recordPeriodLabel->setAlignment(Qt::AlignRight);
    recordPeriodLayout->addWidget(recordPeriodLabel);
    recordPeriodLayout->addWidget(recordPeriodSpinBox = new QSpinBox);
    recordPeriodSpinBox->setFixedWidth(50);
    rightColumn->addLayout(recordPeriodLayout);

    columnLayout->addLayout(leftColumn);
    columnLayout->addLayout(rightColumn);

    mainLayout->addLayout(columnLayout);

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
