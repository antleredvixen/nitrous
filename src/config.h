// config.h
#ifndef CONFIG_H
#define CONFIG_H

#include <QWidget>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QPushButton>
#include <QLabel>
#include "config_data.h"

class Config : public QWidget
{
    Q_OBJECT

public:
    Config(QWidget *parent = nullptr);
    ~Config();

    QLineEdit *getNameLineEdit();
    void setNameLineEdit(QLineEdit *lineEdit);
    QSpinBox *getSeekJumpPeriodSpinBox();
    void setSeekJumpPeriodSpinBox(QSpinBox *spinBox);
    QSpinBox *getSeekBuffersToPlaySpinBox();
    void setSeekBuffersToPlaySpinBox(QSpinBox *spinBox);
    QSpinBox *getIsolationRampPeriodSpinBox();
    void setIsolationRampPeriodSpinBox(QSpinBox *spinBox);
    QSpinBox *getIsolationHitBoxSizeSpinBox();
    void setIsolationHitBoxSizeSpinBox(QSpinBox *spinBox);
    QSpinBox *getMinStemBackgroundLevelSpinBox();
    void setMinStemBackgroundLevelSpinBox(QSpinBox *spinBox);
    QDoubleSpinBox *getFast2playDoubleSpinBox();
    void setFast2playDoubleSpinBox(QDoubleSpinBox *spinBox);
    QDoubleSpinBox *getFast1playDoubleSpinBox();
    void setFast1playDoubleSpinBox(QDoubleSpinBox *spinBox);
    QDoubleSpinBox *getSlow1playDoubleSpinBox();
    void setSlow1playDoubleSpinBox(QDoubleSpinBox *spinBox);
    QSpinBox *getRecordPeriodSpinBox();
    void setRecordPeriodSpinBox(QSpinBox *spinBox);
    QSpinBox *getHeadphoneWiredLimitSpinBox();
    void setHeadphoneWiredLimitSpinBox(QSpinBox *spinBox);
    QSpinBox *getHeadphoneBTLimitSpinBox();
    void setHeadphoneBTLimitSpinBox(QSpinBox *spinBox);
    QSpinBox *getSplitterPreferenceSpinBox();
    void setSplitterPreferenceSpinBox(QSpinBox *spinBox);

    void updateCurrentDirectory(const QString &path);

private slots:
    void onApplyClicked();
    void onOkClicked();

private:
    void loadConfig();
    void clearConfigForm();

    QHBoxLayout *mainLayout;
    QLineEdit *nameLineEdit;
    QSpinBox *seekJumpPeriodSpinBox;
    QSpinBox *seekBuffersToPlaySpinBox;
    QSpinBox *isolationRampPeriodSpinBox;
    QSpinBox *isolationHitBoxSizeSpinBox;
    QSpinBox *minStemBackgroundLevelSpinBox;
    QDoubleSpinBox *fast2playDoubleSpinBox;
    QDoubleSpinBox *fast1playDoubleSpinBox;
    QDoubleSpinBox *slow1playDoubleSpinBox;
    QSpinBox *recordPeriodSpinBox;
    QSpinBox *headphoneWiredLimitSpinBox;
    QSpinBox *headphoneBTLimitSpinBox;
    QSpinBox *splitterPreferenceSpinBox;
    QPushButton *applyButton;
    QPushButton *okButton;

    ConfigData m_configData;
    QString m_currentDirectory;
};

#endif // CONFIG_H
