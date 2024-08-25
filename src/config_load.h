// config_load.h
#ifndef CONFIG_LOAD_H
#define CONFIG_LOAD_H

#include <QString>
#include "config_data.h"

class ConfigLoad
{
public:
    static bool loadConfig(ConfigData &configData, const QString& directory);
};

#endif // CONFIG_LOAD_H
