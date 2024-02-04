#include <iostream>
#include <string>
#include <chrono>
#include <ctime>
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

class Soft {
private:
    string programName;
    string developer;
    double occupiedVolume;
    tm expirationDate;

    // Вспомогательная функция для вычисления разницы между двумя датами
    int daysBetween(const tm& date1, const tm& date2) const {
        chrono::system_clock::time_point tp1 = chrono::system_clock::from_time_t(mktime(const_cast<tm*>(&date1)));
        chrono::system_clock::time_point tp2 = chrono::system_clock::from_time_t(mktime(const_cast<tm*>(&date2)));
        return chrono::duration_cast<chrono::duration<int, ratio<24 * 60 * 60>>>(tp2 - tp1).count();
    }

public:
    // Конструктор
    Soft(const string& programName, const string& developer, double occupiedVolume, const tm& expirationDate)
        : programName(programName), developer(developer), occupiedVolume(occupiedVolume), expirationDate(expirationDate) {}

    // Деструктор
    ~Soft() {}

    // Функция подсчета количества дней до завершения лицензии
    int daysToLicenseEnd() const {
        time_t now = time(nullptr);
        tm currentDate;
        if (localtime_s(&currentDate, &now) != 0) {
            // Обработка ошибки
        }
        return daysBetween(currentDate, expirationDate);
    }

    // Функция вывода информации о программе на экран
    void displayInfo() const {
        cout << "Название программы: " << programName << endl;
        cout << "Разработчик: " << developer << endl;
        cout << "Занимаемый объем: " << occupiedVolume << " MB" << endl;
        cout << "Дата завершения лицензии: " << expirationDate.tm_mday << "." << expirationDate.tm_mon + 1 << "." << expirationDate.tm_year + 1900 << endl;
    }
};

int main() {
    Soft* software = nullptr;
    setlocale(LC_ALL, "ru");
    while (true) {
        cout << "Меню:" << endl;
        cout << "1. Создать новую запись о программе" << endl;
        cout << "2. Показать информацию о программе" << endl;
        cout << "3. Показать количество дней до завершения лицензии" << endl;
        cout << "4. Выход" << endl;

        int choice;
        cin >> choice;

        switch (choice) {
        case 1: {
            cin.ignore();
            string programName, developer;
            double occupiedVolume;
            tm date = {};

            cout << "Введите название программы: ";
            getline(cin, programName);

            cout << "Введите разработчика: ";
            getline(cin, developer);

            cout << "Введите занимаемый объем (MB): ";
            cin >> occupiedVolume;

            cout << "Введите дату завершения лицензии (ДД ММ ГГГГ): ";
            cin >> date.tm_mday >> date.tm_mon >> date.tm_year;
            date.tm_mon -= 1;
            date.tm_year -= 1900;

            delete software;
            software = new Soft(programName, developer, occupiedVolume, date);
            cout << "Запись создана!" << endl;
            break;
        }
        case 2:
            if (software) {
                software->displayInfo();
            }
            else {
                cout << "Сначала создайте запись о программе." << endl;
            }
            break;

        case 3:
            if (software) {
                cout << "Дней до завершения лицензии: " << software->daysToLicenseEnd() << endl;
            }
            else {
                cout << "Сначала создайте запись о программе." << endl;
            }
            break;

        case 4:
            delete software;
            return 0;

        default:
            cout << "Неверный выбор. Повторите ввод." << endl;
            break;
        }
    }

    return 0;
}
