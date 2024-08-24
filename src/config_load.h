// config_load.h
#ifndef CONFIG_LOAD_H
#define CONFIG_LOAD_H

#include "config_data.h"

class ConfigLoad {
public:
    static bool loadConfig(ConfigData& config);
};

#endif // CONFIG_LOAD_H
