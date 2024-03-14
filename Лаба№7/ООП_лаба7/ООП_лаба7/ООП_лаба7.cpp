#include <iostream>
using namespace std;

// Базовый класс Array
class Array {
protected:
    static const int MAX_SIZE = 100; // Максимальный размер массива
    unsigned arr[MAX_SIZE]; // Массив
    int size; // Количество элементов

public:
    // Конструктор инициализации
    Array(int sz, unsigned initialValue = 0) : size(sz) {
        for (int i = 0; i < size; ++i) {
            arr[i] = initialValue;
        }
    }

    // Виртуальная функция поэлементного сложения массивов
    virtual void addArrays(const Array& other) {
        int minSize = min(size, other.size);
        for (int i = 0; i < minSize; ++i) {
            arr[i] += other.arr[i];
        }
    }

    // Вывод массива
    void printArray() const {
        for (int i = 0; i < size; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

// Класс ArrayPlusOne, переопределяющий виртуальную функцию
class ArrayPlusOne : public Array {
public:
    // Конструктор
    ArrayPlusOne(int sz, unsigned initialValue = 0) : Array(sz, initialValue) {}

    // Переопределение функции поэлементного сложения массивов
    void addArrays(const Array& other) override {
        Array::addArrays(other);
        for (int i = 0; i < size; ++i) {
            arr[i]++;
        }
    }

    // Вывод массива
    void printArrayplus() const {
        for (int i = 0; i < size; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

// Класс ArrayMinusOne, переопределяющий виртуальную функцию
class ArrayMinusOne : public Array {
public:
    // Конструктор
    ArrayMinusOne(int sz, unsigned initialValue = 0) : Array(sz, initialValue) {}

    // Переопределение функции поэлементного сложения массивов
    void addArrays(const Array& other) override {
        Array::addArrays(other);
        for (int i = 0; i < size; ++i) {
            arr[i]--;
        }
    }

    // Вывод массива
    void printArrayminus() const {
        for (int i = 0; i < size; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};



int main() {
    setlocale(LC_ALL, "Ru");
    // Пример использования

    Array arr1(3, 60);
    Array arr2(3, 40);
    ArrayPlusOne arr3(3, 10);
    ArrayMinusOne arr4(3, 20);

    cout << "Вывод значении: " << endl;
    cout << "Вывод arr1: ";
    arr1.printArray();

    cout << "Вывод arr2: ";
    arr2.printArray();

    cout << "Вывод arr3: ";
    arr3.printArray();

    cout << "Вывод arr4:  ";
    arr4.printArray();
    cout << "\n-------------------------------------------------";
    cout << "\nВызов виртуальной функции поэлементного сложения" << endl;
    cout << "-------------------------------------------------" << endl;
    cout << "arr1 + arr2: ";
    cout << "\n60  +  40:   ";
    arr1.addArrays(arr2);
    arr1.printArray();

    cout << "arr2 + arr4: ";
    cout << "\n40  +  20:   ";
    arr2.addArrays(arr4);
    arr2.printArray();



    cout << "arr3 + arr2: ";
    cout << "\n10  +  40 + 1:   ";
    arr3.addArrays(arr2);
    arr3.printArray ();

    cout << "arr4 + arr1: ";
    cout << "\n20  +  60 - 1:   ";
    arr4.addArrays(arr1);
    arr4.printArray();

    return 0;
}
