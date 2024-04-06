#include <string>
#include <iostream>
#include <format>
using namespace std;
struct MyStruct
{
	MyStruct()=default;
	MyStruct(const char* _punkt_vileta, int _num_reica, const char* _data_prileta, const char* _vremya_prileta, const char* _info_about_zaderzka_prilet);
	char* punkt_vileta = new char[20];
	int num_reica;
	char data_prileta[5];
	char vremya_prileta[5];
	char info_about_zaderzka_prilet[2];
	void printer();
};
