#ifndef VECTOR_H
#define VECTOR_H

class Vector
{
private:
    double x;
    double y;

public:
    Vector(double x = 0.0, double y = 0.0)
        : x(x), y(y) {}

    double getX() const { return x; }
    double getY() const { return y; }

    void setX(double val) { x = val; }
    void setY(double val) { y = val; }

    // Метод 1: Классическое сложение - возвращает новый вектор
    Vector addClassic(const Vector& other) const
    {
        return Vector(x + other.x, y + other.y);
    }

    // Метод 2: Модификация текущего вектора - прибавляет другой к текущему
    void addModify(const Vector& other)
    {
        x += other.x;
        y += other.y;
    }
};

#endif // VECTOR_H
