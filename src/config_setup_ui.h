// config_setup_ui.h
#ifndef CONFIG_SETUP_UI_H
#define CONFIG_SETUP_UI_H

#include "config.h"
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QSpinBox>
#include <QDoubleSpinBox>

class ConfigUI {
public:
    ConfigUI(Config* config);
    void setupUI();

private:
    Config* config_;
    QHBoxLayout* mainLayout_;
    QLineEdit* nameLineEdit_;
    QSpinBox* seekJumpPeriodSpinBox_;
    QSpinBox* seekBuffersToPlaySpinBox_;
    QSpinBox* isolationRampPeriodSpinBox_;
    QSpinBox* isolationHitBoxSizeSpinBox_;
    QSpinBox* minStemBackgroundLevelSpinBox_;
    QDoubleSpinBox* fast2playDoubleSpinBox_;
    QDoubleSpinBox* fast1playDoubleSpinBox_;
    QDoubleSpinBox* slow1playDoubleSpinBox_;
    QSpinBox* recordPeriodSpinBox_;
};

#endif // CONFIG_SETUP_UI_H
