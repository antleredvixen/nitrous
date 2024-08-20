// preferences.h
#ifndef PREFERENCES_H
#define PREFERENCES_H

#include <QDialog>
#include <QComboBox>
#include <QLabel>
#include <QVBoxLayout>
#include <QPushButton>
#include <QSettings>
#include "status.h"

class Preferences : public QDialog
{
    Q_OBJECT

public:
    explicit Preferences(Status *status, QWidget *parent = nullptr);

private slots:
    void applyChanges();
    void okButtonClicked();

private:
    QLabel *label;
    QComboBox *comboBox;
    QPushButton *applyButton;
    QPushButton *okButton;
    QPushButton *cancelButton;
    Status *mStatus;
};

#endif // PREFERENCES_H
