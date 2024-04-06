#include <iostream>
#include <string>
using namespace std;
void addToCharToReform(char* stroka, int& size, char hz)
{
    stroka[size] = hz;
    size++;
    stroka[size] = '\0';
}
void reformChar(char* stroka, int& size)
{
    int size_char = 0;
    char* temp_char = new char[size_char];
    int size_newChar = 0;
    char* new_char = new char[size_newChar];
    new_char[0] = NULL;
    temp_char[0] = NULL;
    for (int i = 0; i < size; i++)
    {
        addToCharToReform(temp_char, size_char, stroka[i]);
        if ((int)stroka[i] == (int)' ' || (int)stroka[i] == (int)',')
        {
            bool flag = true;
            for (int i = 0; i < size_char; i++)
            {
                if ((int)temp_char[i] == '-' && size_char == 1)
                {
                    flag = false;
                }
                if ((int)temp_char[i] == '-' && size_char != 1)
                {
                    continue;
                }
                if ((int)temp_char[i] != (int)' ' && (int)temp_char[i] != (int)',')
                {
                    if ((int)temp_char[i] < 47 || (int)temp_char[i]>57)
                    {
                        flag = false;
                        break;
                    }
                }
                else
                {
                    break;
                }
            }
            if (flag)
            {
                int tempChislo = atoi(temp_char);
                if (tempChislo < 101 && -101 < tempChislo)
                {
                    strcat(new_char, "*,");
                    temp_char[0] = NULL;
                    size_char = 0;
                }
                else
                {
                    strcat(new_char, temp_char);
                    temp_char[0] = NULL;
                    size_char = 0;
                }
            }
            else
            {
                strcat(new_char, temp_char);
                temp_char[0] = NULL;
                size_char = 0;
            }
        }
    }
    cout << "Измененная строка: " << new_char << "\n";

}
void reformStr(string stroka)
{
    string temp_num;
    string new_str;
    for (char c : stroka) {
        temp_num += c;
        if ((int)c == (int)' ' || (int)c == (int)',')
        {
            bool flag = true;
            for (int i = 0; i < temp_num.size(); i++)
            {
                if ((int)temp_num[i] == '-' && temp_num.size() == 1)
                {
                    flag = false;
                }
                if ((int)temp_num[i] == '-' && temp_num.size() != 1)
                {
                    continue;
                }
                if ((int)temp_num[i] != (int)' ' && (int)temp_num[i] != (int)',')
                {
                    if ((int)temp_num[i] < 47 || (int)temp_num[i]>57)
                    {
                        flag = false;
                        break;
                    }
                }
                else
                {
                    break;
                }
            }
            if (flag)
            {
                int tempChislo = stoi(temp_num);
                if (tempChislo < 101 && -101 < tempChislo)
                {
                    new_str += "* ";
                    temp_num.clear();
                }
                else
                {
                    new_str += temp_num;
                    temp_num.clear();

                }
            }
            else
            {
                new_str += temp_num;
                temp_num.clear();
            }
        }
    }

    cout << "Измененная строка: " << new_str<<"\n";
}
void addToChar(char* stroka, int& size)
{
    cout<< "Введите число: ";
    char temp;
    cin >> temp;
    stroka[size] = temp;
    size++;
    stroka[size] = '\0';
}
void add_to_str(string& stroka)
{
    string temp_str;
    cout << "Введите строку: ";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, temp_str);
    stroka += temp_str;
    
}
int main()
{
    string stroka;
    bool case2 = true;
    bool case1 = true;
    char menu;
    int size = 0;
    char* charovka = new char[size];
    cout << "1 string\n"
         << "2 char: ";
    cin >> menu;

    setlocale(0, "");
    switch (menu)
    { 
        case '1':
        {
            while (case1)
            {
                cout << "1.Ввод значений\n"
                    << "2.Замена значений: ";
                cin >> menu;
                switch (menu)
                {
                case '1':
                    add_to_str(stroka);
                    cout << stroka<<"\n";
                    break;
                case '2':
                    reformStr(stroka);
                    break;
                case'3':
                    case1 = false;
                default:
                    break;
                }
            }
        }
        case '2':
        {

        
            while (case2)
            {
                cout << "1.Ввод значений\n"
                    << "2.Замена значений: ";
                cin >> menu;

                switch (menu)
                {
                case '1':
                    addToChar(charovka, size);
                    break;
                case '2':
                    reformChar(charovka, size);
                    break;
                case'3':
                    case2 = false;
                default:
                    break;
                }
            }
        default:
            cout << "Гон";
            break;
        }
    }
}