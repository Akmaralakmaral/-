#include <iostream>
#include <iomanip>
#include <algorithm>
#include <limits>
using namespace std;

// Шаблон функции для нахождения максимального элемента массива
template <typename T>
T findMaxElement(const T* array, int size) {
    T maxElement = array[0];
    for (int i = 1; i < size; ++i) {
        if (array[i] > maxElement + std::numeric_limits<T>::epsilon()) {
            maxElement = array[i];
        }
    }
    return maxElement;
}

// Шаблон функции для сортировки массива
template <typename T>
void sortArray(T* array, int size) {
    sort(array, array + size, [](const T& a, const T& b) {
        return a + std::numeric_limits<T>::epsilon() < b;
        });
}

int main() {
    setlocale(LC_ALL, "Ru");

    // Ввод размера массива для целых чисел
    int intSize;
    cout << "Введите размер массива целых чисел: ";
    cin >> intSize;

    // Ввод значений для целых чисел
    int* intArray = new int[intSize];
    cout << "Введите значения массива целых чисел: ";
    for (int i = 0; i < intSize; ++i) {
        cin >> intArray[i];
    }

    cout << "Максимальный элемент в intArray: " << findMaxElement(intArray, intSize) << std::endl;

    sortArray(intArray, intSize);
    cout << "Отсортированный intArray: ";
    for (int i = 0; i < intSize; ++i) {
        cout << intArray[i] << " ";
    }
    cout << std::endl;

    delete[] intArray; // Освобождение памяти для целых чисел

    // Ввод размера массива для чисел с плавающей точкой (double)
    int doubleSize;
    cout << "Введите размер массива с плавающей точкой: ";
    cin >> doubleSize;

    // Ввод значений для чисел с плавающей точкой
    double* doubleArray = new double[doubleSize];
    cout << "Введите значения массива с плавающей точкой: ";
    for (int i = 0; i < doubleSize; ++i) {
        cin >> doubleArray[i];
    }

    cout << "Максимальный элемент в doubleArray: " << findMaxElement(doubleArray, doubleSize) << endl;

    sortArray(doubleArray, doubleSize);
    cout << "Отсортированный doubleArray: ";
    for (int i = 0; i < doubleSize; ++i) {
        cout << doubleArray[i] << " ";
    }
    cout << endl;

    delete[] doubleArray; // Освобождение памяти для чисел с плавающей точкой

    return 0;
}
