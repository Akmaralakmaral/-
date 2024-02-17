#include <iostream>

class Rectangle {
private:
    double length;
    double width;

public:
    // Конструктор класса
    Rectangle(double len, double wid) : length(len), width(wid) {}

    // Перегруженный метод rect_area() для прямоугольника
    double rect_area(double len, double wid) {
        return len * wid;
    }

    // Перегруженный метод rect_area() для квадрата
    double rect_area(double side) {
        return side * side;
    }
};

int main() {
    setlocale(LC_ALL, "Ru");
    Rectangle rectangleObj(5.0, 3.0); // Прямоугольник
    Rectangle squareObj(4.0, 4.0);    // Квадрат

    // Вызов первой версии метода rect_area() для прямоугольника
    std::cout << "Площадь прямоугольника: " << rectangleObj.rect_area(5.0, 3.0) << std::endl;

    // Вызов второй версии метода rect_area() для квадрата
    std::cout << "Площадь квадрата: " << squareObj.rect_area(4.0) << std::endl;

    return 0;
}
