#pragma once

template<typename T>
class SLinkedList;

/************************_Node Class_****************************/

template<typename T>
class Node 
{
	T data;
	Node<T>* next;

public:
	friend class SLinkedList<T>;

	Node();
	Node(T in_data);

	T Get_Data();
	Node<T>* Get_Next();

	void Set_Data(T in_data);
	void Set_Next(Node<T>* in_node);
};

template<typename T>
Node<T>::Node()
{
	data = 0;
	next = nullptr;
}
template<typename T>
Node<T>::Node(T in_data)
{
	data = in_data;
	next = nullptr;
}

template<typename T>
T Node<T>::Get_Data()
{
	return data;
}

template<typename T>
Node<T>* Node<T>::Get_Next()
{
	return next;
}

template<typename T>
void Node<T>::Set_Data(T in_data)
{
	data = in_data;
}

template<typename T>
void Node<T>::Set_Next(Node<T>* in_node)
{
	next = in_node;
}

/*********************************************************************************************/

/**********************_List Class_******************************/

template<typename T>
class SLinkedList
{
	Node<T>* head;

public:
	SLinkedList();
	SLinkedList(Node<T>* in_node);
	~SLinkedList();

	void Add_Node(T in_data);
	void Delete_Node(int given_pos);

	void Print_List();
};

template<typename T>
SLinkedList<T>::SLinkedList()
{
	head = NULL;
}

template<typename T>
SLinkedList<T>::SLinkedList(Node<T>* in_node)
{
	head = in_node;
}

template<typename T>
SLinkedList<T>::~SLinkedList()
{
	while (head != NULL)
	{
		Node<T>* temp;
		temp = head;
		head = head->next;

		delete temp;
	}
}

//Add new node at the end of the list
template<typename T>
void SLinkedList<T>::Add_Node(T in_data)
{
	Node<T>* new_node = new Node<T>(in_data);

	if (head == NULL)
	{
		head = new_node;
		
		return;
	}

	Node<T>* temp_node = head;
	while (temp_node->Get_Next() != NULL)
	{
		temp_node = temp_node->next;
	}

	temp_node->next = new_node;
}

//Delete node at given position
template<typename T>
void SLinkedList<T>::Delete_Node(int given_pos)
{
	if (head == NULL)
	{
		std::cout << "The List is empty, no element to delete.\n";
		return;
	}

	int list_length = 0;
	int i = 1;
	Node<T>* temp_h = head;

	while (temp_h != NULL)
	{
		list_length++;
		temp_h = temp_h->next;
	}

	if (given_pos > list_length-1)
	{
		std::cout << "The given position for data deletion doesn't exit. Position out of bounds.\n";
		delete temp_h;
		return;
	}
	
	temp_h = head;
	if (given_pos == 0)
	{
		head = head->next;
		return;
	}

	while ( i != given_pos)
	{
		temp_h = temp_h->next;
		i++;
	}

	Node<T>* temp2 = temp_h->next;
	if (temp2->next != NULL)
	{
		temp_h->next = temp2->next;
		delete temp2;
	}
	else
	{
		temp_h->next = NULL;
		delete temp2;
	}
}

template<typename T>
void SLinkedList<T>::Print_List()
{
	if (head == nullptr)
	{
		std::cout << "The List is empty.\n";
		return;
	}

	Node<T>* temp_head = head;

	while (temp_head != NULL)
	{
		std::cout << "List Element: " << temp_head->data << "\n";
		temp_head = temp_head->next;
	}
	std::cout<< std::endl;
}