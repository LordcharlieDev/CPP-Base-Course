#pragma once
#include <string>
using namespace std;

struct Company
{
	string name = "empty";
	string surname = "empty";
	string lastname = "empty";
	int number = 0;
	char department[30] = "empty";
	char position[30] = "empty";
	int salary = 0;
};

void PrintMenu();
bool UniquenessCheckNumber(Company*& myArr, int size, int number);
bool FillArray(Company*& myArr, int& size);
void FillDatabase(Company*& myArr, int size);
void SaveDatabase(Company*& myArr, int size);
int MaxLenName(Company*& myArr, int size);
int MaxLenSurname(Company*& myArr, int size);
int MaxLenLastname(Company*& myArr, int size);
int MaxLenDepart(Company*& myArr, int size);
int MaxLenPosition(Company*& myArr, int size);
void PrintSpaceString(int num, string str);
void PrintSpaceChar(int num, char* str);
void PrintFile(Company*& myArr, int size);
void FillItemArray(Company*& arr, int size);
void AddItemArray(Company*& myArr, int& size);
void ReadDatabase(Company*& myArr, int& size);
void DeleteItemArray(Company*& myArr, int& size); //4 і 11 пункт
void SortByDepart(Company*& myArr, int size);
void SortByPosition(Company*& myArr, int size);
void FoundWorkerByNSL(Company*& myArr, int size);
void FoundWorkedByDepart(Company*& myArr, int size);
void AmountWorkerInDepart(Company*& myArr, int size);
void AddWord(char* word);
bool FoundDepart(char* item);
void FoundAllDepart(Company*& myArr, int size);
void TotalMoneyByDepart(Company*& myArr, int size);
void ReplaceDepartByWorker(Company*& myArr, int size);
void TotalMoneyByCompany();
void PrintWorkerByDepart(Company*& myArr, int size, char* depart);
void ReadDepartment(Company*& myArr, int size);
int CheckMenu(Company*& myArr, int& size);