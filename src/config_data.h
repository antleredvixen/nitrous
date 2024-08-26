// config_data.h
#ifndef CONFIG_DATA_H
#define CONFIG_DATA_H

#include <QString>

class ConfigData {
public:
    QString name;
    int seekJumpPeriod;
    int seekBuffersToPlay;
    int isolationRampPeriod;
    int isolationHitBoxSize;
    int minStemBackgroundLevel;
    double fast2play;
    double fast1play;
    double slow1play;
    int recordPeriod;
    int headphoneWiredLimit;
    int headphoneBTLimit;
    int splitterPreference;
};

#endif // CONFIG_DATA_H
