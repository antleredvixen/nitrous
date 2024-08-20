// status.h
#ifndef STATUS_H
#define STATUS_H

#include <QWidget>
#include <QPainter>
#include <QBrush>
#include <QPen>
#include <QColor>
#include <QSettings>

class Status : public QWidget
{
    Q_OBJECT

public:
    explicit Status(QWidget *parent = nullptr);

    enum class ColorOption { Tan, Green, Clear, Black };

    void setColorOption(ColorOption option);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    ColorOption mCurrentColorOption;
    QList<QColor> mCurrentColors;
};

#endif // STATUS_H
