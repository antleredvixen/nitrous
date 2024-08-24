// config_load.cpp
#include "config_load.h"
#include "config_data.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDir>

bool ConfigLoad::loadConfig(ConfigData& config) {
    // Get the current directory
    QString currentDir = QDir::currentPath();

    // Construct the path to CONFIG.TXT in the current directory
    QString configFilePath = currentDir + "/CONFIG.TXT";

    QFile configFile(configFilePath);
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
