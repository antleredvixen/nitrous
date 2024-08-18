// status_display.cpp
#include "status_display.h"

StatusDisplay::StatusDisplay(QWidget *parent) : QWidget(parent)
{
    setFixedSize(151, 150);
    mCurrentColorOption = ColorOption::Tan;
    mCurrentColors = QList<QColor>() << QColor(12888216) << QColor(8745568);
}

void StatusDisplay::setColorOption(ColorOption option)
{
    mCurrentColorOption = option;
    switch (option) {
    case ColorOption::Tan:
        mCurrentColors = QList<QColor>() << QColor(12888216) << QColor(8745568);
        break;
    case ColorOption::Green:
        mCurrentColors = QList<QColor>() << QColor(3107155) << QColor(2644037);
        break;
    case ColorOption::Clear:
        mCurrentColors = QList<QColor>() << QColor(14737375) << QColor(14013395);
        break;
    case ColorOption::Black:
        mCurrentColors = QList<QColor>() << QColor(4605510) << QColor(3684408);
        break;
    }
    update();
}

void StatusDisplay::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);

    // Set up the brush for the main circle
    QBrush brush(mCurrentColors.first());
    painter.setBrush(brush);
    painter.setPen(Qt::NoPen);

    // Draw the main circle
    painter.drawEllipse(rect().center(), 75, 75);

    // Set up the brush for the hole punches
    QBrush holeBrush(mCurrentColors.last());
    painter.setBrush(holeBrush);

    // Define positions for the hole punches
    QPointF holePositions[] = {
        {0.5, 0.11}, {0.5, 0.19}, {0.5, 0.27}, {0.5, 0.35}, {0.5, 0.65}, {0.5, 0.73}, {0.5, 0.81}, {0.5, 0.89},  // Vertical line
        {0.11, 0.5}, {0.19, 0.5}, {0.27, 0.5}, {0.35, 0.5}, {0.65, 0.5}, {0.73, 0.5}, {0.81, 0.5}, {0.89, 0.5}   // Horizontal line
    };

    // Draw the hole punches
    int holeRadius = rect().width() * 0.039;
    for (const QPointF &position : holePositions) {
        QPoint center(rect().width() * position.x(), rect().height() * position.y());
        painter.drawEllipse(center, holeRadius, holeRadius);
    }

    // Set up the brush for the ring
    QBrush ringBrush(mCurrentColors.last());
    painter.setBrush(ringBrush);

    // Draw the ring
    int ringRadius = rect().width() * 0.075;
    painter.drawEllipse(rect().center(), ringRadius, ringRadius);

    // Set up the brush button
    QBrush buttonBrush(mCurrentColors.first());
    painter.setBrush(buttonBrush);

    // Draw the button
    int buttonRadius = rect().width() * 0.07;
    painter.drawEllipse(rect().center(), buttonRadius, buttonRadius);
}
