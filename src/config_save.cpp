// config_save.cpp
#include "config_save.h"
#include "config_data.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDir>

bool ConfigSave::saveConfig(const ConfigData& config) {
    // Get the current directory
    QString currentDir = QDir::currentPath();

    // Construct the path to CONFIG.TXT in the current directory
    QString configFilePath = currentDir + "/CONFIG.TXT";

    QJsonObject jsonObject;
    jsonObject["name"] = config.name;

    QJsonObject parameters;
    parameters["SeekJumpPeriod_mSecs"] = config.seekJumpPeriod;
    parameters["SeekBuffersToPlay"] = config.seekBuffersToPlay;
    parameters["IsolationRampPeriod_mSecs"] = config.isolationRampPeriod;
    parameters["IsolationHitBoxSize"] = config.isolationHitBoxSize;
    parameters["MinStemBackgroundLevel"] = config.minStemBackgroundLevel;
    parameters["Fast2play"] = config.fast2play;
    parameters["Fast1play"] = config.fast1play;
    parameters["Slow1play"] = config.slow1play;
    parameters["RecordPeriod_secs"] = config.recordPeriod;

    jsonObject["parameters"] = parameters;

    QJsonDocument jsonDoc(jsonObject);

    QFile configFile(configFilePath);
    if (configFile.open(QFile::WriteOnly)) {
        configFile.write(jsonDoc.toJson(QJsonDocument::Indented));
        configFile.close();
        return true;
    }
    return false;
}
