#include <iostream>
#include <format> //C++20
using namespace std;

int printDynArray(int arrayToPrint[], int size) {
	cout << "Массив: ";
	for (int i = 0; i < size; i++)
		cout << arrayToPrint[i] << " ";
	cout << endl;
	return 0;
}
int addToDynArray(int*& dynamicArray, int& size, int newNumber) {

	size++;
	dynamicArray = (int*)realloc(dynamicArray, size * sizeof(int));
	dynamicArray[size-1] = newNumber;
	return 0;
}
int countMAX(int dynamicArray[], int size, int& maxchislo, int& kolvo) {
	kolvo = 0;
	maxchislo = 0;
	for (int i = 0; i < size; i++) {
		if (dynamicArray[i] > maxchislo) {
			maxchislo = dynamicArray[i];
		}
	}
	for (int i = 0; i < size; i++) {
		if (dynamicArray[i] == maxchislo) {
			kolvo += 1;
		}
	}
	return 0;
}
int isAbsolute(int n) {
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
int dellAllAbsolute(int dynamicArray[], int& size) {
	for (int i = 0; i < size; i++) {
		if (isAbsolute(dynamicArray[i]) == 1) {
			for (int z = i; z < size - 1; z++) {
				dynamicArray[z] = dynamicArray[z + 1];
			}
			size--;
			i--;
		}

	}
	return 0;
}
int addToArrayAfterPos(int dynamicArray[], int& size, int newNumber, int position) {
	size++;
	for (int i = size - 1; i > position + 1; i--) {
		dynamicArray[i] = dynamicArray[i - 1];
	}
	dynamicArray[position] = newNumber;
	return 0;
}
int main()
{
	setlocale(0, "");
	int pos;
	int currentDynamicSize = 0;
	int* dynamicArray = new int[currentDynamicSize];
	int tempNumber,result,sizeCase7, raznocstCase7,maxchislo, kolvo;

	cout << "1. Вывод массива\n"
		<< "2. Добавить элемент\n"
		<< "5.Вставить элемент после заданного элемента\n"
		<< "6.Количество максимальных чисел в массиве\n"
		<< "7.Удалить все совершенные\n"
		<< "0.Выход\n"
		<< "Выберите действие: ";
	char menu;
	while (true) {
		cout << "Выберите действие: ";
		cin >> menu;
		switch (menu) {
		case'1':
			printDynArray(dynamicArray, currentDynamicSize);
			break;
		case'2':
			cout << "Введите число: ";
			cin >> tempNumber;
			addToDynArray(dynamicArray, currentDynamicSize, tempNumber);
			break;
		case '5':
			cout << "Введите число: ";
			cin >> tempNumber;
			cout << "Введите позицию, после которой добавить число: ";
			cin >> pos;
			if (addToArrayAfterPos(dynamicArray, currentDynamicSize, tempNumber, pos ) == -1) cout << "Массив полон\n";
			else cout << "Элемент успешно добавлен\n";
			break;
		case '6':
			countMAX(dynamicArray, currentDynamicSize, maxchislo, kolvo);
			cout << format("Максимальный элемент {:d} встречается в массиве {:d} раз(а)", maxchislo, kolvo) << '\n';
			break;
		case '7':
			sizeCase7 = currentDynamicSize;
			dellAllAbsolute(dynamicArray, currentDynamicSize);
			raznocstCase7 = sizeCase7 - currentDynamicSize;
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
				<< "5.Вставить элемент после заданного элемента\n"
				<< "6.Количество максимальных чисел в массиве\n"
				<< "7.Удалить все совершенные\n"
				<< "0.Выход\n"
				<< "Выберите действие: ";
			break;
		}
	}
	delete[] dynamicArray;

}