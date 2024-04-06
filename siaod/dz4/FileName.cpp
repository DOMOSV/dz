#include "FileName.h"
MyStruct::MyStruct()
{

}
MyStruct::MyStruct(const char *_punkt_vileta, int _num_reica, const char* _data_prileta, const char* _vremya_prileta, const char* _info_about_zaderzka_prilet)
{
	num_reica = _num_reica;
	strncpy(punkt_vileta, _punkt_vileta, _TRUNCATE);
	strncpy(data_prileta, _data_prileta, _TRUNCATE);
	strncpy(vremya_prileta, vremya_prileta, _TRUNCATE);
	strncpy(info_about_zaderzka_prilet, info_about_zaderzka_prilet, _TRUNCATE);
}
void MyStruct::printer()
{

	format("|{:^7}|{:<15s}|{:<20s}|{:<20s}|{:^5}|",
		punkt_vileta,
		num_reica,
		data_prileta,
		vremya_prileta,
		info_about_zaderzka_prilet);
  
}
