// preferences.h
#ifndef PREFERENCES_H
#define PREFERENCES_H

#include <QDialog>
#include <QComboBox>
#include <QLabel>
#include <QVBoxLayout>

class Preferences : public QDialog
{
    Q_OBJECT

public:
    explicit Preferences(QWidget *parent = nullptr);

private:
    QLabel *label;
    QComboBox *comboBox;
};

#endif // PREFERENCES_H
