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

    void updateCurrentDirectory(const QString &path);
    void loadConfig(); // Add the declaration of loadConfig() here

private slots:
    void onApplyClicked();
    void onOkClicked();

private:
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
    QPushButton *applyButton;
    QPushButton *okButton;
    // ConfigData m_configData
};

#endif // CONFIG_H
