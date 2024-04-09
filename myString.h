#pragma once
class myString
{
	char* str;
	int size;
	static int counterObject;
public:
	myString();
	myString(int size);
	myString(char* str);
	myString(const myString& res);
	~myString();
	void input();
	void output();
	int getSize();
	char* getStr();
	static int getCoutObj();
};