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

    void setNameLineEdit(QLineEdit* nameLineEdit) { this->nameLineEdit = nameLineEdit; }
    void setSeekJumpPeriodSpinBox(QSpinBox* seekJumpPeriodSpinBox) { this->seekJumpPeriodSpinBox = seekJumpPeriodSpinBox; }
    void setSeekBuffersToPlaySpinBox(QSpinBox* seekBuffersToPlaySpinBox) { this->seekBuffersToPlaySpinBox = seekBuffersToPlaySpinBox; }
    void setIsolationRampPeriodSpinBox(QSpinBox* isolationRampPeriodSpinBox) { this->isolationRampPeriodSpinBox = isolationRampPeriodSpinBox; }
    void setIsolationHitBoxSizeSpinBox(QSpinBox* isolationHitBoxSizeSpinBox) { this->isolationHitBoxSizeSpinBox = isolationHitBoxSizeSpinBox; }
    void setMinStemBackgroundLevelSpinBox(QSpinBox* minStemBackgroundLevelSpinBox) { this->minStemBackgroundLevelSpinBox = minStemBackgroundLevelSpinBox; }
    void setFast2playDoubleSpinBox(QDoubleSpinBox* fast2playDoubleSpinBox) { this->fast2playDoubleSpinBox = fast2playDoubleSpinBox; }
    void setFast1playDoubleSpinBox(QDoubleSpinBox* fast1playDoubleSpinBox) { this->fast1playDoubleSpinBox = fast1playDoubleSpinBox; }
    void setSlow1playDoubleSpinBox(QDoubleSpinBox* slow1playDoubleSpinBox) { this->slow1playDoubleSpinBox = slow1playDoubleSpinBox; }
    void setRecordPeriodSpinBox(QSpinBox* recordPeriodSpinBox) { this->recordPeriodSpinBox = recordPeriodSpinBox; }

private:
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
