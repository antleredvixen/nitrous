// json_parser.cpp
#include "json_parser.h"
#include <QDir>

bool JsonParser::parseConfigFile(const QString& fileName, ConfigData& configData)
{
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly)) {
        return false;
    }

    QJsonDocument document = QJsonDocument::fromJson(file.readAll());
    if (document.isNull()) {
        return false;
    }

    QJsonObject jsonObject = document.object();
    if (jsonObject.contains("name")) {
        configData.setName(jsonObject["name"].toString());
    }

    if (jsonObject.contains("parameters")) {
        QJsonObject parameters = jsonObject["parameters"].toObject();
        parseParametersObject(parameters, configData);
    }

    return true;
}

bool JsonParser::isConfigFilePresent(const QString& directoryPath)
{
    QDir dir(directoryPath);
    QStringList filters;
    filters << "CONFIG.TXT";
    QStringList configFiles = dir.entryList(filters, QDir::Files);
    return !configFiles.isEmpty();
}

QString JsonParser::findConfigFile(const QString& directoryPath)
{
    QDir dir(directoryPath);
    QStringList filters;
    filters << "CONFIG.TXT";
    QStringList configFiles = dir.entryList(filters, QDir::Files);

    if (!configFiles.isEmpty()) {
        return dir.filePath(configFiles.first());
    }
    return QString();
}

bool JsonParser::saveConfigFile(const QString& fileName, const ConfigData& configData)
{
    QJsonObject jsonObject;
    jsonObject["name"] = configData.getName();
    jsonObject["parameters"] = createParametersObject(configData);

    QJsonDocument jsonDoc(jsonObject);
    QFile configFile(fileName);
    if (configFile.open(QFile::WriteOnly)) {
        configFile.write(jsonDoc.toJson(QJsonDocument::Indented));
        configFile.close();
        return true;
    }
    return false;
}

QJsonObject JsonParser::createParametersObject(const ConfigData& configData)
{
    QJsonObject parameters;

    for (ConfigData::Parameter parameter = ConfigData::Parameter::SeekJumpPeriod;
         parameter <= ConfigData::Parameter::RecordPeriod;
         parameter = static_cast<ConfigData::Parameter>(static_cast<int>(parameter) + 1)) {
        QString parameterName;
        switch (parameter) {
        case ConfigData::Parameter::SeekJumpPeriod:
            parameterName = "SeekJumpPeriod_mSecs";
            break;
        case ConfigData::Parameter::SeekBuffersToPlay:
            parameterName = "SeekBuffersToPlay";
            break;
        case ConfigData::Parameter::IsolationRampPeriod:
            parameterName = "IsolationRampPeriod_mSecs";
            break;
        case ConfigData::Parameter::IsolationHitBoxSize:
            parameterName = "IsolationHitBoxSize";
            break;
        case ConfigData::Parameter::MinStemBackgroundLevel:
            parameterName = "MinStemBackgroundLevel";
            break;
        case ConfigData::Parameter::Fast2play:
            parameterName = "Fast2play";
            break;
        case ConfigData::Parameter::Fast1play:
            parameterName = "Fast1play";
            break;
        case ConfigData::Parameter::Slow1play:
            parameterName = "Slow1play";
            break;
        case ConfigData::Parameter::RecordPeriod:
            parameterName = "RecordPeriod_secs";
            break;
        }

        if (parameter == ConfigData::Parameter::Fast2play ||
            parameter == ConfigData::Parameter::Fast1play ||
            parameter == ConfigData::Parameter::Slow1play) {
            parameters[parameterName] = configData.getDoubleParameterValue(parameter);
        } else {
            parameters[parameterName] = configData.getParameterValue(parameter).toInt();
        }
    }

    return parameters;
}

void JsonParser::parseParametersObject(const QJsonObject& parameters, ConfigData& configData)
{
    for (ConfigData::Parameter parameter = ConfigData::Parameter::SeekJumpPeriod;
         parameter <= ConfigData::Parameter::RecordPeriod;
         parameter = static_cast<ConfigData::Parameter>(static_cast<int>(parameter) + 1)) {
        QString parameterName;
        switch (parameter) {
        case ConfigData::Parameter::SeekJumpPeriod:
            parameterName = "SeekJumpPeriod_mSecs";
            break;
        case ConfigData::Parameter::SeekBuffersToPlay:
            parameterName = "SeekBuffersToPlay";
            break;
        case ConfigData::Parameter::IsolationRampPeriod:
            parameterName = "IsolationRampPeriod_mSecs";
            break;
        case ConfigData::Parameter::IsolationHitBoxSize:
            parameterName = "IsolationHitBoxSize";
            break;
        case ConfigData::Parameter::MinStemBackgroundLevel:
            parameterName = "MinStemBackgroundLevel";
            break;
        case ConfigData::Parameter::Fast2play:
            parameterName = "Fast2play";
            break;
        case ConfigData::Parameter::Fast1play:
            parameterName = "Fast1play";
            break;
        case ConfigData::Parameter::Slow1play:
            parameterName = "Slow1play";
            break;
        case ConfigData::Parameter::RecordPeriod:
            parameterName = "RecordPeriod_secs";
            break;
        }

        if (parameters.contains(parameterName)) {
            if (parameter == ConfigData::Parameter::Fast2play ||
                parameter == ConfigData::Parameter::Fast1play ||
                parameter == ConfigData::Parameter::Slow1play) {
                configData.setDoubleParameterValue(parameter, parameters[parameterName].toDouble());
            } else {
                configData.setParameterValue(parameter, parameters[parameterName].toInt());
            }
        }
    }
}
