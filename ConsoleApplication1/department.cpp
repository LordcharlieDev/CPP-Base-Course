#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>
#include "department.h"
using namespace std;

int rows = 0;
int cols = 30;
char** allDepart = new char* [rows];
int* moneyDeport;

void PrintMenu()
{
	int g = 0;
	cout << ++g << " - ���������� ���� �����" << endl; //done
	cout << ++g << " - �������� ����� ��� ��� �����������" << endl; //done(�������), ��� ���������� ��� ����������(�� ���)
	cout << ++g << " - ���������� ���� ����� ����� ������������" << endl; //done
	cout << ++g << " - ��������� �� ���� ����� ��������� �����������" << endl; //done
	cout << ++g << " - ������������ ����������� �� ������" << endl; //done
	cout << ++g << " - ������������ ����������� �� �������" << endl; //done
	cout << ++g << " - ����� ����������� � ������ ϲ�" << endl; //done
	cout << ++g << " - ������ ����������� ��������� �����" << endl; //done
	cout << ++g << " - ��������� ������� ����������� � ��������� ����" << endl; //done
	cout << ++g << " - ��������� ���� �������� ����� �� ������" << endl; //done
	cout << ++g << " - ��������� ������� ��� ���������� �����������" << endl; //done
	cout << ++g << " - ����������� ����������� � ����� �� � ���� ��" << endl; //done
	cout << ++g << " - ��������� ���: ������ ����������� �� ������," <<
		"\n������� - ���� �������� ������� ����� � ��������� ���� �� ����" << endl;

	cout << ++g << " - ��������" << endl;
	cout << ++g << " - �����" << endl;
}


bool UniquenessCheckNumber(Company*& myArr, int size, int number)
{
	for (int i = 0; i < size; i++)
	{
		if (myArr[i].number == number)
		{
			return false;
		}
	}
	return true;
}
bool FillArray(Company*& myArr, int& size)
{

	cout << "������ ������� �����������: ";
	int number;
	cin >> number;
	if (number <= 0)
	{
		cout << "Error\a" << endl;
		return false;
	}
	size = number;
	Company* arr = new Company[size];
	for (int i = 0; i < size; i++)
	{
		cout << "������ ϲ� (����� �����):" << endl;
		cin >> arr[i].name;
		cin >> arr[i].surname;
		cin >> arr[i].lastname;
		int number_;
		while (true)
		{
			cout << "������ ��������� �����: ";
			cin >> number_;
			if (UniquenessCheckNumber(myArr, size, number_))
			{
				cin >> arr[i].number;
				break;
			}
			else
			{
				cout << "��� ��������� ����� �� � ���������!\a" << endl;
			}
		}
		cin >> arr[i].department;
		cout << "������ ����: ";
		cin >> arr[i].department;
		cout << "������ ������: ";
		cin >> arr[i].position;
		cout << "������ ��������: ";
		cin >> arr[i].salary;
	}
	myArr = arr;
	return true;
}
void FillDatabase(Company*& myArr, int size)
{
	ofstream of("database.txt");
	if (!of)
	{
		cerr << "������� ���������� �����" << endl;
		return;
	}
	if (!FillArray(myArr, size))
	{
		return;
	}
	for (int i = 0; i < size; i++)
	{
		of << myArr[i].name << " ";
		of << myArr[i].surname << " ";
		of << myArr[i].lastname << " ";
		of << myArr[i].department << " ";
		of << myArr[i].position << " ";
		of << myArr[i].salary << " \n";
	}
}



void SaveDatabase(Company*& myArr, int size)
{
	ofstream of("database.txt");
	if (!of)
	{
		cerr << "������� ���������� �����" << endl;
		return;
	}
	for (int i = 0; i < size; i++)
	{
		of << myArr[i].name << " ";
		of << myArr[i].surname << " ";
		of << myArr[i].lastname << " ";
		of << myArr[i].number << " ";
		of << myArr[i].department << " ";
		of << myArr[i].position << " ";
		of << myArr[i].salary << " \n";
	}
}



