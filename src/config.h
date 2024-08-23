// config.h
#ifndef CONFIG_H
#define CONFIG_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>
#include <QTextStream>
#include <QFont>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include "config_data.h"

class Config : public QWidget {
    Q_OBJECT

public:
    explicit Config(QWidget *parent = nullptr);
    ~Config();

    void loadConfig();
    void saveConfig();

private:
    void setupUI();
    void updateUIFromConfig();
    void updateConfigFromUI();

    ConfigData m_configData;
    QHBoxLayout* mainLayout;
    QLineEdit* nameLineEdit;
    QSpinBox* seekJumpPeriodSpinBox;
    QSpinBox* seekBuffersToPlaySpinBox;
    QSpinBox* isolationRampPeriodSpinBox;
    QSpinBox* isolationHitBoxSizeSpinBox;
    QSpinBox* minStemBackgroundLevelSpinBox;
    QDoubleSpinBox* fast2playDoubleSpinBox;
    QDoubleSpinBox* fast1playDoubleSpinBox;
    QDoubleSpinBox* slow1playDoubleSpinBox;
    QSpinBox* recordPeriodSpinBox;
};

#endif // CONFIG_H
