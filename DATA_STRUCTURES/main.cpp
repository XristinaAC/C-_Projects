#include <iostream>
#include <iostream>
#include "ARRAY.h"
#include "Single_Linked_List.h"

int main()
{
	int n = 50;
	ARRAY<int> arr(n);
	ARRAY<int> arr2;

	for (int i = 0; i < arr.getSize(); ++i)
	{
		arr[i] = i * i;
	}

	std::cout << arr;

	arr2 = arr;
	arr2 += 5;

	std::cout << "\n" << arr2.getSize() << "\n";
	std::cout << arr2;
	arr2[5] = 20;
	std::cout << arr2 << "\n";

	SLinkedList<int> list;

	list.Add_Node(1);
	list.Add_Node(2);
	list.Add_Node(3);
	list.Add_Node(4);

	list.Print_List();

	list.Delete_Node(0);

	list.Print_List();

	return 0;
}