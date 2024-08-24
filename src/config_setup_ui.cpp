#include "config_setup_ui.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QFont>

ConfigUI::ConfigUI(Config* config) : config_(config) {
}

void ConfigUI::setupUI() {
    mainLayout_ = new QHBoxLayout();
    QVBoxLayout *leftColumn = new QVBoxLayout();
    QVBoxLayout *rightColumn = new QVBoxLayout();
    mainLayout_->addLayout(leftColumn);
    mainLayout_->addLayout(rightColumn);

    auto createLabeledWidget = [](const QString& labelText, QWidget* widget, QVBoxLayout* column) {
        QLabel* label = new QLabel(labelText);
        QFont font = label->font();
        font.setBold(true);
        label->setFont(font);
        label->setAlignment(Qt::AlignRight | Qt::AlignVCenter);

        QHBoxLayout* layout = new QHBoxLayout;
        layout->addWidget(label);
        layout->addWidget(widget);
        layout->setStretchFactor(label, 1);
        layout->setStretchFactor(widget, 0);
        layout->setSpacing(5);

        widget->setFixedWidth(100);

        column->addLayout(layout);
    };

    QLineEdit* nameLineEdit = new QLineEdit;
    createLabeledWidget("Name:", nameLineEdit, leftColumn);
    config_->setNameLineEdit(nameLineEdit);

    QSpinBox* seekJumpPeriodSpinBox = new QSpinBox;
    seekJumpPeriodSpinBox->setRange(0, 10000);
    createLabeledWidget("Seek Jump Period (mSecs):", seekJumpPeriodSpinBox, leftColumn);
    config_->setSeekJumpPeriodSpinBox(seekJumpPeriodSpinBox);

    QSpinBox* seekBuffersToPlaySpinBox = new QSpinBox;
    seekBuffersToPlaySpinBox->setRange(0, 100);
    createLabeledWidget("Seek Buffers To Play:", seekBuffersToPlaySpinBox, leftColumn);
    config_->setSeekBuffersToPlaySpinBox(seekBuffersToPlaySpinBox);

    QSpinBox* isolationRampPeriodSpinBox = new QSpinBox;
    isolationRampPeriodSpinBox->setRange(0, 10000);
    createLabeledWidget("Isolation Ramp Period (mSecs):", isolationRampPeriodSpinBox, leftColumn);
    config_->setIsolationRampPeriodSpinBox(isolationRampPeriodSpinBox);

    QSpinBox* isolationHitBoxSizeSpinBox = new QSpinBox;
    isolationHitBoxSizeSpinBox->setRange(0, 100);
    createLabeledWidget("Isolation Hit Box Size:", isolationHitBoxSizeSpinBox, leftColumn);
    config_->setIsolationHitBoxSizeSpinBox(isolationHitBoxSizeSpinBox);

    QSpinBox* minStemBackgroundLevelSpinBox = new QSpinBox;
    minStemBackgroundLevelSpinBox->setRange(0, 255);
    createLabeledWidget("Min Stem Background Level:", minStemBackgroundLevelSpinBox, rightColumn);
    config_->setMinStemBackgroundLevelSpinBox(minStemBackgroundLevelSpinBox);

    QDoubleSpinBox* fast2playDoubleSpinBox = new QDoubleSpinBox;
    fast2playDoubleSpinBox->setRange(0.0, 10.0);
    fast2playDoubleSpinBox->setSingleStep(0.1);
    createLabeledWidget("Fast 2 Play:", fast2playDoubleSpinBox, rightColumn);
    config_->setFast2playDoubleSpinBox(fast2playDoubleSpinBox);

    QDoubleSpinBox* fast1playDoubleSpinBox = new QDoubleSpinBox;
    fast1playDoubleSpinBox->setRange(0.0, 10.0);
    fast1playDoubleSpinBox->setSingleStep(0.1);
    createLabeledWidget("Fast 1 Play:", fast1playDoubleSpinBox, rightColumn);
    config_->setFast1playDoubleSpinBox(fast1playDoubleSpinBox);

    QDoubleSpinBox* slow1playDoubleSpinBox = new QDoubleSpinBox;
    slow1playDoubleSpinBox->setRange(0.0, 10.0);
    slow1playDoubleSpinBox->setSingleStep(0.1);
    createLabeledWidget("Slow 1 Play:", slow1playDoubleSpinBox, rightColumn);
    config_->setSlow1playDoubleSpinBox(slow1playDoubleSpinBox);

    QSpinBox* recordPeriodSpinBox = new QSpinBox;
    recordPeriodSpinBox->setRange(0, 3600);
    createLabeledWidget("Record Period (secs):", recordPeriodSpinBox, rightColumn);
    config_->setRecordPeriodSpinBox(recordPeriodSpinBox);

    config_->setLayout(mainLayout_);
}
