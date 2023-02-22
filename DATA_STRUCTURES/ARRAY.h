#pragma once

template<typename T>
class ARRAY
{
	T* pArray;
	int SIZE;

public:
	ARRAY();
	ARRAY(int in_size);
	ARRAY(const ARRAY<T>& ob);
	~ARRAY();

	int getSize() const;
	void setSize(int s);

	int& operator[](int index);
	ARRAY<T>& operator=(ARRAY<T>& arr);
	ARRAY<T>& operator+=(int right);

	template<typename U> friend std::ostream& operator<<(std::ostream& left, const ARRAY<U>& right);

	static int MAX_LENGTH;
};

template<typename T>
int ARRAY<T>::MAX_LENGTH = 1000;

template<typename T>
ARRAY<T>::ARRAY()
{
	SIZE = 0;
	pArray = nullptr;
}

template<typename T>
ARRAY<T>::ARRAY(int in_size)
{
	if (in_size > MAX_LENGTH)
	{
		std::cout << "WARNING: The array size you've given is more than 1000. TRY AGAIN.\n";

		SIZE = 0;
		pArray = NULL;
		return;
	}

	SIZE = in_size;
	pArray = new T[SIZE];
	if (!pArray)
	{
		std::cout << "ERROR! NO MEMORY FOR THE ARRAY\n";
	}

	std::cout << "Constructing...\n";
}

template<typename T>
ARRAY<T>::ARRAY(const ARRAY<T>& ob)
{
	SIZE = ob.getSize();
	pArray = new T[SIZE];

	if (!pArray)
	{
		std::cout << "ERROR! NO MEMORY FOR THE ARRAY\n";
	}
	else
	{
		for (int i = 0; i < SIZE; ++i)
		{
			pArray[i] = ob.pArray[i];
		}
	}

	std::cout << "Copy Constructing...\n";
}

template<typename T>
ARRAY<T>::~ARRAY()
{
	std::cout << "Destructing...\n";
	delete[] pArray;
}

template<typename T>
int ARRAY<T>::getSize() const
{
	return SIZE;
}

template<typename T>
void ARRAY<T>::setSize(int s)
{
	SIZE = s;
}

template<typename T>
int& ARRAY<T>::operator[](int index)
{
	if (index >= 0 && index < SIZE)
	{
		return pArray[index];
	}

	std::cout << "ERROR! Array out of bounds!\n";
	return pArray[0];
}

template<typename T>
ARRAY<T>& ARRAY<T>::operator=(ARRAY<T>& arr)
{
	if (this == &arr)
	{
		return *this;
	}
	SIZE = arr.getSize();
	delete[] pArray;
	pArray = new T[SIZE];

	if (!pArray)
	{
		std::cout << "ERROR! NO MEMORY FOR THE ARRAY\n";
	}
	else
	{
		for (int i = 0; i < SIZE; ++i)
		{
			pArray[i] = arr[i];
		}
	}

	return *this;
}

template<typename T>
ARRAY<T>& ARRAY<T>::operator+=(int right)
{
	int newS = SIZE + right;
	int* newpArray;
	newpArray = new T[newS];

	if (right > 0)
	{
		if (newpArray)
		{
			for (int i = 0; i < SIZE; i++)
			{
				newpArray[i] = pArray[i];
			}

			for (int i = SIZE; i < newS; i++)
			{
				newpArray[i] = 0;
			}

			delete[] pArray;

			SIZE = newS;
			pArray = newpArray;
		}
		else
		{
			std::cout << "No memory allocation for the array!\n";
		}
	}
	else
	{
		std::cout << "The extra size is 0 or less!\n";
	}

	return *this;
}

template<typename T>
std::ostream& operator<<(std::ostream& left, const ARRAY<T>& right)
{
	left << "[";
	for (int i = 0; i < right.SIZE; ++i)
	{
		left << " " << right.pArray[i] << " ";
	}
	left << "] \n";

	return left;
}