#include <iostream>
#include <format> //C++20
#include <vector>
using namespace std;
void printVec(vector<int> sVector) {
	cout << "Вектор: ";
	for (int i = 0; i < sVector.size(); i++)
		cout << sVector[i] << " ";
	cout << endl;
}

int addToVector(vector<int>& sVector, int newNumber) {
	sVector.push_back(newNumber);
	return 0;
}
int countMAX(vector<int> sVector, int& maxchislo, int& kolvo) {
	kolvo = 0;
	maxchislo = 0;
	for (int i = 0; i < sVector.size(); i++) {
		int chislo = sVector[i];
		if (maxchislo < chislo) {
			kolvo = 0;
		}
		if (sVector[i] >= maxchislo) {
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
		if (isAbsolute(sVector[i]) == 1) {
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
int main()
{
	setlocale(0, "");
	int currentStaticSize = 0;
	vector <int> sVector;
	int tempNumber, pos,result,sizeCase7, raznocstCase7,maxchislo = 0,kolvo = 0;

	cout << "1.Вывод вектора \n"
		<< "2.Добавить элемент\n"
		<< "5.Вставить элемент после заданного элемента\n"
		<< "6.Количество максимальных чисел в векторе\n"
		<< "7.Удалить все совершенные\n"
		<< "0.Выход\n";

	char menu;
	while (true) {
		cout << "Выберите действие: ";
		cin >> menu;
		switch (menu) {
		case'1':
			printVec(sVector);
			break;
		case'2':
			cout << "Введите число: ";
			cin >> tempNumber;
			addToVector(sVector, tempNumber);
			cout << "Элемент успешно добавлен\n";
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
				<< "5.Вставить элемент после заданного элемента\n"
				<< "6.Количество максимальных чисел в векторе\n"
				<< "7.Удалить все совершенные\n"
				<< "0. выход\n"
				<< "Выберите действие: ";
			break;
		}
	}

}
