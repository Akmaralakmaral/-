#include <iostream>
#include <string>
using namespace std;

class Employee {
protected:
    string name;
    string position;
    double salary;

public:
    // Конструктор по умолчанию
    Employee() : name(""), position(""), salary(0.0) {}

    // Конструктор с аргументами
    Employee(const string& name, const string& position, double salary)
        : name(name), position(position), salary(salary) {}

    // Деструктор
    ~Employee() {
        std::cout << "Объект Employee уничтожен для " << name << endl;
    }

    // Расчет годовой заработной платы
    double calculateAnnualSalary() const {
        return salary * 12;
    }

    // Вывод информации о работнике на консоль
    void displayInfo() const {
        std::cout << "----------------------------------------\n"
            << "Информация о сотрудниках\n"
            << "----------------------------------------\n"
            << "Имя: " << name << "\nДолжность: " << position << "\nЗаработная плата: $" << salary << "\n";
    }
};

class Manager : private Employee {       //// private Employee 
private:
    double annual_bonus;
    string company_car;
    int stock_options;

public:
    // Конструктор по умолчанию
    Manager() : annual_bonus(0.0), company_car(""), stock_options(0) {}

    // Конструктор с аргументами
    Manager(const string& name, const string& position, double salary,
        double annual_bonus, const string& company_car, int stock_options)
        : Employee(name, position, salary), annual_bonus(annual_bonus),
        company_car(company_car), stock_options(stock_options) {}

    // Деструктор
    ~Manager() {
        cout << "\nОбъект Manager уничтожен для " << name << endl;
    }

    //// Восстановление доступа к методам базового класса 
    using Employee::calculateAnnualSalary;
    using Employee::displayInfo;

    // Вывод информации о менеджере на консоль
    void displayInfo() const {
        Employee::displayInfo();  // Вызываем метод родительского класса
        cout << "Годовой бонус: " << annual_bonus << "\nКомпанийская машина: " << company_car
            << "\nОпции по акциям: " << stock_options << endl;
    }
    double getTotalAnnualEarnings() const {
        // Вызываем метод calculateAnnualSalary базового класса и добавляем к нему annual_bonus
        return calculateAnnualSalary() + annual_bonus;
    }
};

int main() {
    setlocale(LC_ALL, "Ru");
    Employee emp("Джон Доу", "Инженер-программист", 5000.0);
    emp.displayInfo();
    cout << "Годовая зарплата: $" << emp.calculateAnnualSalary() << endl;

    Manager manager("Алиса Смит", "Руководитель проекта", 7000.0, 2000.0, "Компанийская машина ABC", 500);
    manager.displayInfo();
    cout << "Годовая зарплата: $" << manager.calculateAnnualSalary() << endl;
    cout << "Итоговая годовая зарплата: $" << manager.getTotalAnnualEarnings() << endl;
}
