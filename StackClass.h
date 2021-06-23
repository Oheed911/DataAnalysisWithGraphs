#pragma once
template<class a>
class stacklist
{
public:
	node<a>* top;
	stacklist()
	{
		top = NULL;
	}
	//now the funcitons
	void push(a pushdata)
	{
		node<a>* new_Node = new node<a>;

		new_Node->next = top;
		new_Node->data = pushdata;
		top = new_Node;
	}

	node<int>* Peek()
	{
		if (top != NULL)
		{
			return top;
		}
		else
			cout << "STACK IS EMPTY" << endl;
	}

	a pop()
	{
		a ret;
		if (top == NULL)
		{
			cout << "Stack is Empty" << endl;
		}
		else
		{
			node<a>* newnode = top;
			ret = top->data;
			//newnode = top;

			top = top->next;

			newnode->next = NULL;

			delete newnode;
		}
		return ret;
	}
	int sizeQueu()
	{
		node<a>* temp = top;
		int s = 0;
		while (temp != NULL)
		{
			s++;
			temp = temp->next;
		}
		return s;
	}
	bool isEmpty()
	{
		if (top == NULL)
			return 1;
		else
			return 0;
	}
	a topele()
	{
		node<a>* temp = top;
		return temp->data;
	}
};