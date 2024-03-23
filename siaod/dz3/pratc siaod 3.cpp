#include <iostream>
#include <string>
using namespace std;
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
                if ((int)temp_num[i]=='-' && temp_num.size()!=1)
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
    cout << new_str;
}
int main()
{
    int menu;
    cout << "1 string\n"
         << "2 char";
    cin >> menu;

    setlocale(0, "");
    switch (menu)
    {
    case 1:
    {
        string stroka;
        getline(cin, stroka);
        reformStr(stroka);
        break;
    }
    case 2:
    {
        int size = 0;
        char* stroka = new char[size];
        
        cin >> menu;
        cout << "1.Ввод значений\n"
             << "2.Замена значений: ";
                
        switch (menu)
        {
        
        default:
            break;
        }
        break;
    }
    default:
        cout << "Гон";
        break;
    }
    
    
};
