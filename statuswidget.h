#ifndef STATUSWIDGET_H
#define STATUSWIDGET_H

#include <QWidget>

class StatusWidget : public QWidget
{
    Q_OBJECT

public:
    explicit StatusWidget(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;
};

#endif // STATUSWIDGET_H
