#include <iostream>
#include <ctime>
#include <string>
#include <thread>
#include <chrono>
#include <stdio.h>
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "Winmm.lib") // Чтобы связать библиотеку winmm.lib

using namespace std;

class Timer {
private:
    int sec; //секунды

public:
    // Конструктор 1: время указано в секундах (целое число)
    Timer(int s) : sec(s) {}

    // Конструктор 2: время указано в секундах (строка)
    Timer(const string& s) {
        sec = stoi(s);  //преобразование строки в целое число
    }

    // Конструктор 3: время указано в минутах и секундах (два целых числа)
    Timer(int m, int s) : sec(m * 60 + s) {}

    void run() {
        cout << "Таймер начал работу\n";

        // Получаем начальное время
        clock_t start_time = clock();

        while (sec > 0) {
            // Время, прошедшее с начала отсчета
            double elapsed_time = (clock() - start_time) / (double)CLOCKS_PER_SEC;

            // Если прошла одна секунда, уменьшаем время таймера
            if (elapsed_time >= 1) {
                sec--;
                start_time = clock();
                cout << sec << " секунды\n";

            }

            this_thread::sleep_for(chrono::milliseconds(50));  // небольшая задержка, чтобы не загружать процессор
        }
        Sleep(1000); system("cls");
        PlaySound(L"qwerty", NULL, SND_FILENAME | SND_ASYNC); Sleep(2000);
        cout << "Звонок! Звонок! Звонок!\n";
    }
};


int main() {
    setlocale(LC_ALL, "ru");
    int choice;
    int minutes, seconds;
    string sec_str;

    while (true) {
        cout << "/*---------* Главное Меню *---------*/\n";
        cout << "1. Задать таймер *в секундах - целое число*\n";
        cout << "2. Задать таймер *в секундах - строка*\n";
        cout << "3. Задать таймер *в минутах и секундах - два целых числа*\n";
        cout << "4. 1Выход\n";
        cout << "Выберите действие: ";

        cin >> choice; // выбор пользователя

        switch (choice) {
        case 1:
            cout << "Введите количество секунд: ";
            cin >> seconds;
            Timer(seconds).run(); //выполнения метода run() с передачей значения seconds
            break;

        case 2:
            cout << "Введите количество секунд (строкой): ";
            cin >> sec_str;
            Timer(sec_str).run(); //выполнения метода run() с передачей значения sec_str
            break;

        case 3:
            cout << "Введите количество минут: ";
            cin >> minutes;
            cout << "Введите количество секунд: ";
            cin >> seconds;
            Timer(minutes, seconds).run();//выполнения метода run() с передачей значений minutes и seconds
            break;

        case 4:
            cout << "Выход из программы. До свидания!\n";
            choice = 0;
            break;

        default:
            cout << "Неверный выбор. Попробуйте снова.\n";
            break;
        }

        cout << "\n";  // Для лучшей читаемости выводим пустую строку между итерациями
    }

    return 0;
}
