// status_display.h
#ifndef STATUS_DISPLAY_H
#define STATUS_DISPLAY_H

#include <QWidget>
#include <QPainter>
#include <QBrush>
#include <QPen>
#include <QColor>
#include <QSettings>

class StatusDisplay : public QWidget
{
    Q_OBJECT

public:
    explicit StatusDisplay(QWidget *parent = nullptr);

    enum class ColorOption { Tan, Green, Clear, Black };

    void setColorOption(ColorOption option);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    ColorOption mCurrentColorOption;
    QList<QColor> mCurrentColors;
};

#endif // STATUS_DISPLAY_H
