#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

class Shooter {
private:
    double hitProbability; 
    static int totalShots; 

public:
    Shooter(double probability) : hitProbability(probability) {}

    
    static int getTotalShots() {
        return totalShots;
    }

    static int shoot(const Shooter& shooter, int shots) {
        

        for (int i = 1; i <= shots; ++i) {
            double estimatedProbability = Shooter::estimatedHitProbability(shooter, i);
            if (estimatedProbability * 10000 > 9999) {
                // Цель поражена
                totalShots += i + 1; // Увеличиваем общее количество выстрелов
                return 1;
            }
            cout << "выстрел #" << i << " вероятность " << estimatedProbability << endl;
        }
        // Цель не поражена
        totalShots += shots; // Увеличиваем общее количество выстрелов
        return 0;
    }

   

    // Статический метод для вычисления оценочной вероятности попадания в цель
    static double estimatedHitProbability(const Shooter& shooter, int shots) {
        return 1.0 - pow((1.0 - shooter.hitProbability), shots);
    }
};

// Инициализация статического поля
int Shooter::totalShots = 0;

int main() {
    setlocale(LC_ALL, "ru");
    srand(static_cast<unsigned int>(time(0))); // Зерно для генерации случайных чисел

    double p; // Вероятность попадания в цель
    int n;    // Количество выстрелов

    // Ввод вероятности попадания
    cout << "Введите вероятность попадания в цель (от 0 до 1): ";
    cin >> p;

    // Ввод количества выстрелов
    cout << "Введите количество выстрелов (n): ";
    cin >> n;

    if (p < 0 || p > 1 || n <= 0) {
        cout << "Ошибка: Некорректный ввод. Вероятность должна быть от 0 до 1, а количество выстрелов - положительным числом.\n";
        return 1;
    }

    Shooter shooter(p);

    // Вычисление и вывод результата стрельбы
    int result = Shooter::shoot(shooter, n);
    if (result == 1) {
        cout << "Цель поражена!\n";
    }
    else {
        cout << "Цель не поражена.\n";
    }

    // Вывод общего количества выстрелов
    cout << "Общее количество выстрелов: " << Shooter::getTotalShots() << endl;

    //// Вычисление и вывод оценочной вероятности попадания в цель
    //double estimatedProb = Shooter::estimatedHitProbability(shooter, n);
    //cout << "Оценочная вероятность попадания в цель: " << estimatedProb << endl;

    return 0;
}