int MaxLenName(Company*& myArr, int size)
{
	int maxLen = 0;
	for (int i = 0; i < size; i++)
	{
		if (maxLen < myArr[i].name.length())
		{
			maxLen = myArr[i].name.length();
		}
	}
	return maxLen;
}
int MaxLenSurname(Company*& myArr, int size)
{
	int maxLen = 0;
	for (int i = 0; i < size; i++)
	{
		if (maxLen < myArr[i].surname.length())
		{
			maxLen = myArr[i].surname.length();
		}
	}
	return maxLen;
}
int MaxLenLastname(Company*& myArr, int size)
{
	int maxLen = 0;
	for (int i = 0; i < size; i++)
	{
		if (maxLen < myArr[i].lastname.length())
		{
			maxLen = myArr[i].lastname.length();
		}
	}
	return maxLen;
}
int MaxLenDepart(Company*& myArr, int size)
{
	int maxLen = 0;
	for (int i = 0; i < size; i++)
	{
		int tmpMax = 0;
		for (char* j = myArr[i].department; *j != '\0'; j++)
		{
			tmpMax++;
		}
		if (maxLen < tmpMax)
		{
			maxLen = tmpMax;
		}
	}
	return maxLen;
}
int MaxLenPosition(Company*& myArr, int size)
{
	int maxLen = 0;
	for (int i = 0; i < size; i++)
	{
		int tmpMax = 0;
		for (char* j = myArr[i].position; *j != '\0'; j++)
		{
			tmpMax++;
		}
		if (maxLen < tmpMax)
		{
			maxLen = tmpMax;
		}
	}
	return maxLen;
}
void PrintSpaceString(int num, string str)
{
	for (int j = 1; j <= num - str.length() + 2; j++)
	{
		cout << " ";
	}
}
void PrintSpaceChar(int num, char* str)
{
	for (int j = 1; j <= num - strlen(str) + 2; j++)
	{
		cout << " ";
	}
}
void PrintFile(Company*& myArr, int size)
{
	string name = "Name";
	string surname = "Surname";
	string lastname = "Lastname";
	string number = "RegNum";
	string depart = "Department";
	string position = "Position";
	string salary = "Salary";

	int numName = max(MaxLenName(myArr, size), name.length());
	int numSur = max(MaxLenSurname(myArr, size), surname.length());
	int numLast = max(MaxLenLastname(myArr, size), lastname.length());
	int numDep = max(MaxLenDepart(myArr, size), depart.length());
	int numPos = max(MaxLenPosition(myArr, size), position.length());
	for (int i = -1; i < size; i++)
	{
		if (i < 0)
		{
			cout << name;
			PrintSpaceString(numName, name);
			cout << surname;
			PrintSpaceString(numSur, surname);
			cout << lastname;
			PrintSpaceString(numLast, lastname);
			cout << number;
			PrintSpaceString(numName, number);
			cout << depart;
			PrintSpaceString(numDep, depart);
			cout << position;
			PrintSpaceString(numPos, position);
			cout << salary << endl << endl;
		}
		else
		{
			cout << myArr[i].name;
			PrintSpaceString(numName, myArr[i].name);
			cout << myArr[i].surname;
			PrintSpaceString(numSur, myArr[i].surname);
			cout << myArr[i].lastname;
			PrintSpaceString(numLast, myArr[i].lastname);
			cout << myArr[i].number;
			PrintSpaceString(numName, to_string(myArr[i].number));
			cout << myArr[i].department;
			PrintSpaceChar(numDep, myArr[i].department);
			cout << myArr[i].position;
			PrintSpaceChar(numPos, myArr[i].position);
			cout << myArr[i].salary << endl;
		}
	}
	cout << endl;
}

void FillItemArray(Company*& arr, int size)
{
	bool check = true;
	int ind = size - 1;
	while (check)
	{
		check = false;
		cout << "������ ϲ� (����� �����):" << endl;
		cin >> arr[ind].name;
		cin >> arr[ind].surname;
		cin >> arr[ind].lastname;
		if (arr[ind].name.empty() || arr[ind].surname.empty() || arr[ind].lastname.empty())
		{
			cout << "������ �������� ���!" << endl;
			check = true;
		}
		int number_;
		while (true)
		{
			cout << "������ ��������� �����: ";
			cin >> number_;
			if (UniquenessCheckNumber(arr, size, number_))
			{
				arr[ind].number = number_;
				break;
			}
			else
			{
				cout << "��� ��������� ����� �� � ���������!\a" << endl;
			}
		}
		cout << "������ ����: ";
		cin >> arr[ind].department;
		cout << "������ ������: ";
		cin >> arr[ind].position;
		cout << "������ ��������: ";
		cin >> arr[ind].salary;
	}
}
void AddItemArray(Company*& myArr, int& size)
{
	size++;
	Company* arr = new Company[size];
	for (int i = 0; i < size - 1; i++)
	{
		arr[i] = myArr[i];
	}
	myArr = arr;
}
void ReadDatabase(Company*& myArr, int& size)
{
	ifstream ifs("database.txt");
	if (!ifs)
	{
		cerr << "������� ���������� �����" << endl;
		return;
	}
	for (int i = 0; ; i++)
	{
		if (ifs.eof())
		{
			return;
		}
		AddItemArray(myArr, size);
		ifs >> myArr[i].name;
		ifs >> myArr[i].surname;
		ifs >> myArr[i].lastname;
		ifs >> myArr[i].number;
		ifs >> myArr[i].department;
		ifs >> myArr[i].position;
		ifs >> myArr[i].salary;
	}
}



