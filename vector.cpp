
#include <iostream>
#include <format> //C++20
#include <vector>
using namespace std;
void printArray(vector<int> sVector) {
	cout << "Массив: ";
	for (int i = 0; i < sVector.size(); i++)
		cout << sVector[i] << " ";
	cout << endl;
}
int addToVector(vector<int>& sVector, int newNumber) {
	sVector.push_back(newNumber);
	return 0;
}
int countMAX(vector<int> sVector, int& maxchislo, int& kolvo) {
	for (int i = 0; i < sVector.size(); i++) {
		int chislo = sVector[i];
		if (maxchislo < chislo) {	
			kolvo = 0;
		}
		if (sVector[i] > maxchislo) {
			maxchislo = sVector[i];
			kolvo++;
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
int dellAllAbsolute(vector<int>& sVector) {
	for (int i = 0; i < sVector.size(); i++) {
		if (findAbsolute(sVector[i]) == 1) {
			sVector.erase(sVector.begin() + i);
			i--;
		}


	}
	return 0;
}
void addToVectorAfterPos(vector<int>& sVector, int newNumber, int poscion) {
	sVector.resize(sVector.size() + 1);
	for (int i = sVector.size() - 1; i > poscion + 1; i--) {
		sVector[i] = sVector[i - 1];
	}
	sVector[poscion + 1] = newNumber;
}
int RemoveFromArray(vector<int> sVector, int& size, int position) {
	if (size <= 0) return -1;
	if (position >= size) return -2;
	for (int i = position; i < size - 1; i++)
		sVector[i + 1] = sVector[i];
	size--;
	return 0;
}
int findInArray(vector<int> sVector, int& size, int toFindNumber) {
	for (int i = 0; i < size; i++)
		if (sVector[i] == toFindNumber)
			return i;
	return -1;
}
int main()
{
	setlocale(0, "");
	int pos;
	int currentStaticSize = 0;
	vector <int> sVector;
	int tempNumber;
	int result;
	int sizeCase7, raznocstCase7;
	int maxchislo = 0;
	int kolvo = 0;

	cout << "1.Вывод вектора \n"
		<< "2.Добавить элемент\n"
		<< "3.Удалить элемент\n"
		<< "4.Найти элемент\n"
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
			printArray(sVector);
			break;
		case'2':
			cout << "Введите число: ";
			cin >> tempNumber;
			addToVector(sVector, tempNumber);
			cout << "Элемент успешно добавлен\n";
			break;
		case'3':
			cout << "Введите позицию: ";
			cin >> tempNumber;
			switch (RemoveFromArray(sVector, currentStaticSize, tempNumber)) {
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
			result = findInArray(sVector, currentStaticSize, tempNumber);
			if (result == -1)cout << "Элемент не найден\n";
			else cout << format("Элемент {:d} найден в позиции {:d}\n", tempNumber, result);
			break;
		case '5':
			cout << "Введите число: ";
			cin >> tempNumber;
			cout << "Введите позицию, после которой добавить число: ";
			cin >> pos;
			addToVectorAfterPos(sVector, tempNumber, pos - 1);
			cout << "Элемент успешно добавлен\n";
			break;
		case '6':
			countMAX(sVector, maxchislo, kolvo);
			cout << format("Максимальный элемент {:d} встречается в массиве {:d} раз(а)", maxchislo, kolvo) << '\n';
			break;
		case '7':
			sizeCase7 = sVector.size();
			dellAllAbsolute(sVector);
			raznocstCase7 = sizeCase7 - sVector.size();
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
