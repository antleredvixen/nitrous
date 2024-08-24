// json_parser.h
#ifndef JSON_PARSER_H
#define JSON_PARSER_H

#include <QString>
#include <QJsonDocument>
#include <QJsonObject>
#include <QFile>
#include "config_data.h"

class JsonParser {
public:
    static bool parseConfigFile(const QString& fileName, ConfigData& configData);
    static bool isConfigFilePresent(const QString& directoryPath);
    static QString findConfigFile(const QString& directoryPath);
    static bool saveConfigFile(const QString& fileName, const ConfigData& configData);

private:
    static QJsonObject createParametersObject(const ConfigData& configData);
    static void parseParametersObject(const QJsonObject& parameters, ConfigData& configData);
};

#endif // JSON_PARSER_H
