#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <stack>
using namespace std;

class STACK {
private:
    stack<int> myStack1; // Основной стек, в который будут вводиться данные
    stack<int> myStack3; // Стек для четных чисел
    stack<int> myStack4; // Стек для нечетных чисел

public:
    void input(int a) {
        myStack1.push(a); // Добавить введенное значение в основной стек
    }

    void raz() {
        if (myStack1.empty()) {
            cout << "нет данных" << endl;
        }
        else {
            while (!myStack1.empty()) {
                if (myStack1.top() % 2 == 0) {
                    myStack3.push(myStack1.top()); // Поместить четное число в стек myStack3
                }
                else {
                    myStack4.push(myStack1.top()); // Поместить нечетное число в стек myStack4
                }
                myStack1.pop(); // Удалить верхний элемент из основного стека
            }
            cout << "деление завершено" << endl;
        }
    }

    void file_Show() {
        ifstream fin;
        fin.open("akmaral.txt"); // Открыть файл для чтения
        if (!fin.is_open()) {
            cout << "Файл не открылся" << endl;
        }
        else {
            int a;
            while (fin >> a) {
                myStack1.push(a); // Считать данные из файла и добавить в основной стек
            }
        }
        fin.close(); // Закрыть файл
        cout << "данные считаны из файла" << endl;
    }

    void show() {
        stack<int> myStack2 = myStack1; // Создать копию основного стека для вывода
        if (!myStack2.empty()) {
            while (!myStack2.empty()) {
                cout << myStack2.top() << endl; // Вывести верхний элемент
                myStack2.pop(); // Удалить верхний элемент из копии стека
            }
        }
        else {
            cout << "стек пуст!" << endl;
        }
    }

    void chetn() {
        stack<int> myStack2 = myStack3; // Создать копию стека четных чисел
        if (!myStack2.empty()) {
            while (!myStack2.empty()) {
                cout << myStack2.top() << endl; // Вывести верхний элемент
                myStack2.pop(); // Удалить верхний элемент из копии стека
            }
        }
        else {
            cout << "нет таких вагонов!" << endl;
        }
    }

    void ne_chetn() {
        stack<int> myStack2 = myStack4; // Создать копию стека нечетных чисел
        if (!myStack2.empty()) {
            while (!myStack2.empty()) {
                cout << myStack2.top() << endl; // Вывести верхний элемент
                myStack2.pop(); // Удалить верхний элемент из копии стека
            }
        }
        else {
            cout << "нет таких вагонов!" << endl;
        }
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    srand(static_cast<unsigned>(time(NULL))); // Инициализация генератора случайных чисел
    int col = 0, val = 0;
    STACK obj; // Создание объекта класса STACK

    cout << "Введите количество вагонов: " << endl;
    cin >> col; // Ввод количества вагонов

    ofstream fout("akmaral.txt"); // Открыть файл для записи
    if (!fout.is_open()) {
        cout << "Файл не открылся!" << endl;
    }
    else {
        for (int i = 0; i < col; i++) {
            fout << rand() % 21 << endl; // Случайно генерировать числа и записывать их в файл
        }
        fout.close(); // Закрыть файл
    }

    while (val != 6) {
        system("CLS"); // Очистить консоль
        cout << "\n Меню: " << endl;
        cout << "0 - Ввод данных " << "\n 1 - Считывание из файла " << "\n 2 - Вывод всех вагонов " << "\n 3- Разделить вагоны " << "\n 4 - Вывод четных вагонов" << "\n 5 - Вывод нечетных вагонов" << "\n 6 - Выход";
        cout << endl << "Выберите из меню: ";
        cin >> val; // Выбор действия из меню

        if (val == 0) {
            system("CLS"); // Очистить консоль
            cout << "Введите номера вагонов : " << endl;
            for (int i = 0; i < col; i++) {
                int zn;
                cin >> zn; // Ввод номеров вагонов
                obj.input(zn); // Добавление номера в основной стек
            }
            cout << endl << "данные записаны!" << endl << endl;
            system("pause"); // Пауза для продолжения
        }
        else if (val == 1) {
            system("CLS"); // Очистить консоль
            obj.file_Show(); // Считать данные из файла
            system("pause"); // Пауза для продолжения
        }
        else if (val == 2) {
            system("CLS"); // Очистить консоль
            cout << "Все вагоны: " << endl << endl;
            obj.show(); // Вывод всех вагонов
            system("pause"); // Пауза для продолжения
        }
        else if (val == 3) {
            system("CLS"); // Очистить консоль
            obj.raz(); // Разделить вагоны
            system("pause"); // Пауза для продолжения
        }
        else if (val == 4) {
            system("CLS"); // Очистить консоль
            cout << "Вагоны с четными номерами:" << endl << endl;
            obj.chetn(); // Вывод четных вагонов
            system("pause"); // Пауза для продолжения
        }
        else if (val == 5) {
            system("CLS"); // Очистить консоль
            cout << "Вагоны с нечетными номерами:" << endl << endl;
            obj.ne_chetn(); // Вывод нечетных вагонов
            system("pause"); // Пауза для продолжения
        }
        else if (val == 6) {
            cout << "До свидания!" << endl;
            break; // Выход из цикла при выборе опции "Выход"
        }
        else {
            cout << "Неверный выбор. Попробуйте снова." << endl;
            system("pause");
            return 0;
        }
    }
}
