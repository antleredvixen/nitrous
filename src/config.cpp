// config.cpp
#include "config.h"
#include "config_load.h"
#include "config_save.h"
#include "config_setup_ui.h"
#include "config_update.h"

Config::Config(QWidget *parent) : QWidget(parent)
{
    ConfigUI configUI(this);
    configUI.setupUI();

    loadConfig();
}

void Config::loadConfig()
{
    if (ConfigLoad::loadConfig(m_configData)) {
        ConfigUpdate update;
        update.updateUIFromConfig(m_configData, nameLineEdit, seekJumpPeriodSpinBox,
                                  seekBuffersToPlaySpinBox, isolationRampPeriodSpinBox,
                                  isolationHitBoxSizeSpinBox, minStemBackgroundLevelSpinBox,
                                  fast2playDoubleSpinBox, fast1playDoubleSpinBox,
                                  slow1playDoubleSpinBox, recordPeriodSpinBox);
    }
}

void Config::saveConfig()
{
    ConfigUpdate update;
    update.updateConfigFromUI(m_configData, nameLineEdit, seekJumpPeriodSpinBox,
                              seekBuffersToPlaySpinBox, isolationRampPeriodSpinBox,
                              isolationHitBoxSizeSpinBox, minStemBackgroundLevelSpinBox,
                              fast2playDoubleSpinBox, fast1playDoubleSpinBox,
                              slow1playDoubleSpinBox, recordPeriodSpinBox);

    ConfigSave::saveConfig(m_configData);
}

Config::~Config()
{
    // Qt will handle deletion of child widgets
}
