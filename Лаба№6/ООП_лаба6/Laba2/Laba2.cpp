#include <iostream>
#include <cstring>
using namespace std;

// Родительский класс Display
class Display {
protected:
    char type[32];
    long colors;
    int x_resolution;
    int y_resolution;

public:
    // Конструктор с аргументами
    Display(const char* displayType, long displayColors, int xRes, int yRes)
        : colors(displayColors), x_resolution(xRes), y_resolution(yRes) {
        strncpy_s(type, displayType, _TRUNCATE);
    }

    // Размещение информации о классе-родителе на консоли
    void displayInfo() const {
        std::cout << "----------------------------------------\n"
            << "Информация о дисплее\n"
            << "----------------------------------------\n"
            << "Тип: " << type << "\nЦвета: " << colors
            << "\nРазрешение: " << x_resolution << "x" << y_resolution << "\n";
    }
};
// Родительский класс MotherBoard
class MotherBoard {
protected:
    int processor;
    int speed;
    int RAM;

public:
    // Конструктор с аргументами
    MotherBoard(int proc, int spd, int ram)
        : processor(proc), speed(spd), RAM(ram) {}
    // Размещение информации о классе-родителе на консоли
    void displayInfo() const {
        std::cout << "----------------------------------------\n"
            << "Информация о материнской плате\n"
            << "----------------------------------------\n"
            << "Процессор: " << processor << "\nСкорость: " << speed
            << " GHz\nОперативная память: " << RAM << " GB\n";
    }
};
// Класс-потомок Computer
class Computer : public Display, public MotherBoard {
private:
    char name[64];
    int hard_disk;

public:
    // Конструктор с аргументами
    Computer(const char* compName, const char* displayType, long displayColors,
        int xRes, int yRes, int proc, int spd, int ram, int disk)
        : Display(displayType, displayColors, xRes, yRes),
        MotherBoard(proc, spd, ram), hard_disk(disk) {
        strncpy_s(name, compName, _TRUNCATE);
    }
    // Метод для отображения информации о компьютере на экране
    void show() const {
        std::cout << "----------------------------------------\n"
            << "Информация о компьютере\n"
            << "----------------------------------------\n"
            << "Имя компьютера: " << name << "\nРазмер жесткого диска: " << hard_disk << " GB\n";
        Display::displayInfo();
        MotherBoard::displayInfo();
    }
};


int main() {
    setlocale(LC_ALL, "RU");
    // Пример использования класса Computer
    Computer myComputer("MyPC", "LCD", 16777216, 1920, 1080, 4, 3, 16, 500);
    myComputer.show();

    return 0;
}
