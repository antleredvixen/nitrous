// config_save.h
#ifndef CONFIG_SAVE_H
#define CONFIG_SAVE_H

#include "config_data.h"

class ConfigSave {
public:
    static bool saveConfig(const ConfigData& config);
};

#endif // CONFIG_SAVE_H
