
#include <iostream>
#include <format> //C++20
using namespace std;
const int maxStaticSize = 10;

int printArray(int arrayToPrint[], int size) {
	cout << "Массив: ";
	for (int i = 0; i < size; i++)
		cout << arrayToPrint[i] << " ";
	cout << endl;
	return 0;
}

int addToArray(int staticArray[], int& size, int newNumber) {
	if (size >= maxStaticSize) return -1;
	staticArray[size] = newNumber;
	size++;
	return 0;
}
int countMAX(int staticArray[], int size, int& maxchislo, int& kolvo) {
	

}
bool isAbsolute(int n) {
	int summa = 0;
	for (int i = 1; i < n; i++) {
		if (n % i == 0) {
			summa += i;
		}
	}
	if (summa == n) {
		return 1;
	}
	return 0;
}
int dellAllAbsolute(int staticArray[], int& size) {
	if (size <= 0) return -1;
	for (int i = 0; i < size; i++) {
		if (findAbsolute(staticArray[i]) == 1) {
			for (int z = i; z < size - 1; z++) {
				staticArray[z] = staticArray[z + 1];
			}
			size--;
			i--;
		}

	}
	return 0;
}
int addToArrayAfterPos(int staticArray[], int& size, int newNumber, int poscion) {
	if (size >= maxStaticSize) return -1;
	size++;
	for (int i = size - 1; i > poscion + 1; i--) {
		staticArray[i] = staticArray[i - 1];
	}
	staticArray[poscion + 1] = newNumber;
	return 0;
}

int RemoveFromArray(int staticArray[], int& size, int position) {
	if (size <= 0) return -1;
	if (position >= size) return -2;
	for (int i = position; i < size - 1; i++)
		staticArray[i + 1] = staticArray[i];
	size--;
	return 0;
}

int findInArray(int staticArray[], int& size, int toFindNumber) {
	for (int i = 0; i < size; i++)
		if (staticArray[i] == toFindNumber)
			return i;
	return -1;
}

int main()
{
	setlocale(0, "");
	int pos;
	int currentStaticSize = 0;
	int staticArray[maxStaticSize];
	int tempNumber;
	int result;
	int sizeCase7, raznocstCase7;
	int maxchislo = 0;
	int kolvo = 0;

	cout << "1. Вывод массива\n"
		<< "2. Добавить элемент\n"
		<< "3. Удалить элемент\n"
		<< "4. Найти элемент\n"
		<< "5.Вставить элемент после заданного элемента\n"
		<< "6.Количество максимальных чисел в массиве\n"
		<< "7.Удалить все совершенные\n"
		<< "0.Выход\n";

	char menu;
	while (true) {
		cout << "Выберите действие: ";
		cin >> menu;
		switch (menu) {
		case'1':
			printArray(staticArray, currentStaticSize);
			break;
		case'2':
			cout << "Введите число: ";
			cin >> tempNumber;
			if (addToArray(staticArray, currentStaticSize, tempNumber) == -1) cout << "Массив полон\n";
			else cout << "Элемент успешно добавлен\n";
			break;
		case'3':
			cout << "Введите позицию: ";
			cin >> tempNumber;
			switch (RemoveFromArray(staticArray, currentStaticSize, tempNumber)) {
			case 0:
				cout << "Элемент успешно удален\n";
				break;
			case -1:
				cout << "Массив пуст\n";
				break;
			case -2:
				cout << "Такого элемента нет\n";
				break;
			}
			break;
		case'4':
			cout << "Введите число: ";
			cin >> tempNumber;
			result = findInArray(staticArray, currentStaticSize, tempNumber);
			if (result == -1)cout << "Элемент не найден\n";
			else cout << format("Элемент {:d} найден в позиции {:d}\n", tempNumber, result);
			break;
		case '5':
			cout << "Введите число: ";
			cin >> tempNumber;
			cout << "Введите позицию, после которой добавить число: ";
			cin >> pos;
			if (addToArrayAfterPos(staticArray, currentStaticSize, tempNumber, pos + 1) == -1) cout << "Массив полон\n";
			else cout << "Элемент успешно добавлен\n";
			break;
		case '6':
			countMAX(staticArray, currentStaticSize, maxchislo, kolvo);
			cout << format("Максимальный элемент {:d} встречается в массиве {:d} раз(а)", maxchislo, kolvo) << '\n';
			break;
		case '7':
			sizeCase7 = currentStaticSize;
			dellAllAbsolute(staticArray, currentStaticSize);
			raznocstCase7 = sizeCase7 - currentStaticSize;
			if (raznocstCase7 != 0) {
				cout << "Из массива удаленны все совершенные числа\n";
			}
			else
			{
				cout << "В массиве нет совершенных чисел\n";
			}
			break;
		case'0':
			return 0;
			break;
		default:
			cout << "Неверный ввод!";
			cout << "1. Вывод массива\n"
				<< "2. Добавить элемент\n"
				<< "3. Удалить элемент\n"
				<< "4. Найти\n"
				<< "0. выход\n"
				<< "Выберите действие: ";
			break;
		}
	}

}

