#include "mainwindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGroupBox>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , vector1(new Vector(0, 0))
    , vector2(new Vector(0, 0))
    , vectorResult(nullptr)
{
    QWidget* centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    QVBoxLayout* mainLayout = new QVBoxLayout(centralWidget);

    // Создание управления для первого вектора
    QGroupBox* vec1Group = new QGroupBox("Vector 1");
    QHBoxLayout* vec1Layout = new QHBoxLayout(vec1Group);
    vector1XSpin = new QSpinBox;
    vector1XSpin->setRange(-100, 100);
    vector1XSpin->setValue(0);
    vector1YSpin = new QSpinBox;
    vector1YSpin->setRange(-100, 100);
    vector1YSpin->setValue(0);
    vec1Layout->addWidget(new QLabel("X:"));
    vec1Layout->addWidget(vector1XSpin);
    vec1Layout->addWidget(new QLabel("Y:"));
    vec1Layout->addWidget(vector1YSpin);

    // Создание управления для второго вектора
    QGroupBox* vec2Group = new QGroupBox("Vector 2");
    QHBoxLayout* vec2Layout = new QHBoxLayout(vec2Group);
    vector2XSpin = new QSpinBox;
    vector2XSpin->setRange(-100, 100);
    vector2XSpin->setValue(0);
    vector2YSpin = new QSpinBox;
    vector2YSpin->setRange(-100, 100);
    vector2YSpin->setValue(0);
    vec2Layout->addWidget(new QLabel("X:"));
    vec2Layout->addWidget(vector2XSpin);
    vec2Layout->addWidget(new QLabel("Y:"));
    vec2Layout->addWidget(vector2YSpin);

    // Выбор метода сложения
    QGroupBox* methodGroup = new QGroupBox("Addition Method");
    QHBoxLayout* methodLayout = new QHBoxLayout(methodGroup);
    methodCombo = new QComboBox;
    methodCombo->addItem("Classic (new vector)");
    methodCombo->addItem("Modify Vector 1");
    methodLayout->addWidget(methodCombo);

    // Кнопка сложения
    addButton = new QPushButton("Add Vectors");

    // Результат
    resultLabel = new QLabel("Result: (0, 0)");

    // Область рисования
    drawingArea = new DrawingArea;

    // Соединяем лэйауты
    mainLayout->addWidget(vec1Group);
    mainLayout->addWidget(vec2Group);
    mainLayout->addWidget(methodGroup);
    mainLayout->addWidget(addButton);
    mainLayout->addWidget(resultLabel);
    mainLayout->addWidget(drawingArea);



    setWindowTitle("Vector Editor");
    resize(600, 700);
}
