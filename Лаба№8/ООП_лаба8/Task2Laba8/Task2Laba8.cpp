#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

template <typename T, int size>
class ArraySum {
public:
    // Конструктор, который заполняет массивы случайными числами
    ArraySum() {
        srand(time(nullptr));
        for (int i = 0; i < size; ++i) {
            // array1[i] = static_cast<T>(rand() % 100);
            // array2[i] = static_cast<T>(rand() % 100);
            array1[i] = static_cast<T>(rand()) / static_cast<T>(RAND_MAX / 100.0);
            array2[i] = static_cast<T>(rand()) / static_cast<T>(RAND_MAX / 100.0);
        }
    }

    // Метод для нахождения суммы элементов массивов
    T findSum() const {
        T sum = 0;
        for (int i = 0; i < size; ++i) {
            sum += array1[i] + array2[i];
        }
        return sum;
    }

    // Метод для вывода содержимого массивов
    void displayArrays() const {
        std::cout << "Первый массив: ";
        displayArray(array1);
        std::cout << "Второй массив: ";
        displayArray(array2);
    }

private:
    T array1[size];
    T array2[size];

    // Вспомогательный метод для вывода содержимого массива
    void displayArray(const T* arr) const {
        for (int i = 0; i < size; ++i) {
            std::cout << std::fixed << std::setprecision(1) << arr[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    setlocale(LC_ALL, "Ru");
    // Примеры использования шаблона на различных типах данных

    // Шаблон для массивов целых чисел
    std::cout << "\nДля массивов целых чисел: " << std::endl;
    ArraySum<int, 5> intArraySum;
    intArraySum.displayArrays();
    std::cout << "Сумма массивов: " << intArraySum.findSum() << std::endl;
    std::cout << "\n************************************* " << std::endl;
    // Шаблон для массивов чисел с плавающей точкой
    std::cout << "\nДля массивов чисел с плавающей точкой: " << std::endl;
    ArraySum<double, 5> doubleArraySum;
    doubleArraySum.displayArrays();
    std::cout << "Сумма массивов: " << doubleArraySum.findSum() << std::endl;

    return 0;
}
