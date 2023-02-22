#include "MYSTRING.h"

mySTRING::mySTRING()
{
	std::cout << "Default Constructing...\n";
	SIZE = 0;
	//Anti gia: "str = nullptr;" einai pio kompso na graposoume
	str = new char[1];
	str[0] = '\0';
}

mySTRING::mySTRING(char* uStr)
{
	std::cout << "Constructing...\n";

	SIZE = strlen(uStr) + 1;
	str = new char[SIZE];
	if (!str)
	{
		std::cout << "ERROR! No memory allocated for the string\n";
	}
	else
	{
		strcpy_s(str, SIZE, uStr);
	}
}

mySTRING::mySTRING(const mySTRING& cStr)
{
	std::cout << "Copy Constructing...\n";

	SIZE = cStr.getStrSize();
	str = new char[SIZE + 1];
	if (!str)
	{
		std::cout << "ERROR! No memory allocated for the string\n";
	}
	else
	{
		strcpy_s(str, SIZE + 1, cStr.getString());
	}
}

mySTRING::~mySTRING()
{
	std::cout << "Destructing...\n";
	delete str;
}

int mySTRING::getStrSize() const
{
	return SIZE;
}

char* mySTRING::getString() const
{
	return str;
}

void mySTRING::setString(char* ui)
{
	if (str != nullptr)
	{
		delete str;
	}

	SIZE = strlen(ui) + 1;
	str = new char[SIZE];

	strcpy_s(str, SIZE, ui);
}

mySTRING& mySTRING::operator=(mySTRING& right)
{
	if (this != &right)
	{
		SIZE = right.getStrSize();
		delete[] str;

		str = new char[SIZE + 1];
		if (!str)
		{
			std::cout << "ERROR! No memory allocated for the string\n";
		}
		else
		{
			strcpy_s(str, SIZE + 1, right.getString());
		}

		return *this;
	}

	return *this;
}

char& mySTRING::operator[](int index)
{
	if (index >= 0 && index < SIZE)
	{
		return str[index];
	}

	std::cout << "ERROR!! String out of bounds!\n";
}

bool mySTRING::operator==(const mySTRING& c_string)
{
	if (strcmp(str, c_string.str) == 0)
	{
		return true;
	}

	return false;
}

std::ostream& operator<<(std::ostream& left, const mySTRING& right)
{
	left << right.str;

	return left;
}

std::istream& operator>>(std::istream& left, mySTRING& right)
{
	char in_str[100];

	left >> in_str;

	if (right.str != NULL)
	{
		delete[] right.str;
	}

	right.str = new char[strlen(in_str) + 1];
	if (!right.str)
	{
		std::cout << "Error allocating memory to the string\n";
		return left;
	}

	right.SIZE = strlen(in_str);
	strcpy_s(right.str, right.SIZE + 1, in_str);

	return left;
}