#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>
#include "department.h"
using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Company* myArr;
	int Size = 0;
	ReadDatabase(myArr, Size);
	Size--;
	int number = 0;
	while (number != 15)
	{
		system("cls");
		number = CheckMenu(myArr, Size);
	}
	delete[] myArr;
	system("pause");
	return 0;
}