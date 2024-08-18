// preferences.h
#ifndef PREFERENCES_H
#define PREFERENCES_H

#include <QDialog>
#include <QComboBox>
#include <QLabel>
#include <QVBoxLayout>
#include <QPushButton>
#include "status_display.h"

class Preferences : public QDialog
{
    Q_OBJECT

public:
    explicit Preferences(StatusDisplay* statusDisplay, QWidget *parent = nullptr);

private slots:
    void applyChanges();
    void okButtonClicked();

private:
    QLabel *label;
    QComboBox *comboBox;
    QPushButton *applyButton;
    QPushButton *okButton;
    QPushButton *cancelButton;
    StatusDisplay *mStatusDisplay;
};

#endif // PREFERENCES_H
