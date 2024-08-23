// config.cpp
#include "config.h"
#include "config_file_handler.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QFont>

Config::Config(QWidget *parent) : QWidget(parent)
{
    setupUI();
    loadConfig();
}

void Config::setupUI()
{
    mainLayout = new QHBoxLayout(this);
    QVBoxLayout *leftColumn = new QVBoxLayout();
    QVBoxLayout *rightColumn = new QVBoxLayout();
    mainLayout->addLayout(leftColumn);
    mainLayout->addLayout(rightColumn);

    auto createLabeledWidget = [](const QString& labelText, QWidget* widget, QVBoxLayout* column) {
        QLabel* label = new QLabel(labelText);
        QFont font = label->font();
        font.setBold(true);
        label->setFont(font);
        label->setAlignment(Qt::AlignRight | Qt::AlignVCenter);

        QHBoxLayout* layout = new QHBoxLayout;
        layout->addWidget(label);
        layout->addWidget(widget);
        layout->setStretchFactor(label, 1);
        layout->setStretchFactor(widget, 0);
        layout->setSpacing(5);

        widget->setFixedWidth(100);

        column->addLayout(layout);
    };

    nameLineEdit = new QLineEdit;
    createLabeledWidget("Name:", nameLineEdit, leftColumn);

    seekJumpPeriodSpinBox = new QSpinBox;
    seekJumpPeriodSpinBox->setRange(0, 10000);
    createLabeledWidget("Seek Jump Period (mSecs):", seekJumpPeriodSpinBox, leftColumn);

    seekBuffersToPlaySpinBox = new QSpinBox;
    seekBuffersToPlaySpinBox->setRange(0, 100);
    createLabeledWidget("Seek Buffers To Play:", seekBuffersToPlaySpinBox, leftColumn);

    isolationRampPeriodSpinBox = new QSpinBox;
    isolationRampPeriodSpinBox->setRange(0, 10000);
    createLabeledWidget("Isolation Ramp Period (mSecs):", isolationRampPeriodSpinBox, leftColumn);

    isolationHitBoxSizeSpinBox = new QSpinBox;
    isolationHitBoxSizeSpinBox->setRange(0, 100);
    createLabeledWidget("Isolation Hit Box Size:", isolationHitBoxSizeSpinBox, leftColumn);

    minStemBackgroundLevelSpinBox = new QSpinBox;
    minStemBackgroundLevelSpinBox->setRange(0, 255);
    createLabeledWidget("Min Stem Background Level:", minStemBackgroundLevelSpinBox, rightColumn);

    fast2playDoubleSpinBox = new QDoubleSpinBox;
    fast2playDoubleSpinBox->setRange(0.0, 10.0);
    fast2playDoubleSpinBox->setSingleStep(0.1);
    createLabeledWidget("Fast 2 Play:", fast2playDoubleSpinBox, rightColumn);

    fast1playDoubleSpinBox = new QDoubleSpinBox;
    fast1playDoubleSpinBox->setRange(0.0, 10.0);
    fast1playDoubleSpinBox->setSingleStep(0.1);
    createLabeledWidget("Fast 1 Play:", fast1playDoubleSpinBox, rightColumn);

    slow1playDoubleSpinBox = new QDoubleSpinBox;
    slow1playDoubleSpinBox->setRange(0.0, 10.0);
    slow1playDoubleSpinBox->setSingleStep(0.1);
    createLabeledWidget("Slow 1 Play:", slow1playDoubleSpinBox, rightColumn);

    recordPeriodSpinBox = new QSpinBox;
    recordPeriodSpinBox->setRange(0, 3600);
    createLabeledWidget("Record Period (secs):", recordPeriodSpinBox, rightColumn);
}

// The rest of the file remains unchanged
void Config::loadConfig()
{
    if (ConfigFileHandler::loadConfig(m_configData)) {
        updateUIFromConfig();
    }
}

void Config::saveConfig()
{
    updateConfigFromUI();
    ConfigFileHandler::saveConfig(m_configData);
}

void Config::updateUIFromConfig()
{
    nameLineEdit->setText(m_configData.name);
    seekJumpPeriodSpinBox->setValue(m_configData.seekJumpPeriod);
    seekBuffersToPlaySpinBox->setValue(m_configData.seekBuffersToPlay);
    isolationRampPeriodSpinBox->setValue(m_configData.isolationRampPeriod);
    isolationHitBoxSizeSpinBox->setValue(m_configData.isolationHitBoxSize);
    minStemBackgroundLevelSpinBox->setValue(m_configData.minStemBackgroundLevel);
    fast2playDoubleSpinBox->setValue(m_configData.fast2play);
    fast1playDoubleSpinBox->setValue(m_configData.fast1play);
    slow1playDoubleSpinBox->setValue(m_configData.slow1play);
    recordPeriodSpinBox->setValue(m_configData.recordPeriod);
}

void Config::updateConfigFromUI()
{
    m_configData.name = nameLineEdit->text();
    m_configData.seekJumpPeriod = seekJumpPeriodSpinBox->value();
    m_configData.seekBuffersToPlay = seekBuffersToPlaySpinBox->value();
    m_configData.isolationRampPeriod = isolationRampPeriodSpinBox->value();
    m_configData.isolationHitBoxSize = isolationHitBoxSizeSpinBox->value();
    m_configData.minStemBackgroundLevel = minStemBackgroundLevelSpinBox->value();
    m_configData.fast2play = fast2playDoubleSpinBox->value();
    m_configData.fast1play = fast1playDoubleSpinBox->value();
    m_configData.slow1play = slow1playDoubleSpinBox->value();
    m_configData.recordPeriod = recordPeriodSpinBox->value();
}

Config::~Config()
{
    // Qt will handle deletion of child widgets
}
