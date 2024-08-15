#include "statuswidget.h"
#include <QPainter>
#include <QBrush>
#include <QPen>

StatusWidget::StatusWidget(QWidget *parent) : QWidget(parent)
{
    // Optional: Set a fixed size for the widget
    setFixedSize(201, 200);
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
    painter.drawEllipse(rect().center(), 100, 100);

    // Set up the brush for the holes
    QBrush holeBrush(Qt::white);
    painter.setBrush(holeBrush);

    // Define positions for the hole punches relative to the widget's size
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

    // Set up the brush for the ring of the play/pause button
    QBrush ringBrush(QColor(8745568));
    painter.setBrush(ringBrush);

    // Draw the play/pause button ring
    int ringRadius = rect().width() * 0.06;
    painter.drawEllipse(rect().center(), ringRadius, ringRadius);

    // Set up the brush for the play/pause button
    QBrush buttonBrush(QColor(12888216));
    painter.setBrush(buttonBrush);

    // Draw the play/pause button
    int buttonRadius = rect().width() * 0.055;
    painter.drawEllipse(rect().center(), buttonRadius, buttonRadius);
}
