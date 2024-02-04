#include <iostream>
#include <string>

class Nomenclature {
private:
    std::string name;
    double wholesalePrice;
    double retailMarkup;
    int quantity;

public:
    Nomenclature(const std::string& n, double wPrice, double rMarkup, int q) :
        name(n), wholesalePrice(wPrice), retailMarkup(rMarkup), quantity(q) {}

    double potentialProfit() {
        return quantity * (retailMarkup - wholesalePrice);
    }

    void displayInfo() {
        std::cout << "Название товара: " << name << "\n";
        std::cout << "Оптовая цена: " << wholesalePrice << "\n";
        std::cout << "Розничная наценка: " << retailMarkup << "\n";
        std::cout << "Количество на складе: " << quantity << "\n";
        std::cout << "Потенциальный чистый доход: " << potentialProfit() << "\n";
    }

    ~Nomenclature() {
        std::cout << "Товар " << name << " был удален.\n";
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    int numProducts;

    std::cout << "Введите количество видов товара: ";
    std::cin >> numProducts;
    std::cin.ignore(); // Clear the newline character from the buffer

    for (int i = 0; i < numProducts; ++i) {
        std::string name;
        double wholesalePrice, retailMarkup;
        int quantity;

        std::cout << "Введите название товара " << i + 1 << ": ";
        std::cin >> name;
        std::cout << "Введите оптовую цену для " << name << ": ";
        std::cin >> wholesalePrice;
        std::cout << "Введите розничную наценку для " << name << ": ";
        std::cin >> retailMarkup;
        std::cout << "Введите количество товаров на складе для " << name << ": ";
        std::cin >> quantity;

        Nomenclature product(name, wholesalePrice, retailMarkup, quantity);
        product.displayInfo();
    }

    return 0;
}