//4 � 11 �����
void DeleteItemArray(Company*& myArr, int& size)
{
	cout << "������ ��������� ����� ����������� ��� ���������: ";
	int number;
	cin >> number;
	size--;
	int index = -1;
	Company* arr = new Company[size];
	for (int i = 0; i < size + 1; i++)
	{
		if (myArr[i].number == number)
		{
			index = i;
		}
	}
	if (index >= 0)
	{
		for (int i = 0; i < size + 1; i++)
		{
			if (i < index)
			{
				arr[i] = myArr[i];
			}
			if (i > index)
			{
				arr[i - 1] = myArr[i];
			}
		}
		delete[] myArr;
		myArr = arr;
	}
}



void SortByDepart(Company*& myArr, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		bool swapped = false;
		for (int j = 0; j < size - 1 - i; j++) //binary sort
		{
			if (_stricmp(myArr[j].department, myArr[j + 1].department) > 0)
			{
				swapped = true;
				//int tmp = arr[j];
				//arr[j] = arr[j + 1];
				//arr[j + 1] = tmp;

				string tmpName = myArr[j].name;
				myArr[j].name = myArr[j + 1].name;
				myArr[j + 1].name = tmpName;

				string tmpSurname = myArr[j].surname;
				myArr[j].surname = myArr[j + 1].surname;
				myArr[j + 1].surname = tmpSurname;

				string tmpLastname = myArr[j].lastname;
				myArr[j].lastname = myArr[j + 1].lastname;
				myArr[j + 1].lastname = tmpLastname;

				int tmpNum = myArr[j].number;
				myArr[j].number = myArr[j + 1].number;
				myArr[j + 1].number = tmpNum;

				char tmpDepart[30];
				strcpy_s(tmpDepart, myArr[j].department);
				strcpy_s(myArr[j].department, myArr[j + 1].department);
				strcpy_s(myArr[j + 1].department, tmpDepart);

				char tmpPos[30];
				strcpy_s(tmpPos, myArr[j].position);
				strcpy_s(myArr[j].position, myArr[j + 1].position);
				strcpy_s(myArr[j + 1].position, tmpPos);

				int tmpSal = myArr[j].salary;
				myArr[j].salary = myArr[j + 1].salary;
				myArr[j + 1].salary = tmpSal;
			}
		}
		if (!swapped)
		{
			break;
		}
	}
}



void SortByPosition(Company*& myArr, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		bool swapped = false;
		for (int j = 0; j < size - 1 - i; j++) //binary sort
		{
			if (_stricmp(myArr[j].position, myArr[j + 1].position) > 0)
			{
				swapped = true;
				//int tmp = arr[j];
				//arr[j] = arr[j + 1];
				//arr[j + 1] = tmp;

				string tmpName = myArr[j].name;
				myArr[j].name = myArr[j + 1].name;
				myArr[j + 1].name = tmpName;

				string tmpSurname = myArr[j].surname;
				myArr[j].surname = myArr[j + 1].surname;
				myArr[j + 1].surname = tmpSurname;

				string tmpLastname = myArr[j].lastname;
				myArr[j].lastname = myArr[j + 1].lastname;
				myArr[j + 1].lastname = tmpLastname;

				int tmpNum = myArr[j].number;
				myArr[j].number = myArr[j + 1].number;
				myArr[j + 1].number = tmpNum;

				char tmpDepart[30];
				strcpy_s(tmpDepart, myArr[j].department);
				strcpy_s(myArr[j].department, myArr[j + 1].department);
				strcpy_s(myArr[j + 1].department, tmpDepart);

				char tmpPos[30];
				strcpy_s(tmpPos, myArr[j].position);
				strcpy_s(myArr[j].position, myArr[j + 1].position);
				strcpy_s(myArr[j + 1].position, tmpPos);

				int tmpSal = myArr[j].salary;
				myArr[j].salary = myArr[j + 1].salary;
				myArr[j + 1].salary = tmpSal;
			}
		}
		if (!swapped)
		{
			break;
		}
	}
}



