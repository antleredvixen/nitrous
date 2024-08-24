// config.cpp
#include "config.h"
#include "config_load.h"
#include "config_save.h"
#include "config_setup_ui.h"
#include "config_update.h"
#include <QDir>

Config::Config(QWidget *parent) : QWidget(parent)
{
    ConfigUI configUI(this);
    configUI.setupUI();
    loadConfig();
}

void Config::setVisible(bool visible) {
    QWidget::setVisible(visible);
}

void Config::loadConfig()
{
    if (ConfigLoad::loadConfig(m_configData)) {
        ConfigUpdate update;
        update.updateUIFromConfig(m_configData, getNameLineEdit(), getSeekJumpPeriodSpinBox(),
                                  getSeekBuffersToPlaySpinBox(), getIsolationRampPeriodSpinBox(),
                                  getIsolationHitBoxSizeSpinBox(), getMinStemBackgroundLevelSpinBox(),
                                  getFast2playDoubleSpinBox(), getFast1playDoubleSpinBox(),
                                  getSlow1playDoubleSpinBox(), getRecordPeriodSpinBox());
    }
}

void Config::saveConfig()
{
    ConfigUpdate update;
    update.updateConfigFromUI(m_configData, getNameLineEdit(), getSeekJumpPeriodSpinBox(),
                              getSeekBuffersToPlaySpinBox(), getIsolationRampPeriodSpinBox(),
                              getIsolationHitBoxSizeSpinBox(), getMinStemBackgroundLevelSpinBox(),
                              getFast2playDoubleSpinBox(), getFast1playDoubleSpinBox(),
                              getSlow1playDoubleSpinBox(), getRecordPeriodSpinBox());
    ConfigSave::saveConfig(m_configData);
}

void Config::updateCurrentDirectory(const QString &path)
{
    QDir::setCurrent(path);
    loadConfig();
}

Config::~Config()
{
    // Qt will handle deletion of child widgets
}
