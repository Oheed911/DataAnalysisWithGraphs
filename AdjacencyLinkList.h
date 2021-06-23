#pragma once
template <class T>
class node
{
public:
	T data;
	node<T>* next;
	node()
	{
		next = NULL;
		data = 0;
	}
};
template <class T>
class AdjencencyList
{

public:
	node<T>* head;
	AdjencencyList()
	{
		head = NULL;
	}
	void insert(T temp)
	{
		if (head == NULL)
		{
			node<T>* new_Node = new node<T>;
			new_Node->data = temp;
			new_Node->next = NULL;
			head = new_Node;
		}
		else
		{
			node<T>* iterate = head;
			while (iterate->next != NULL)
				iterate = iterate->next;

			node<T>* new_Node = new node<T>;
			new_Node->data = temp;
			new_Node->next = NULL;
			iterate->next = new_Node;
		}
	}
	void display()
	{
		node<T>* iterate = head;
		while (iterate != NULL)
		{
			cout << iterate->data << "    ";
			iterate = iterate->next;
		}
		cout << endl;
	}
	node<T>* gethead()
	{
		return head;
	}
};