void FoundWorkerByNSL(Company*& myArr, int size)
{
	bool flag = false;
	cout << "������ ϲ� ����������� ������: ";
	char name[30];
	char surname[30];
	char lastname[30];
	cin >> name >> surname >> lastname;
	for (int i = 0; i < size + 1; i++)
	{
		char myName[30];
		char mySurname[30];
		char myLastname[30];
		strcpy_s(myName, myArr[i].name.c_str());
		strcpy_s(mySurname, myArr[i].surname.c_str());
		strcpy_s(myLastname, myArr[i].lastname.c_str());

		if (_stricmp(name, myName) == 0 && _stricmp(surname, mySurname) == 0 && _stricmp(lastname, myLastname) == 0)
		{
			flag = true;
			cout << myArr[i].name << "\t";
			cout << myArr[i].surname << "\t";
			cout << myArr[i].lastname << "\t";
			cout << myArr[i].number << "\t";
			cout << myArr[i].department << "\t";
			cout << myArr[i].position << "\t";
			cout << myArr[i].salary << "\n";
		}
	}
	if (!flag)
	{
		cout << "�� ��������!" << endl;
	}
	cout << endl << endl;
}



void FoundWorkedByDepart(Company*& myArr, int size)
{
	bool flag = false;
	cout << "������ ���� ��� ��������� ���������� ��� �����������: ";
	string depart;
	cin >> depart;

	string name = "Name";
	string surname = "Surname";
	string lastname = "Lastname";
	string number = "RegNum";
	string position = "Position";
	string salary = "Salary";

	int numName = max(MaxLenName(myArr, size), name.length());
	int numSur = max(MaxLenSurname(myArr, size), surname.length());
	int numLast = max(MaxLenLastname(myArr, size), lastname.length());
	int numPos = max(MaxLenPosition(myArr, size), position.length());
	for (int i = 0; i < size + 1; i++)
	{
		if (depart == (string)myArr[i].department)
		{
			if (!flag)
			{
				cout << name;
				PrintSpaceString(numName, name);
				cout << surname;
				PrintSpaceString(numSur, surname);
				cout << lastname;
				PrintSpaceString(numLast, lastname);
				cout << number;
				PrintSpaceString(numName, number);
				cout << position;
				PrintSpaceString(numPos, position);
				cout << salary << endl << endl;
			}
			flag = true;
			cout << myArr[i].name;
			PrintSpaceString(numName, myArr[i].name);
			cout << myArr[i].surname;
			PrintSpaceString(numSur, myArr[i].surname);
			cout << myArr[i].lastname;
			PrintSpaceString(numLast, myArr[i].lastname);
			cout << myArr[i].number;
			PrintSpaceString(numName, to_string(myArr[i].number));
			cout << myArr[i].position;
			PrintSpaceChar(numPos, myArr[i].position);
			cout << myArr[i].salary << endl;
		}
	}
	if (!flag)
	{
		cout << "�� ��������!" << endl;
	}
	cout << endl;
}



void AmountWorkerInDepart(Company*& myArr, int size)
{
	cout << "������ ���� ��� ���������� ������� �����������: ";
	string depart;
	cin >> depart;
	int count = 0;
	for (int i = 0; i < size + 1; i++)
	{
		if (depart == (string)myArr[i].department)
		{
			count++;
		}
	}
	if (count == 0)
	{
		cout << "�� ��������!" << endl;
	}
	else
	{
		cout << "� ���� " << depart << " " << count << " ����������" << endl;
	}
	cout << endl << endl;
}


void AddWord(char* word)
{
	rows++;
	char** temp = new char* [rows];
	for (int i = 0; i < rows - 1; i++)
	{
		temp[i] = allDepart[i];
	}
	temp[rows - 1] = word;
	delete[] allDepart;
	allDepart = temp;
}
bool FoundDepart(char* item)
{
	for (int i = 0; i < rows; i++)
	{
		if (_stricmp(allDepart[i], item) == 0)
		{
			return true;
		}
	}
	return false;
}
void FoundAllDepart(Company*& myArr, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (!FoundDepart(myArr[i].department))
		{
			AddWord(myArr[i].department);
		}
	}
}
void TotalMoneyByDepart(Company*& myArr, int size)
{
	moneyDeport = new int[rows] {};
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (_stricmp(allDepart[i], myArr[j].department) == 0)
			{
				moneyDeport[i] += myArr[j].salary;
			}
		}
	}

	cout << "���� �������� ����� �� ������: " << endl;
	for (int i = 0; i < rows; i++)
	{
		cout << allDepart[i] << ": " << moneyDeport[i] << endl;
	}
	cout << endl;
}



