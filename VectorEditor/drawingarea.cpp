#include "drawingarea.h"
#include <QPainter>
#include <QPen>
#include <QVector2D>
#include <QtMath>
void DrawingArea::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);
    painter.fillRect(rect(), Qt::white);

    QPen pen(Qt::blue, 2);
    painter.setPen(pen);

    const int centerX = width() / 2;
    const int centerY = height() / 2;

    painter.translate(centerX, centerY);

    // Масштаб для наглядности векторов
    const double scale = 20.0;

    for (const auto& sptrVec : vectors)
    {
        if (sptrVec)
        {
            const Vector& vec = *sptrVec;
            QPointF endPoint(vec.getX() * scale, -vec.getY() * scale);

            // Рисуем стрелку от центра к точке
            painter.drawLine(QPointF(0, 0), endPoint);

            // Рисуем голову стрелки
            const double arrowSize = 8.0;
            QVector2D dir(endPoint);
            QVector2D norm = dir.normalized();
            QPointF arrowP1 =  endPoint - QPointF(norm.y(), -norm.x()) * arrowSize;
            QPointF arrowP2 =  endPoint - QPointF(-norm.y(), norm.x()) * arrowSize;

            QPolygonF arrowHead;
            arrowHead << endPoint << arrowP1 << arrowP2;
            painter.setBrush(Qt::blue);
            painter.drawPolygon(arrowHead);
            painter.setBrush(Qt::NoBrush);
        }
    }
}
