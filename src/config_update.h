// config_update.h
#ifndef CONFIG_UPDATE_H
#define CONFIG_UPDATE_H

#include "config_data.h"
#include <QLineEdit>
#include <QSpinBox>
#include <QDoubleSpinBox>

class ConfigUpdate {
public:
    void updateUIFromConfig(ConfigData& configData, QLineEdit* nameLineEdit,
                            QSpinBox* seekJumpPeriodSpinBox,
                            QSpinBox* seekBuffersToPlaySpinBox,
                            QSpinBox* isolationRampPeriodSpinBox,
                            QSpinBox* isolationHitBoxSizeSpinBox,
                            QSpinBox* minStemBackgroundLevelSpinBox,
                            QDoubleSpinBox* fast2playDoubleSpinBox,
                            QDoubleSpinBox* fast1playDoubleSpinBox,
                            QDoubleSpinBox* slow1playDoubleSpinBox,
                            QSpinBox* recordPeriodSpinBox,
                            QSpinBox* headphoneWiredLimitSpinBox,
                            QSpinBox* headphoneBTLimitSpinBox,
                            QSpinBox* splitterPreferenceSpinBox);

    void updateConfigFromUI(ConfigData& configData, QLineEdit* nameLineEdit,
                            QSpinBox* seekJumpPeriodSpinBox,
                            QSpinBox* seekBuffersToPlaySpinBox,
                            QSpinBox* isolationRampPeriodSpinBox,
                            QSpinBox* isolationHitBoxSizeSpinBox,
                            QSpinBox* minStemBackgroundLevelSpinBox,
                            QDoubleSpinBox* fast2playDoubleSpinBox,
                            QDoubleSpinBox* fast1playDoubleSpinBox,
                            QDoubleSpinBox* slow1playDoubleSpinBox,
                            QSpinBox* recordPeriodSpinBox,
                            QSpinBox* headphoneWiredLimitSpinBox,
                            QSpinBox* headphoneBTLimitSpinBox,
                            QSpinBox* splitterPreferenceSpinBox);
};

#endif // CONFIG_UPDATE_H
