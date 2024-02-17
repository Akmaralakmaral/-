#include <iostream>
#include <string>

class Tatra; // Предварительное объявление класса Tatra

class Kamaz {
private:
    std::string name;
    double speed;

public:
    Kamaz(const std::string& n) : name(n), speed(0) {}

    // Метод для ввода скорости Kamaz
    void inputSpeed() {
        std::cout << "Введите скорость Kamaz " << name << " (км/ч): ";
        std::cin >> speed;
    }

    // Метод для получения скорости Kamaz
    double getSpeed() const {
        return speed;
    }

    // Метод для отображения информации о Kamaz
    void displayInfo() const {
        std::cout << "Kamaz " << name << " (Скорость: " << speed << " км/ч)\n";
    }

    // Функция для сравнения скоростей Kamaz и Tatra
    friend int FrCreater(const Kamaz& kamaz, const Tatra& tatra);
};

class Tatra {
private:
    std::string name;
    double speed;

public:
    Tatra(const std::string& n) : name(n), speed(0) {}

    // Метод для ввода скорости Tatra
    void inputSpeed() {
        std::cout << "Введите скорость Tatra " << name << " (км/ч): ";
        std::cin >> speed;
    }

    // Метод для получения скорости Tatra
    double getSpeed() const {
        return speed;
    }

    // Метод для отображения информации о Tatra
    void displayInfo() const {
        std::cout << "Tatra " << name << " (Скорость: " << speed << " км/ч)\n";
    }

    // Дружественный метод для сравнения скоростей Kamaz и Tatra
    friend int FrCreater(const Kamaz& kamaz, const Tatra& tatra);
};

// Функция для сравнения скоростей Kamaz и Tatra
int FrCreater(const Kamaz& kamaz, const Tatra& tatra) {
    if (kamaz.getSpeed() > tatra.getSpeed()) {
        return 1;
    }
    else if (kamaz.getSpeed() < tatra.getSpeed()) {
        return -1;
    }
    else {
        return 0;
    }
}

int main() {
    setlocale(LC_ALL, "ru");
    Kamaz kamaz1("Master");
    Kamaz kamaz2("Navigator");
    Tatra tatra1("Phoenix");
    Tatra tatra2("Terra");

    int choice;
    int kamazWins = 0;
    int tatraWins = 0;

    do {
        std::cout << "Меню:\n";
        std::cout << "1. Ввести скорости Kamaz\n";
        std::cout << "2. Ввести скорости Tatra\n";
        std::cout << "3. Сравнить скорости по равнине\n";
        std::cout << "4. Сравнить скорости в горах\n";
        std::cout << "5. Сравнить скорости в пустыне\n";
        std::cout << "6. Итоговый результат:\n";
        std::cout << "Выберите действие (1-6): ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            kamaz1.inputSpeed();
            kamaz2.inputSpeed();
            break;
        case 2:
            tatra1.inputSpeed();
            tatra2.inputSpeed();
            break;
        case 3:
            if (kamaz1.getSpeed() == 0 || tatra1.getSpeed() == 0) {
                std::cout << "Сначала введите скорости для Kamaz и Tatra.\n";
            }
            else {
                int result = FrCreater(kamaz1, tatra1);
                if (result > 0) {
                    std::cout << "Kamaz " << kamaz1.getSpeed() << " > Tatra " << tatra1.getSpeed() << " - Kamaz победил\n";
                    kamazWins++;
                }
                else if (result < 0) {
                    std::cout << "Kamaz " << kamaz1.getSpeed() << " < Tatra " << tatra1.getSpeed() << " - Tatra победил\n";
                    tatraWins++;
                }
                else {
                    std::cout << "Kamaz " << kamaz1.getSpeed() << " = Tatra " << tatra1.getSpeed() << " - Ничья\n";
                }
            }
            break;
        case 4: // Горы
            if (kamaz2.getSpeed() == 0 || tatra2.getSpeed() == 0) {
                std::cout << "Сначала введите скорости для Kamaz и Tatra.\n";
            }
            else {
                int result = FrCreater(kamaz2, tatra2);
                if (result > 0) {
                    std::cout << "Kamaz " << kamaz2.getSpeed() << " > Tatra " << tatra2.getSpeed() << " - Kamaz победил в горах\n";
                    kamazWins++;
                }
                else if (result < 0) {
                    std::cout << "Kamaz " << kamaz2.getSpeed() << " < Tatra " << tatra2.getSpeed() << " - Tatra победил в горах\n";
                    tatraWins++;
                }
                else {
                    std::cout << "Kamaz " << kamaz2.getSpeed() << " = Tatra " << tatra2.getSpeed() << " - Ничья в горах\n";
                }
            }
            break;
        case 5: // Пустыня
            if (kamaz1.getSpeed() == 0 || tatra2.getSpeed() == 0) {
                std::cout << "Сначала введите скорости для Kamaz и Tatra.\n";
            }
            else {
                int result = FrCreater(kamaz1, tatra2);
                if (result > 0) {
                    std::cout << "Kamaz " << kamaz1.getSpeed() << " > Tatra " << tatra2.getSpeed() << " - Kamaz победил в пустыне\n";
                    kamazWins++;
                }
                else if (result < 0) {
                    std::cout << "Kamaz " << kamaz1.getSpeed() << " < Tatra " << tatra2.getSpeed() << " - Tatra победил в пустыне\n";
                    tatraWins++;
                }
                else {
                    std::cout << "Kamaz " << kamaz1.getSpeed() << " = Tatra " << tatra2.getSpeed() << " - Ничья в пустыне\n";
                }
            }
            break;
        case 6:
            std::cout << "Итоговый результат:\n";
            std::cout << "Kamaz победил " << kamazWins << " раза.\n";
            std::cout << "Tatra победил " << tatraWins << " раза.\n";
            if (kamazWins > tatraWins) {
                std::cout << "Kamaz является общим победителем!\n";
            }
            else if (tatraWins > kamazWins) {
                std::cout << "Tatra является общим победителем!\n";
            }
            else {
                std::cout << "Ничья! Kamaz и Tatra равны в количестве побед.\n";
            }
            break;
        default:
            std::cout << "Неверный выбор!\n";
            break;
        }
    } while (choice != 6);

    return 0;
}
