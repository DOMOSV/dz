#include <iostream>
#include<format>
#include <vector>
using namespace std;
int printer(int stroka, int stolbec, vector <vector <int>> vec)
{
	if (vec.size() < (stroka)) 
	{
		return -1;
	}
	cout << "\n" << "вектор: " << endl;
	for (int i = 0; i < stroka; i++)
	{
		for (int j = 0; j < stolbec; j++)
		{
			cout << vec[i][j] << " ";
		}
		cout << endl;
	}
}
void fillVector(int stroka, int stolbec, vector <vector <int>> &vec)
{
	int curchislo;
	for (int i = 0; i < stroka; i++)
	{
		vector<int> temp;
		for (int j = 0; j < stolbec; j++)
		{
			cin >> curchislo;
			temp.push_back(curchislo);
		}
		vec.push_back(temp);

	}
}
void automaticFill(int stroka, int stolbec, vector <vector <int>> &vec)
{
	for (int i = 0; i < stroka; i++)
	{
		vector<int> temp;
		for (int j = 0; j < stolbec; j++)
		{
			temp.push_back(rand());
		}
		vec.push_back(temp);

	}
}
int findDifference(int stroka, int stolbec, vector <vector <int>> vec)
{
	if (vec.size() < (stroka))
	{
		return -1;
	}
	cout << "Заполнить новый вектор автоматически(1) или вручную?(2): ";
	int gg;
	bool z = true;
	cin >> gg;
	vector<vector<int>> vec2;
	while (z)
	{
		switch (gg)
		{
		case 1:
			automaticFill(stroka, stolbec, vec);
			z = false;
			cout << "\nНовый вектор: \n";
			printer(stroka, stolbec, vec2);
			cout << "\n";
			break;
		case 2:
			fillVector(stroka, stolbec, vec2);
			z = false;
			cout << "\n";
			break;
		default:
			cout << "Неверный ввод \n";
			break;
		}
	}
	cout << "Разность двух векторов: " << endl;
	for (int i = 0; i < stroka; i++)
	{
		for (int j = 0; j < stolbec; j++)
		{

			cout << vec[i][j] - vec2[i][j] << " ";
		}
		cout << endl;
	}
}
int main()
{
	setlocale(0, "");
	int stroka, stolbec, case1, menu;

	cout << "Введите количество строк: ";
	cin >> stroka;
	cout << "Введите количество стобцов: ";
	cin >> stolbec;
	case1 = stroka * stolbec;
	cout << endl;
	vector <vector <int>> vec;
	while (true)
	{
		cout << "1. Ручное заполнение вектора\n"
			<< "2. Автоматическое заполнение вектора\n"
			<< "3. Печать вектора\n"
			<< "4. Нахождение разницы между векторами\n"
			<< "0. Выход:";
		cin >> menu;
		switch (menu)
		{
		case 1:
			cout << format("Введите {:d} значений: ", case1);
			fillVector(stroka, stolbec, vec);
			cout << endl;
			break;
		case 2:
			cout << "\n";
			automaticFill(stroka, stolbec, vec);
			cout << "вектор успешно заполнен \n\n";
			break;
		case 3:
			if (printer(stroka, stolbec, vec) == -1) { cout << "\nВектор не заполнен\n"; };
			cout << endl;
			break;
		case 4:
			if (findDifference(stroka, stolbec, vec) == -1) { cout << " \nВектор не заполнен\n"; };
			cout << endl;
			break;
		case 0:
			return 0;
		default:
			cout << "Неверный ввод! \n"
				<< "1. Ручное заполнение вектора\n"
				<< "2. Автоматическое заполнение вектора\n"
				<< "3. Печать вектора\n"
				<< "4. Нахождение разницы между векторами\n"
				<< "0. Выход:";

			break;
		}
	}
}