void ReplaceDepartByWorker(Company*& myArr, int size)
{
	cout << "������ ϲ� ����������� ��� ����������� � ����� ����: ";
	string name;
	string surname;
	string lastname;
	int index = -1;
	cin >> name >> surname >> lastname;
	for (int i = 0; i < size + 1; i++)
	{
		if (name == myArr[i].name && surname == myArr[i].surname && lastname == myArr[i].lastname)
		{
			index = i;
			break;
		}
	}
	cout << "������ ����� ����� � ���� ���������� ����������:" << endl;
	char department[30];
	cin >> department;
	if (index >= 0)
	{
		strcpy_s(myArr[index].department, department);
	}
}



void TotalMoneyByCompany()
{
	int totalMoney = 0;
	for (int i = 0; i < rows; i++)
	{
		totalMoney += moneyDeport[i];
	}
	cout << "���� �������� ����� �����:" << endl;
	cout << totalMoney << endl << endl;
}

void PrintWorkerByDepart(Company*& myArr, int size, char* depart)
{
	string name = "Name";
	string surname = "Surname";
	string lastname = "Lastname";
	string number = "RegNum";
	string position = "Position";
	string salary = "Salary";

	int numName = max(MaxLenName(myArr, size), name.length());
	int numSur = max(MaxLenSurname(myArr, size), surname.length());
	int numLast = max(MaxLenLastname(myArr, size), lastname.length());
	int numPos = max(MaxLenPosition(myArr, size), position.length());
	for (int i = -1; i < size; i++)
	{
		if (i < 0)
		{
			cout << name;
			PrintSpaceString(numName, name);
			cout << surname;
			PrintSpaceString(numSur, surname);
			cout << lastname;
			PrintSpaceString(numLast, lastname);
			cout << number;
			PrintSpaceString(numName, number);
			cout << position;
			PrintSpaceString(numPos, position);
			cout << salary << endl << endl;
		}
		else
		{
			if (_stricmp(myArr[i].department, depart) == 0)
			{
				cout << myArr[i].name;
				PrintSpaceString(numName, myArr[i].name);
				cout << myArr[i].surname;
				PrintSpaceString(numSur, myArr[i].surname);
				cout << myArr[i].lastname;
				PrintSpaceString(numLast, myArr[i].lastname);
				cout << myArr[i].number;
				PrintSpaceString(numName, to_string(myArr[i].number));
				cout << myArr[i].position;
				PrintSpaceChar(numPos, myArr[i].position);
				cout << myArr[i].salary << endl;
			}
		}
	}
	cout << endl;
}
void ReadDepartment(Company*& myArr, int size)
{
	for (int i = 0; i < rows; i++)
	{
		cout << "³��� " << allDepart[i] << ":" << endl;
		PrintWorkerByDepart(myArr, size, allDepart[i]);
		cout << endl;
	}
}

int CheckMenu(Company*& myArr, int& size)
{
	PrintMenu();
	int number = 0;
	cin >> number;
	int g = 0;
	if (++g == number)//1
	{
		FillDatabase(myArr, size);
	}
	else if (++g == number)//2
	{
		PrintFile(myArr, size);
	}
	else if (++g == number)//3
	{
		AddItemArray(myArr, size);
		FillItemArray(myArr, size);
	}
	else if (++g == number)//4
	{
		DeleteItemArray(myArr, size);
	}
	else if (++g == number)//5
	{
		SortByDepart(myArr, size);
	}
	else if (++g == number)//6
	{
		SortByPosition(myArr, size);
	}
	else if (++g == number)//7
	{
		FoundWorkerByNSL(myArr, size);
	}
	else if (++g == number)//8
	{
		FoundWorkedByDepart(myArr, size);
	}
	else if (++g == number)//9
	{
		AmountWorkerInDepart(myArr, size);
	}
	else if (++g == number)//10
	{
		FoundAllDepart(myArr, size);
		TotalMoneyByDepart(myArr, size);
	}
	else if (++g == number)//11
	{
		DeleteItemArray(myArr, size);
	}
	else if (++g == number)//12
	{
		ReplaceDepartByWorker(myArr, size);
	}
	else if (++g == number)//13
	{
		//�������

		FoundAllDepart(myArr, size);
		TotalMoneyByDepart(myArr, size);
		TotalMoneyByCompany();
		ReadDepartment(myArr, size);
	}
	else if (++g == number)//14
	{
		SaveDatabase(myArr, size);
		system("cls");
		cout << "���������!" << endl;
	}
	else if (++g == number)//15
	{
		system("cls");
		cout << "�����" << endl;
		SaveDatabase(myArr, size);
	}
	else
	{
		system("cls");
		cout << "Error\a\a" << endl;
		system("pause");
		return 0;
	}
	system("pause");
	return number;
}
