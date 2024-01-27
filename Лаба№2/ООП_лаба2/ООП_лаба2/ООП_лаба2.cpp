#include <string>
#include <iostream>
#include <iomanip>
#include <Windows.h> время

using namespace std;

class  AEROFLOT {
	string departureLocation;
	string destinationLocation;
	string departureTime;
	string arrivalTime;
	string registrationLocation;
	int flightNumber;

public:
	void SetFlightInfo()
	{
		cout << "Введите название пункта отправления:" << endl;
		cin >> departureLocation;
		cout << "Введите название пункта назначения:" << endl;
		cin >> destinationLocation;
		cout << "Введите время отправки:" << endl;
		cin >> departureTime;
		cout << "Введите время прибытия:" << endl;
		cin >> arrivalTime;
		cout << "Введите место регистрации:" << endl;
		cin >> registrationLocation;
		cout << "Введите номер рейса:" << endl;
		cin >> flightNumber;
		cin.ignore();
	}
	void DisplayFlightInfo() {
		cout << setw(15) << departureLocation << setw(15) << destinationLocation << setw(12) << departureTime << setw(12) << arrivalTime << setw(10) << flightNumber << setw(15) << registrationLocation << endl;
		cout << "------------------------------------------------------------------------------------------------------" << endl;
	}
	string GetDestinationLocation() {
		return destinationLocation;
	}
	int GetFlightNumber() {
		return flightNumber;
	}
};

void BubbleSort(AEROFLOT  flights[], size_t size) {
	AEROFLOT temp;
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (flights[j].GetDestinationLocation() > flights[j + 1].GetDestinationLocation()) {
				temp = flights[j];
				flights[j] = flights[j + 1];
				flights[j + 1] = temp;
			}
		}
	}
	cout << "Сортировка выполнена успешно!" << endl;
}

void Search(AEROFLOT flights[], size_t size) {
	bool found = false;
	string destination;
	cout << "Введите название пункта назначения:" << endl;
	cin >> destination;
	for (int i = 0; i < size; i++) {
		if (destination == flights[i].GetDestinationLocation()) {
			flights[i].DisplayFlightInfo();
			found = true;
		}
	}
	if (!found)
		cout << "Рейс не найден!" << endl;
}

int main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int flightCount;
	cout << "Введите количество рейсов:";
	cin >> flightCount;

	AEROFLOT  flightInfo[10];
	int choice;

	do
	{
		cout << "Выберите действие:" << endl;
		cout << "1-Ввод" << endl;
		cout << "2-Вывод" << endl;
		cout << "3-Сортировка" << endl;
		cout << "4-Поиск рейса" << endl;
		cout << "0-Выход" << endl;

		cin >> choice;
		switch (choice) {
		case 0:
			return 0;
			break;

		case 1:
			for (int i = 0; i < flightCount; i++) {
				flightInfo[i].SetFlightInfo();
			}
			cout << endl;
			break;

		case 2:
			cout << setw(15) << "| Пункт отпр. " << setw(15) << "| Пункт назнач. " << setw(12) << "| Время отпр. " << setw(12) << "| Время приб. " << setw(10) << "|Номер рейса " << setw(10) << "| Место регистрации | " << endl;
			cout << " |=============|===============|=============|=============|============|===================|" << endl;
			{
				for (int i = 0; i < flightCount; i++)
				{
					flightInfo[i].DisplayFlightInfo();
				}
				cout << endl;
				break;
			}
		case 3:
			BubbleSort(flightInfo, flightCount);
			cout << endl;
			break;

		case 4:
			Search(flightInfo, flightCount);
			cout << endl;
			break;
		}
	} while (choice != 0);

	return 0;
}
