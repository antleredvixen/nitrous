// config_file_handler.h
#ifndef CONFIG_FILE_HANDLER_H
#define CONFIG_FILE_HANDLER_H

#include "config_data.h"

class ConfigFileHandler {
public:
    static bool loadConfig(ConfigData& config);
    static bool saveConfig(const ConfigData& config);
};

#endif // CONFIG_FILE_HANDLER_H
