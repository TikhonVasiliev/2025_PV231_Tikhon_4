#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSpinBox>
#include <QPushButton>
#include <QComboBox>
#include <QLabel>
#include "drawingarea.h"
#include "vector.h"
#include "smart_ptr.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

private:
    QSpinBox* vector1XSpin;
    QSpinBox* vector1YSpin;
    QSpinBox* vector2XSpin;
    QSpinBox* vector2YSpin;

    QComboBox* methodCombo;
    QPushButton* addButton;

    QLabel* resultLabel;

    DrawingArea* drawingArea;

    // Векторы в умных указателях
    smart_ptr<Vector> vector1;
    smart_ptr<Vector> vector2;
    smart_ptr<Vector> vectorResult;
private slots:
    void onAddClicked();
    void updateVectorsFromInputs();
};

#endif // MAINWINDOW_H
