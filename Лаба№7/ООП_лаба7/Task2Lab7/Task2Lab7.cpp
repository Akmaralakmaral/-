#include <iostream>
using namespace std;

// Абстрактный базовый класс Figure
class Figure {
public:
    // Виртуальные методы для вычисления площади и периметра
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
};

// Производный класс Rectangle
class Rectangle : public Figure {
protected:
    double length;
    double width;

public:
    // Конструктор инициализации
    Rectangle(double l, double w) : length(l), width(w) {}

    // Реализация виртуальных методов
    double area() const override {
        return length * width;
    }

    double perimeter() const override {
        return 2 * (length + width);
    }
};

// Производный класс Circle
class Circle : public Figure {
protected:
    double radius;

public:
    // Конструктор инициализации
    Circle(double r) : radius(r) {}

    // Реализация виртуальных методов
    double area() const override {
        return 3.14 * radius * radius;
    }

    double perimeter() const override {
        return 2 * 3.14 * radius;
    }
};

// Производный класс Trapezium
class Trapezium : public Figure {
protected:
    double sideA;
    double sideB;
    double height;

public:
    // Конструктор инициализации
    Trapezium(double a, double b, double h) : sideA(a), sideB(b), height(h) {}

    // Реализация виртуальных методов
    double area() const override {
        return (sideA + sideB) * height / 2.0;
    }

    double perimeter() const override {
        return sideA + sideB + 2 * height;
    }
};

int main() {
    setlocale(LC_ALL, "Ru");
    Rectangle rectangle(5, 3);
    Circle circle(4);
    Trapezium trapezium(3, 7, 4);

    cout << "Результат производного класса Rectangle:" << endl;
    cout << "Area: " << "5 * 3 = " << rectangle.area() << endl;
    cout << "Area: " << rectangle.area() << endl;
    cout << "\nPerimeter: " << "2 * (5 + 3) = " << rectangle.perimeter() << endl;
    cout << "Perimeter: " << rectangle.perimeter() << endl;
    cout << "----------------------------------------\n";

    cout << "\nРезультат производного класса Circle:" << endl;
    cout << "Area: " << "3.14 * 4 * 4 = " << circle.area() << endl;
    cout << "Area: " << circle.area() << endl;
    cout << "\nPerimeter: " << "2 * 3,14 * 4 = " << circle.perimeter() << endl;
    cout << "Perimeter: " << circle.perimeter() << endl;
    cout << "----------------------------------------\n";

    cout << "\nРезультат производного класса Trapezium:" << endl;
    cout << "Area: " << "(3 + 7) * 4 / 2.0 = " << trapezium.area() << endl;
    cout << "Area: " << trapezium.area() << endl;
    cout << "\nPerimeter: " << "3 + 7 + 2 * 4 = " << trapezium.perimeter() << endl;
    cout << "Perimeter: " << trapezium.perimeter() << endl;

    return 0;
}
