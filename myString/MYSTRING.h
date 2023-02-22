#pragma once

#include <iostream>
#include <cstring>
#include <string.h>

class mySTRING
{
	char* str;
	int SIZE;

public:
	mySTRING();
	mySTRING(char* uStr);
	mySTRING(const mySTRING& str);

	~mySTRING();

	int   getStrSize() const;
	char* getString() const;

	void setString(char* ui);

	mySTRING& operator=(mySTRING& right);
	char& operator[](int index);
	bool operator==(const mySTRING& c_string);
	friend std::ostream& operator<<(std::ostream& left, const mySTRING& right);
	friend std::istream& operator>>(std::istream& left, mySTRING& right);
};