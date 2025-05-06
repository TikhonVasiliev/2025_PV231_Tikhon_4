#ifndef SMART_PTR_H
#define SMART_PTR_H

template <typename T>
class smart_ptr
{
    T* obj;
public:
    explicit smart_ptr(T* obj = nullptr)
        : obj(obj) { }

    ~smart_ptr() { delete obj; }

    // Конструктор копирования
    smart_ptr(const smart_ptr& other) = default;

    // Оператор присваивания копированием
    smart_ptr& operator=(const smart_ptr& other) = default;

    // Перемещающий конструктор
    smart_ptr(smart_ptr&& other) noexcept = default;

    // Перемещающий оператор присваивания
    smart_ptr& operator=(smart_ptr&& other) noexcept = default;

    // Доступ к объекту
    T* operator->() const { return obj; }
    T& operator*() const { return *obj; }
    T* get() const { return obj; }
    explicit operator bool() const { return obj!=nullptr; }
};

#endif // SMART_PTR_H
