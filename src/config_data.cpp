// config_data.cpp
#include "config_data.h"

ConfigData::ConfigData()
{
    m_parameters.insert(Parameter::SeekJumpPeriod, QVariant(0));
    m_parameters.insert(Parameter::SeekBuffersToPlay, QVariant(0));
    m_parameters.insert(Parameter::IsolationRampPeriod, QVariant(0));
    m_parameters.insert(Parameter::IsolationHitBoxSize, QVariant(0));
    m_parameters.insert(Parameter::MinStemBackgroundLevel, QVariant(0));
    m_parameters.insert(Parameter::Fast2play, QVariant(0.0));
    m_parameters.insert(Parameter::Fast1play, QVariant(0.0));
    m_parameters.insert(Parameter::Slow1play, QVariant(0.0));
    m_parameters.insert(Parameter::RecordPeriod, QVariant(0));
}

QString ConfigData::getName() const
{
    return m_name;
}

void ConfigData::setName(const QString& name)
{
    m_name = name;
}

QVariant ConfigData::getParameterValue(Parameter parameter) const
{
    return m_parameters.value(parameter);
}

void ConfigData::setParameterValue(Parameter parameter, const QVariant& value)
{
    m_parameters.insert(parameter, value);
}

double ConfigData::getDoubleParameterValue(Parameter parameter) const
{
    return m_parameters.value(parameter).toDouble();
}

void ConfigData::setDoubleParameterValue(Parameter parameter, double value)
{
    m_parameters.insert(parameter, QVariant(value));
}
