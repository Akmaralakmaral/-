#include <iostream>
#include <string>

// Шаблон класса "стек"
template <typename T, size_t Capacity>
class Stack {
private:
    T elements[Capacity];
    size_t top;

public:
    Stack() : top(0) {}

    void push(const T& value) {
        if (top < Capacity) {
            elements[top++] = value;
        }
        else {
            std::cerr << "Stack overflow!" << std::endl;
        }
    }

    T pop() {
        if (top > 0) {
            return elements[--top];
        }
        else {
            std::cerr << "Stack underflow!" << std::endl;
            return T(); // Возвращаем значение по умолчанию в случае ошибки
        }
    }

    bool isEmpty() const {
        return top == 0;
    }

    size_t size() const {
        return top;
    }
};

// Структура для представления информации о работнике
struct Worker {
    std::string surname;
    int age;
    std::string specialization;
    double averageSalary;
};

int main() {
    setlocale(LC_ALL, "Ru");
    const size_t maxWorkers = 100; // Максимальное количество работников на одном заводе
    Stack<Worker, maxWorkers> workerStack;

    // Ввод информации о работниках завода
    size_t numberOfFactories;
    std::cout << "Введите количество заводов: ";
    std::cin >> numberOfFactories;

    for (size_t i = 0; i < numberOfFactories; ++i) {
        size_t numberOfWorkers;
        std::cout << "Введите количество работников на заводе " << i + 1 << ": ";
        std::cin >> numberOfWorkers;

        for (size_t j = 0; j < numberOfWorkers; ++j) {
            Worker worker;
            std::cout << "Введите информацию о работнике " << j + 1 << " на заводе " << i + 1 << ":\n";
            std::cout << "Фамилия: ";
            std::cin >> worker.surname;
            std::cout << "Возраст: ";
            std::cin >> worker.age;
            std::cout << "Специальность: ";
            std::cin >> worker.specialization;
            std::cout << "Средний оклад: ";
            std::cin >> worker.averageSalary;

            // Положим информацию о работнике в стек
            workerStack.push(worker);
        }
    }

    // Подсчет количества слесарей и токарей
    size_t numberOfLocksmiths = 0;
    size_t numberOfTurners = 0;

    while (!workerStack.isEmpty()) {
        Worker worker = workerStack.pop();
        if (worker.specialization == "slesar") {
            ++numberOfLocksmiths;
        }
        else if (worker.specialization == "tokar") {
            ++numberOfTurners;
        }
    }

    // Вывод результатов
    std::cout << "Количество слесарей: " << numberOfLocksmiths << std::endl;
    std::cout << "Количество токарей: " << numberOfTurners << std::endl;

    return 0;
}
