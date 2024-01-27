#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>
#include <Windows.h>

using namespace std;

class Student {
public:
    string firstName;
    string lastName;
    string dateOfBirth;
    string phoneNumber;
};

class StudentGroup {
private:
    vector<Student> students;

public:
    // Метод для добавления студента
    void addStudent(const Student& student) {
        students.push_back(student);
    }

    // Метод для поиска студента по фамилии
    Student* findStudentByLastName(const string& lastName) {
        auto it = find_if(students.begin(), students.end(),
            [&](const Student& student) { return student.lastName == lastName; });

        return (it != students.end()) ? &(*it) : nullptr;
    }

    // Метод для сортировки студентов по фамилии
    void sortByLastName() {
        sort(students.begin(), students.end(),
            [](const Student& a, const Student& b) { return a.lastName < b.lastName; });
    }

    // Метод для сортировки студентов по имени
    void sortByFirstName() {
        sort(students.begin(), students.end(),
            [](const Student& a, const Student& b) { return a.firstName < b.firstName; });
    }

    // Метод для сортировки студентов по дате рождения
    void sortByDateOfBirth() {
        sort(students.begin(), students.end(),
            [](const Student& a, const Student& b) { return a.dateOfBirth < b.dateOfBirth; });
    }

    // Метод для вывода информации о студентах
    void displayStudents() {
        for (const auto& student : students) {
            cout << "Студент: " << student.firstName << " " << student.lastName
                << ", Дата рождения: " << student.dateOfBirth
                << ", Номер телефона: " << student.phoneNumber << "\n";
        }
    }

    // Метод для удаления студента по имени и фамилии
    void removeStudentByName(const string& firstName, const string& lastName) {
        students.erase(
            remove_if(students.begin(), students.end(),
                [&](const Student& student) { return student.firstName == firstName && student.lastName == lastName; }),
            students.end());
    }
};

int main() {
    setlocale(LC_ALL, "rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    StudentGroup group;

    int choice = -1;
    int numStudents = 0; // Переменная для хранения количества студентов

    while (choice != 0) {
        cout << "Меню:\n";
        cout << "1-Ввод количества студентов\n";  // Добавлен пункт ввода количества студентов
        cout << "2-Ввод данных студентов\n";  // Изменен пункт на ввод данных студентов
        cout << "3-Вывод всех студентов\n";   // Изменен пункт на вывод всех студентов
        cout << "4-Сортировка по фамилии\n";  // Добавлен пункт сортировки по фамилии
        cout << "5-Сортировка по имени\n";  // Добавлен пункт сортировки по имени
        cout << "6-Сортировка по дате рождения\n";  // Добавлен пункт сортировки по дате рождения
        cout << "7-Поиск студента\n";
        cout << "8-Удаление студента\n";  // Изменен пункт на удаление студента
        cout << "0-Выход\n";
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            // Ввод количества студентов
            cout << "Введите количество студентов: ";
            cin >> numStudents;
            break;
        }
        case 2: {
            // Ввод данных студентов
            for (int i = 0; i < numStudents; ++i) {
                Student student;
                cout << "Введите данные для студента " << i + 1 << ":\n";
                cout << "Имя: ";
                cin >> student.firstName;
                cout << "Фамилия: ";
                cin >> student.lastName;
                cout << "Дата рождения (ГГГГ-ММ-ДД): ";
                cin >> student.dateOfBirth;
                cout << "Номер телефона: ";
                cin >> student.phoneNumber;
                group.addStudent(student);
            }
            break;
        }
        case 3:
            // Вывод всех студентов
            cout << "\nВсе студенты:\n";
            group.displayStudents();
            break;
        case 4:
            // Сортировка по фамилии
            group.sortByLastName();
            cout << "\nПосле сортировки по фамилии:\n";
            group.displayStudents();
            break;
        case 5:
            // Сортировка по имени
            group.sortByFirstName();
            cout << "\nПосле сортировки по имени:\n";
            group.displayStudents();
            break;
        case 6:
            // Сортировка по дате рождения
            group.sortByDateOfBirth();
            cout << "\nПосле сортировки по дате рождения:\n";
            group.displayStudents();
            break;
        case 7: {
            // Поиск студента по фамилии
            string searchLastName;
            cout << "\nВведите фамилию для поиска: ";
            cin.ignore();
            getline(cin, searchLastName);
            Student* foundStudent = group.findStudentByLastName(searchLastName);

            if (foundStudent != nullptr) {
                cout << "\nНайденный студент:\n";
                cout << "Студент: " << foundStudent->firstName << " " << foundStudent->lastName
                    << ", Дата рождения: " << foundStudent->dateOfBirth
                    << ", Номер телефона: " << foundStudent->phoneNumber << "\n";
            }
            else {
                cout << "\nСтудент с фамилией '" << searchLastName << "' не найден.\n";
            }
            break;
        }
        case 8: {
            // Удаление студента по имени и фамилии
            string removeFirstName, removeLastName;
            cout << "\nВведите имя и фамилию для удаления (через пробел): ";
            cin >> removeFirstName >> removeLastName;
            group.removeStudentByName(removeFirstName, removeLastName);
            cout << "\nПосле удаления студента '" << removeFirstName << " " << removeLastName << "':\n";
            group.displayStudents();
            break;
        }
        case 0:
            // Выход из программы
            cout << "Выход из программы.\n";
            break;
        default:
            // Некорректный выбор
            cout << "Некорректный выбор. Попробуйте снова.\n";
            break;
        }
    }

    return 0;
}
