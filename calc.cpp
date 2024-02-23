#include <iostream>
#include <format>
#include <string>
#include <vector>
using namespace std;
bool isPrime(int n) {
	for (int i = 2; i < sqrt(n); i++) {
		if (n % i == 0) {
			return 0;
			break;
		}

	}
	return 1;
}
float addition(float firstchislo, float secondchislo)
{
	return firstchislo + secondchislo;
}
float subtraction(float firstchislo, float secondchislo)
{
	return firstchislo - secondchislo;
}
float division(float firstchislo, float secondchislo)
{
	float otvet = (firstchislo / secondchislo);
	return otvet;
}
float multiplication(float firstchislo, float secondchislo)
{
	return firstchislo * secondchislo;
}
float exponentiation(float firstchislo, float secondchislo)
{
	return pow(firstchislo, secondchislo);
}
int allDelit(int n)
{
	vector<int> Deliteli;
	for (int i = 2; i < n; i++) {
		if (n % i == 0) {
			Deliteli.push_back(i);
		}
	}
	if (Deliteli.size() == 0) { return -1; }
	for (size_t i = 0; i < Deliteli.size(); i++) {
		cout << Deliteli[i] << " ";
	}

}
void doubleSS(int SS, int n) {
	string z;

	while (n != 0)
	{
		int ostatok = n % SS;
		if (ostatok > 9) {
			switch (ostatok)
			{
			case 10:
				z += ('A');
				break;
			case 11:
				z += ('B');
				break;
			case 12:
				z += ('C');
				break;
			case 13:
				z += ('D');
				break;
			case 14:
				z += ('E');
				break;
			case 15:
				z += ('F');
				break;
			case 16:
				z += ('G');
				break;
			case 17:
				z += ('H');
				break;
			case 18:
				z += ('I');
				break;
			case 19:
				z += ('G');
				break;
			case 20:
				z += ('K');
				break;
			case 21:
				z += ('L');
				break;
			case 22:
				z += ('M');
				break;
			case 23:
				z += ('N');
				break;
			case 24:
				z += ('O');
				break;
			case 25:
				z += ('P');
				break;
			case 26:
				z += ('Q');
				break;
			case 27:
				z += ('R');
				break;
			case 28:
				z += ('S');
				break;
			case 29:
				z += ('T');
				break;
			case 30:
				z += ('U');
				break;
			case 31:
				z += ('V');
				break;
			case 32:
				z += ('W');
				break;
			case 33:
				z += ('X');
				break;
			case 34:
				z += ('Y');
				break;
			case 35:
				z += ('Z');
				break;
			default:
				cout << "ToO big number:):):) \n";
				break;
			}
			n /= SS;
		}
		else {
			z += (to_string(ostatok));
			n /= SS;
		}
	}
	reverse(z.begin(), z.end());
	for (int i = 0; i < z.size(); i++) {
		cout << z[i];
	}
}
int main()
{
	setlocale(0, "");
	char operation, sub_operation;
	string sub_otvet_str;
	bool sub_true = false;
	float second_chislo, otvet;
	int sub_otvet, SS;
	cout << "Введите первое число: ";
	cin >> otvet;
	while (true)
	{
		cout << "Введите операцию (+;-;/;*;^) or M: ";
		cin >> operation;
		switch (operation)
		{
		case '+':
			cout << "Введите число: ";
			cin >> second_chislo;
			otvet = addition(otvet, second_chislo);
			cout << "Ответ: " << otvet << "\n";
			break;
		case '-':
			cout << "Введите число: ";
			cin >> second_chislo;
			otvet = subtraction(otvet, second_chislo);
			cout << "Ответ: " << otvet << "\n";
			break;
		case '/':
			cout << "Введите число: ";
			cin >> second_chislo;
			otvet = division(otvet, second_chislo);
			cout << "Ответ: " << otvet << "\n";
			break;
		case '*':
			cout << "Введите число: ";
			cin >> second_chislo;
			otvet = multiplication(otvet, second_chislo);
			cout << "Ответ: " << otvet << "\n";
			break;
		case '^':
			cout << "Введите число: ";
			cin >> second_chislo;
			otvet = exponentiation(otvet, second_chislo);
			cout << "Ответ: " << otvet << "\n";
			break;
		case 'M':
			sub_true = true;
			while (sub_true) {
				cout << "Выберите дополнительную функцию: \n"
					<< "1.Проверка на простоту \n"
					<< "2.Проверка на палиндром\n"
					<< "3.Нахождение всех делителей\n"
					<< "4.Перевод в произвольную СС\n"
					<< "0.Выход: ";
				cin >> sub_operation;

				switch (sub_operation)
				{
				case '1':
					if (isPrime(otvet) == 1) {
						cout << "ЧИСЛО " << otvet << " ПРОСТОЕ \n";
						break;
					}
					else
					{
						cout << "ЧИСЛО " << otvet << " НЕ ПРОСТОЕ\n";
						break;
					}
					break;
				case '2':
					sub_otvet = (int)otvet;
					sub_otvet_str = to_string(sub_otvet);
					reverse(sub_otvet_str.begin(), sub_otvet_str.end());
					if (sub_otvet == stoi(sub_otvet_str)) {
						cout << "ПОЛИНДРОМ \n";
					}
					else { cout << "НЕ ПОЛИНДРОМ \n"; }
					break;
				case '3':
					if (allDelit((int)otvet) == -1) { cout << "Делителей нет!"; }
					cout << endl;
					break;
				case '4':
					cout << "ВВЕДИТЕ ЖЕЛАЕМУЮ СС(2-35): ";
					cin >> SS;
					doubleSS(SS, (int)otvet);
					cout << endl;
					break;
				case '0':
					sub_true = 0;
					break;
				default:
					cout << "ТАКОЙ ФУНКЦИИ НЕ СУЩЕСТВУЕТ \n";
					break;
				}
			}
			break;
		case '0':
			return 0;
		default:
			cout << "Неверный ввод! \n";
			break;
		}
	}

}

