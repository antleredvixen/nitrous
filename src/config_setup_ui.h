#ifndef CONFIG_SETUP_UI_H
#define CONFIG_SETUP_UI_H

#include <QVariant>
#include <QApplication>
#include <QButtonGroup>
#include <QDialog>
#include <QDialogButtonBox>
#include <QGridLayout>
#include <QHeaderView>
#include <QLabel>
#include <QLineEdit>
#include <QSpinBox>
#include <QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ConfigSetup
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *nameLabel;
    QLineEdit *nameLineEdit;
    QLabel *seekJumpPeriodLabel;
    QSpinBox *seekJumpPeriodSpinBox;
    QLabel *seekBuffersToPlayLabel;
    QSpinBox *seekBuffersToPlaySpinBox;
    QLabel *isolationRampPeriodLabel;
    QSpinBox *isolationRampPeriodSpinBox;
    QLabel *isolationHitBoxSizeLabel;
    QSpinBox *isolationHitBoxSizeSpinBox;
    QLabel *minStemBackgroundLevelLabel;
    QSpinBox *minStemBackgroundLevelSpinBox;
    QLabel *fast2playLabel;
    QDoubleSpinBox *fast2playDoubleSpinBox;
    QLabel *fast1playLabel;
    QDoubleSpinBox *fast1playDoubleSpinBox;
    QLabel *slow1playLabel;
    QDoubleSpinBox *slow1playDoubleSpinBox;
    QLabel *recordPeriodLabel;
    QSpinBox *recordPeriodSpinBox;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ConfigSetup)
    {
        if (ConfigSetup->objectName().isEmpty())
            ConfigSetup->setObjectName(QStringLiteral("ConfigSetup"));
        ConfigSetup->resize(400, 300);
        verticalLayout = new QVBoxLayout(ConfigSetup);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        nameLabel = new QLabel(ConfigSetup);
        nameLabel->setObjectName(QStringLiteral("nameLabel"));

        gridLayout->addWidget(nameLabel, 0, 0, 1, 1);

        nameLineEdit = new QLineEdit(ConfigSetup);
        nameLineEdit->setObjectName(QStringLiteral("nameLineEdit"));

        gridLayout->addWidget(nameLineEdit, 0, 1, 1, 1);

        seekJumpPeriodLabel = new QLabel(ConfigSetup);
        seekJumpPeriodLabel->setObjectName(QStringLiteral("seekJumpPeriodLabel"));

        gridLayout->addWidget(seekJumpPeriodLabel, 1, 0, 1, 1);

        seekJumpPeriodSpinBox = new QSpinBox(ConfigSetup);
        seekJumpPeriodSpinBox->setObjectName(QStringLiteral("seekJumpPeriodSpinBox"));

        gridLayout->addWidget(seekJumpPeriodSpinBox, 1, 1, 1, 1);

        seekBuffersToPlayLabel = new QLabel(ConfigSetup);
        seekBuffersToPlayLabel->setObjectName(QStringLiteral("seekBuffersToPlayLabel"));

        gridLayout->addWidget(seekBuffersToPlayLabel, 2, 0, 1, 1);

        seekBuffersToPlaySpinBox = new QSpinBox(ConfigSetup);
        seekBuffersToPlaySpinBox->setObjectName(QStringLiteral("seekBuffersToPlaySpinBox"));

        gridLayout->addWidget(seekBuffersToPlaySpinBox, 2, 1, 1, 1);

        isolationRampPeriodLabel = new QLabel(ConfigSetup);
        isolationRampPeriodLabel->setObjectName(QStringLiteral("isolationRampPeriodLabel"));

        gridLayout->addWidget(isolationRampPeriodLabel, 3, 0, 1, 1);

        isolationRampPeriodSpinBox = new QSpinBox(ConfigSetup);
        isolationRampPeriodSpinBox->setObjectName(QStringLiteral("isolationRampPeriodSpinBox"));

        gridLayout->addWidget(isolationRampPeriodSpinBox, 3, 1, 1, 1);

        isolationHitBoxSizeLabel = new QLabel(ConfigSetup);
        isolationHitBoxSizeLabel->setObjectName(QStringLiteral("isolationHitBoxSizeLabel"));

        gridLayout->addWidget(isolationHitBoxSizeLabel, 4, 0, 1, 1);

        isolationHitBoxSizeSpinBox = new QSpinBox(ConfigSetup);
        isolationHitBoxSizeSpinBox->setObjectName(QStringLiteral("isolationHitBoxSizeSpinBox"));

        gridLayout->addWidget(isolationHitBoxSizeSpinBox, 4, 1, 1, 1);
        isolationHitBoxSizeSpinBox = new QSpinBox(ConfigSetup);
        isolationHitBoxSizeSpinBox->setObjectName(QStringLiteral("isolationHitBoxSizeSpinBox"));

        gridLayout->addWidget(isolationHitBoxSizeSpinBox, 4, 1, 1, 1);

        minStemBackgroundLevelLabel = new QLabel(ConfigSetup);
        minStemBackgroundLevelLabel->setObjectName(QStringLiteral("minStemBackgroundLevelLabel"));

        gridLayout->addWidget(minStemBackgroundLevelLabel, 5, 0, 1, 1);

        minStemBackgroundLevelSpinBox = new QSpinBox(ConfigSetup);
        minStemBackgroundLevelSpinBox->setObjectName(QStringLiteral("minStemBackgroundLevelSpinBox"));

        gridLayout->addWidget(minStemBackgroundLevelSpinBox, 5, 1, 1, 1);

        fast2playLabel = new QLabel(ConfigSetup);
        fast2playLabel->setObjectName(QStringLiteral("fast2playLabel"));

        gridLayout->addWidget(fast2playLabel, 6, 0, 1, 1);

        fast2playDoubleSpinBox = new QDoubleSpinBox(ConfigSetup);
        fast2playDoubleSpinBox->setObjectName(QStringLiteral("fast2playDoubleSpinBox"));

        gridLayout->addWidget(fast2playDoubleSpinBox, 6, 1, 1, 1);

        fast1playLabel = new QLabel(ConfigSetup);
        fast1playLabel->setObjectName(QStringLiteral("fast1playLabel"));

        gridLayout->addWidget(fast1playLabel, 7, 0, 1, 1);

        fast1playDoubleSpinBox = new QDoubleSpinBox(ConfigSetup);
        fast1playDoubleSpinBox->setObjectName(QStringLiteral("fast1playDoubleSpinBox"));

        gridLayout->addWidget(fast1playDoubleSpinBox, 7, 1, 1, 1);

        slow1playLabel = new QLabel(ConfigSetup);
        slow1playLabel->setObjectName(QStringLiteral("slow1playLabel"));

        gridLayout->addWidget(slow1playLabel, 8, 0, 1, 1);

        slow1playDoubleSpinBox = new QDoubleSpinBox(ConfigSetup);
        slow1playDoubleSpinBox->setObjectName(QStringLiteral("slow1playDoubleSpinBox"));

        gridLayout->addWidget(slow1playDoubleSpinBox, 8, 1, 1, 1);

        recordPeriodLabel = new QLabel(ConfigSetup);
        recordPeriodLabel->setObjectName(QStringLiteral("recordPeriodLabel"));

        gridLayout->addWidget(recordPeriodLabel, 9, 0, 1, 1);

        recordPeriodSpinBox = new QSpinBox(ConfigSetup);
        recordPeriodSpinBox->setObjectName(QStringLiteral("recordPeriodSpinBox"));

        gridLayout->addWidget(recordPeriodSpinBox, 9, 1, 1, 1);

        verticalLayout->addLayout(gridLayout);

        buttonBox = new QDialogButtonBox(ConfigSetup);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);

        retranslateUi(ConfigSetup);
        QObject::connect(buttonBox, SIGNAL(accepted()), ConfigSetup, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ConfigSetup, SLOT(reject()));

        QMetaObject::connectSlotsByName(ConfigSetup);
    } // setupUi

    void retranslateUi(QDialog *ConfigSetup)
    {
        ConfigSetup->setWindowTitle(QApplication::translate("ConfigSetup", "Config Setup", nullptr));
        nameLabel->setText(QApplication::translate("ConfigSetup", "Name", nullptr));
        seekJumpPeriodLabel->setText(QApplication::translate("ConfigSetup", "Seek Jump Period", nullptr));
        seekBuffersToPlayLabel->setText(QApplication::translate("ConfigSetup", "Seek Buffers to Play", nullptr));
        isolationRampPeriodLabel->setText(QApplication::translate("ConfigSetup", "Isolation Ramp Period", nullptr));
        isolationHitBoxSizeLabel->setText(QApplication::translate("ConfigSetup", "Isolation Hit Box Size", nullptr));
        minStemBackgroundLevelLabel->setText(QApplication::translate("ConfigSetup", "Min Stem Background Level", nullptr));
        fast2playLabel->setText(QApplication::translate("ConfigSetup", "Fast 2 Play", nullptr));
        fast1playLabel->setText(QApplication::translate("ConfigSetup", "Fast 1 Play", nullptr));
        slow1playLabel->setText(QApplication::translate("ConfigSetup", "Slow 1 Play", nullptr));
        recordPeriodLabel->setText(QApplication::translate("ConfigSetup", "Record Period", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ConfigSetup: public Ui_ConfigSetup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // CONFIG_SETUP_UI_H
