#ifndef DRAWINGAREA_H
#define DRAWINGAREA_H

#include <QWidget>
#include "vector.h"
#include "smart_ptr.h"

class DrawingArea : public QWidget
{
    Q_OBJECT

private:
    std::vector<smart_ptr<Vector>> vectors;

public:
    explicit DrawingArea(QWidget* parent = nullptr)
        : QWidget(parent)
    {
        setMinimumSize(400, 400);
    }

    void setVectors(const std::vector<smart_ptr<Vector>>& vecs)
    {
        vectors = vecs;
        update();
    }

protected:
    void paintEvent(QPaintEvent* event) override;
};

#endif // DRAWINGAREA_H
