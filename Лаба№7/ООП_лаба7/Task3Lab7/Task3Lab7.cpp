#include <iostream>
#include <iomanip>
using namespace std;

// Абстрактный базовый класс
class Currency {
public:
    // Виртуальная функция для конвертации в рубли
    virtual double toRubles(double amount, double exchangeRate) const = 0;

    // Виртуальная функция для отображения типа валюты
    virtual void display() const = 0;

    // Виртуальный деструктор для правильного удаления объектов
    virtual ~Currency() {}
};

// Производный класс Dollar
class Dollar : public Currency {
public:
    // Реализация функции конвертации в рубли
    double toRubles(double amount, double exchangeRate) const override {
        return amount * exchangeRate;
    }

    // Реализация функции отображения типа валюты
    void display() const override {
        cout << "Тип валюты: Dollar" << endl;
    }
};

// Производный класс Euro
class Euro : public Currency {
public:
    // Реализация функции конвертации в рубли
    double toRubles(double amount, double exchangeRate) const override {
        return amount * exchangeRate;
    }

    // Реализация функции отображения типа валюты
    void display() const override {
        cout << "Тип валюты: Euro" << endl;
    }
};

int main() {
    setlocale(LC_ALL, "Ru");


    // Создание объектов классов Dollar и Euro
    Dollar dollar;
    Euro euro;

    double amount, exchangeRate;

    cout << "Производный класс Dollar: " << endl;
    cout << "\nВведите сумму в долларах: ";
    cin >> amount;

    cout << "Введите текущий курс доллара к рублю: ";
    cin >> exchangeRate;

    // Отображение результата для долларов
    cout << "\nРезультат для Долларов:\n";
    dollar.display();
    cout << "Сумма в рублях: " << dollar.toRubles(amount, exchangeRate) << endl;
    cout << endl << "----------------------------------\n";

    cout << "Производный класс Euro: " << endl;
    cout << "\nВведите сумму в евро: ";
    cin >> amount;

    cout << "Введите текущий курс евро к рублю: ";
    cin >> exchangeRate;

    // Отображение результата для евро
    cout << "\nРезультат для Евро:\n";
    euro.display();
    cout << "Сумма в рублях: " << euro.toRubles(amount, exchangeRate) << endl;

    return 0;
}
