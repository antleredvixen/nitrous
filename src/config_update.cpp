// config_update.cpp
#include "config_update.h"
#include <QLineEdit>
#include <QSpinBox>
#include <QDoubleSpinBox>

void ConfigUpdate::updateUIFromConfig(ConfigData& configData, QLineEdit* nameLineEdit,
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
                                      QSpinBox* splitterPreferenceSpinBox)
{
    nameLineEdit->setText(configData.name);
    seekJumpPeriodSpinBox->setValue(configData.seekJumpPeriod);
    seekBuffersToPlaySpinBox->setValue(configData.seekBuffersToPlay);
    isolationRampPeriodSpinBox->setValue(configData.isolationRampPeriod);
    isolationHitBoxSizeSpinBox->setValue(configData.isolationHitBoxSize);
    minStemBackgroundLevelSpinBox->setValue(configData.minStemBackgroundLevel);
    fast2playDoubleSpinBox->setValue(configData.fast2play);
    fast1playDoubleSpinBox->setValue(configData.fast1play);
    slow1playDoubleSpinBox->setValue(configData.slow1play);
    recordPeriodSpinBox->setValue(configData.recordPeriod);
    headphoneWiredLimitSpinBox->setValue(configData.headphoneWiredLimit);
    headphoneBTLimitSpinBox->setValue(configData.headphoneBTLimit);
    splitterPreferenceSpinBox->setValue(configData.splitterPreference);
}

void ConfigUpdate::updateConfigFromUI(ConfigData& configData, QLineEdit* nameLineEdit,
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
                                      QSpinBox* splitterPreferenceSpinBox)
{
    configData.name = nameLineEdit->text();
    configData.seekJumpPeriod = seekJumpPeriodSpinBox->value();
    configData.seekBuffersToPlay = seekBuffersToPlaySpinBox->value();
    configData.isolationRampPeriod = isolationRampPeriodSpinBox->value();
    configData.isolationHitBoxSize = isolationHitBoxSizeSpinBox->value();
    configData.minStemBackgroundLevel = minStemBackgroundLevelSpinBox->value();
    configData.fast2play = fast2playDoubleSpinBox->value();
    configData.fast1play = fast1playDoubleSpinBox->value();
    configData.slow1play = slow1playDoubleSpinBox->value();
    configData.recordPeriod = recordPeriodSpinBox->value();
    configData.headphoneWiredLimit = headphoneWiredLimitSpinBox->value();
    configData.headphoneBTLimit = headphoneBTLimitSpinBox->value();
    configData.splitterPreference = splitterPreferenceSpinBox->value();
}
