#include "myString.h"
#include <iostream>
using namespace std;

//■ Конструктор за замовчуванням, що дозволяє створити рядок довжиною 80 символів;
myString::myString() :myString(80) {}

//■ Конструктор, що дозволяє створювати рядок довільного розміру;
myString::myString(int size)
{
	if (size > 0)
	{
		this->size = size+1;
		this->str = new char[this->size];
		this->str[this->size] = '\0';
		counterObject++;
	}
}
//■ Конструктор, який створює рядок і ініціалізує його рядком, отриманим від користувача.
myString::myString(char* str)
{
	if (str != nullptr)
	{
		for (int i = 0; str[i] != '\0'; i++)
		{
			if (str[i] != '\0')
			{
				this->size++;
			}
		}
		size++;
		this->str = new char[size];
		strcpy_s(this->str, size, str);
		counterObject++;
	}
}
// Конструктор копирования
myString::myString(const myString& str)
{
	this->size = str.size;
	this->str = new char[this->size];
	for (int i = 0; i < this->size; i++)
	{
		this->str[i] = str.str[i];
	}
	counterObject++;
}

// Деструктор (очищает память если не пустой)
myString::~myString()
{
	if (str != nullptr)
	{
		delete[] str;
	}
}

//Клас повинен містити методи для введення рядків з
//клавіатури
void myString::input()
{
	this->size = 0;
	int const mesSize = 100;
	char newMes[mesSize];
	cout << "Enter message!" << endl;
	cin.getline(newMes, mesSize - 1);
	for (int i = 0; newMes[i] != '\0'; i++)
	{
		if (newMes[i]!='\0')
		{
			this->size++;
		}
		else 
		{
			break;
		}
	}
	this->str = new char[size+1];
	for (int i = 0; i < size; i++)
	{
		this->str[i] = newMes[i];
	}
	this->str[size] = '\0';

}

//метод оутпут виведення рядків на екран
void myString::output()
{
	if (this->str != nullptr)
	{
		for (int i = 0; i < this->size; i++)
		{
			cout << str[i];
		}
		cout << endl;
	}
}

int myString::getSize()
{
	return this->size;
}

char* myString::getStr()
{
	char* strCopy = new char[this->size];
	for (int i = 0; i < size; i++)
	{
		strCopy[i] = this->str[i];
	}
	strCopy[size] = '\0';
	return strCopy;
}

int myString::getCoutObj()
{
	return counterObject;
}

int myString::counterObject = 0; // инициализация статического поля