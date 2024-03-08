#include <iostream>
#include<format>
using namespace std;
void printer(int stroka, int stolbec, int** arr)
{
	for (int i = 0; i < stroka; i++)
	{
		for (int j = 0; j < stolbec;j++) 
		{
			cout<<arr[i][j]<<" ";
		}
		cout << endl;
	}
}
void fillArray(int stroka, int stolbec, int** arr) 
{	
	int curchislo;
	for (int i = 0; i < stroka; i++)
	{
		for (int j = 0; j < stolbec; j++)
		{
			cin >> curchislo;
			arr[i][j] = curchislo;
		}
		
	}
}
void automaticFill(int stroka,int stolbec,int** arr)
{
	for (int i = 0; i < stroka; i++)
	{
		for (int j = 0; j < stolbec; j++)
		{
			arr[i][j] = rand();
		}

	}
}
void deleteArray(int stroka,int** arr) {
	for (int i = 0; i < stroka; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
}
void findDifference(int stroka, int stolbec, int** arr) 
{
	int** arr2 = new int* [stroka];
	for (int i = 0; i < stroka; i++)
	{
		arr2[i] = new int[stolbec];
	}
	cout << "Заполнить новый массив автоматически(1) или вручную?(2): ";
	int gg;
	bool z = true;
	cin >> gg;
	while (z)
	{
		switch (gg)
		{
		case 1:
			automaticFill(stroka, stolbec, arr2);
			z = false;
			cout << "\nНовый массив: \n";
			printer(stroka, stolbec, arr2);
			cout << "\n";
			break;
		case 2:
			fillArray(stroka, stolbec, arr2);
			z = false;
			break;
		default:
			cout << "Неверный ввод \n";
			break;
		}
	}
	cout << "Разность двух массивов: " << endl;
	for (int i = 0; i < stroka; i++)
	{
		for (int j = 0; j < stolbec; j++)
		{

			cout << arr[i][j] - arr2[i][j] << " ";
		}
		cout << endl;

	}
	deleteArray(stroka, arr2);
}
int main()
{	
	setlocale(0, "");
	int stroka, stolbec,case1,menu;
	
	cout << "Введите количество строк: ";
	cin >> stroka;
	cout << "Введите количество стобцов: ";
	cin >> stolbec;
	case1 = stroka * stolbec;
	cout << endl;
	int** arr = new int* [stroka];	
	for (int i = 0; i < stroka; i++) 
	{
		arr[i] = new int[stolbec];
	}

	while(true)
	{
		cout << "1. Ручное заполнение массива\n"
			<< "2. Автоматическое заполнение массива\n"
			<< "3. Печать массива\n"
			<< "4. Нахождение разницы между массивами\n"
			<< "0. Выход:";
		cin >> menu;
		switch (menu)
		{
		case 1:
			cout << format("Введите {:d} значений: ", case1);
			fillArray(stroka, stolbec, arr);
			cout << endl;
			break;
		case 2:
			cout << "\n";
			automaticFill(stroka, stolbec, arr);
			cout << "Массив успешно заполнен \n\n";
			break;
		case 3:
			cout << "\n" << "Массив: " << endl;
			printer(stroka, stolbec, arr);
			cout << endl;
			break;
		case 4:
			findDifference(stroka, stolbec, arr);
			cout << endl;
			break;
		case 0:
			return 0;
		default:
			cout << "Неверный ввод! \n"
				<< "1. Ручное заполнение массива\n"
				<< "2. Автоматическое заполнение массива\n"
				<< "3. Печать массива\n"
				<< "4. Нахождение разницы между массивами\n"
				<< "0. Выход:";
				
			break;
		}
	}
}
