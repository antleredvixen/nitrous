// config_load.h
#ifndef CONFIG_LOAD_H
#define CONFIG_LOAD_H

#include <QString>
#include <QFile>
#include <QTextStream>
#include "config_data.h"

class ConfigLoad
{
public:
    static bool loadConfig(ConfigData &configData);
};

#endif // CONFIG_LOAD_H
