#include <iostream>

class Fraction {
private:
    double chislo;

public:
    // Конструктор по умолчанию
    Fraction() : chislo(0.0) {}

    // Конструктор с одним аргументом
    Fraction(double value) : chislo(value) {}

    // Перегрузка операторов сложения
    Fraction operator+(const Fraction& other) const {
        return Fraction(chislo + other.chislo);
    }

    Fraction operator+(double value) const {
        return Fraction(chislo + value);
    }

    // Перегрузка операторов вычитания
    Fraction operator-(const Fraction& other) const {
        return Fraction(chislo - other.chislo);
    }

    Fraction operator-(double value) const {
        return Fraction(chislo - value);
    }

    // Перегрузка операторов умножения
    Fraction operator*(const Fraction& other) const {
        return Fraction(chislo * other.chislo);
    }

    Fraction operator*(double value) const {
        return Fraction(chislo * value);
    }

    // Перегрузка операторов деления
    Fraction operator/(const Fraction& other) const {
        if (other.chislo == 0.0) {
            std::cerr << "Ошибка: Деление на ноль недопустимо." << std::endl;
            exit(EXIT_FAILURE);
        }
        return Fraction(chislo / other.chislo);
    }

    Fraction operator/(double value) const {
        if (value == 0.0) {
            std::cerr << "Ошибка: Деление на ноль недопустимо." << std::endl;
            exit(EXIT_FAILURE);
        }
        return Fraction(chislo / value);
    }

    // Перегрузка унарной операции инкремента (постфиксная форма)
    Fraction operator++(int) {
        Fraction temp = *this;
        chislo += 1.0;
        return temp;
    }

    // Вывод текущего значения
    void Display() const {
        std::cout << "Текущее значение: " << chislo << std::endl;
    }
};

int main() {
    setlocale(LC_ALL, "Ru");
    Fraction frac1(3.0 / 4);
    Fraction frac2(2.0 / 5);

    std::cout << "Выполняем операцию сложения:" << std::endl;
    std::cout << "Сложения: (3.0 / 4) + (2.0 / 5) = " << std::endl;
    Fraction sum1 = frac1 + frac2;
    sum1.Display();

    std::cout << "\nВыполняем операцию сложения с числом:" << std::endl;
    std::cout << "\nСложения с числом: (3.0 / 4) - 2.0 =" << std::endl;
    Fraction sum2 = frac1 - 2.0;
    sum2.Display();

    std::cout << "\nВыполняем унарный инкремент:" << std::endl;
    std::cout << "\nунарный инкремент: frac1++(3.0 / 4) =" << std::endl;
    Fraction inc = frac1++;
    inc.Display();
    frac1.Display();  // После постфиксного инкремента значение frac1 также увеличивается

    return 0;
}
