// config_file_handler.cpp
#include "config_file_handler.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>

bool ConfigFileHandler::loadConfig(ConfigData& config) {
    QFile configFile("CONFIG.TXT");
    if (configFile.open(QFile::ReadOnly)) {
        QJsonDocument jsonDoc = QJsonDocument::fromJson(configFile.readAll());
        QJsonObject jsonObject = jsonDoc.object();

        config.name = jsonObject["name"].toString();
        QJsonObject parameters = jsonObject["parameters"].toObject();
        config.seekJumpPeriod = parameters["SeekJumpPeriod_mSecs"].toInt();
        config.seekBuffersToPlay = parameters["SeekBuffersToPlay"].toInt();
        config.isolationRampPeriod = parameters["IsolationRampPeriod_mSecs"].toInt();
        config.isolationHitBoxSize = parameters["IsolationHitBoxSize"].toInt();
        config.minStemBackgroundLevel = parameters["MinStemBackgroundLevel"].toInt();
        config.fast2play = parameters["Fast2play"].toDouble();
        config.fast1play = parameters["Fast1play"].toDouble();
        config.slow1play = parameters["Slow1play"].toDouble();
        config.recordPeriod = parameters["RecordPeriod_secs"].toInt();

        configFile.close();
        return true;
    }
    return false;
}

bool ConfigFileHandler::saveConfig(const ConfigData& config) {
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
    QFile configFile("CONFIG.TXT");
    if (configFile.open(QFile::WriteOnly)) {
        configFile.write(jsonDoc.toJson(QJsonDocument::Indented));
        configFile.close();
        return true;
    }
    return false;
}
