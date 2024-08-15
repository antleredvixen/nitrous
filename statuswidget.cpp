#include "statuswidget.h"
#include <QPainter>
#include <QBrush>
#include <QPen>

StatusWidget::StatusWidget(QWidget *parent) : QWidget(parent)
{
    // Optional: Set a fixed size for the widget
    setFixedSize(151, 150);
}

void StatusWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);

    // Set up the brush for the main circle (the Stem Player logo)
    QBrush brush(QColor(12888216));
    painter.setBrush(brush);
    painter.setPen(Qt::NoPen);

    // Draw the main circle
    painter.drawEllipse(rect().center(), 75, 75);

    // Set up the brush for the holes
    QBrush holeBrush(Qt::white);
    painter.setBrush(holeBrush);

    // Define positions for the hole punches relative to the widget's size
    QPointF holePositions[] = {
        {0.5, 0.87}, {0.5, 0.79}, {0.5, 0.71}, {0.5, 0.63}, {0.5, 0.37}, {0.5, 0.29}, {0.5, 0.21}, {0.5, 0.13},  // Vertical line
        {0.13, 0.5}, {0.21, 0.5}, {0.29, 0.5}, {0.37, 0.5}, {0.63, 0.5}, {0.71, 0.5}, {0.79, 0.5}, {0.87, 0.5}   // Horizontal line
    };

    // Draw the hole punches
    int holeRadius = 5;
    for (const QPointF &position : holePositions) {
        QPoint center(rect().width() * position.x(), rect().height() * position.y());
        painter.drawEllipse(center, holeRadius, holeRadius);
    }

    // Set up the brush for the ring
    QBrush ringBrush(QColor(1320));
    painter.setBrush(ringBrush);
    painter.setPen(Qt::NoPen);

}
