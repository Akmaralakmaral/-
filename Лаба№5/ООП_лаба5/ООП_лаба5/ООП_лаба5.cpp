#include <iostream>
#include <limits>

class Int {
private:
    long double value;

public:
    Int(long double initialValue) : value(initialValue) {}

    // Бинарные операторы
    // Оператор сложения
    Int operator+(const Int& other) const {
        CheckOverflow(value + other.value);  // CheckOverflow - Проверка Переполнение
        return Int(value + other.value);
    }

    // Оператор вычитания
    Int operator-(const Int& other) const {
        CheckOverflow(value - other.value);
        return Int(value - other.value);
    }

    // Оператор умножение
    Int operator*(const Int& other) const {
        CheckOverflow(value * other.value);
        return Int(value * other.value);
    }

    // Оператор деление
    Int operator/(const Int& other) const {
        if (other.value == 0) {
            std::cerr << "Ошибка: Деление на ноль недопустимо." << std::endl;
            exit(EXIT_FAILURE);
        }
        CheckOverflow(value / other.value);
        return Int(value / other.value);
    }

    // Унарные операторы инкремента
    Int& operator++() {
        CheckOverflow(value + 1);
        ++value;
        return *this;
    }

    // Вывод текущего значения
    void Display() const {
        std::cout << "Текущее значение: " << static_cast<int>(value) << std::endl;
    }

private:
    // Функция для проверки переполнения и завершения программы при необходимости
    void CheckOverflow(long double result) const {
        if (result > std::numeric_limits<int>::max() || result < std::numeric_limits<int>::min()) {
            std::cerr << "Ошибка: Арифметическое переполнение. Результат не может быть представлен типом int." << std::endl;
            exit(EXIT_FAILURE);
        }
    }
};

int main() {
    setlocale(LC_ALL, "Ru");
    Int num1 = 2147483647; // Максимальное значение int
    Int num2 = 1;

    std::cout << "Выполняем сложение:" << std::endl;
    Int sum = num1 + num2;
    sum.Display();

    Int difference = num1 - num2;
    difference.Display();

    Int product = num1 * num2;
    product.Display();

    Int quotient = num1 / num2;
    quotient.Display();

    Int result = ++num1;
    result.Display();

    return 0;
}
