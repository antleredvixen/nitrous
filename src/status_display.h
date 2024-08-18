// status_display.h
#ifndef STATUS_DISPLAY_H
#define STATUS_DISPLAY_H

#include <QWidget>
#include <QPainter>
#include <QBrush>
#include <QPen>

class StatusDisplay : public QWidget
{
    Q_OBJECT

public:
    explicit StatusDisplay(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;
};

#endif // STATUS_DISPLAY_H
