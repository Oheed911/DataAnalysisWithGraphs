#pragma once
template<class T>
struct Queue
{
	T data;
	Queue<T>* next;

};


template<class T>
struct tunnel
{
public:
	Queue<T>* front;
	Queue<T>* rear;
	int size = 0;
	tunnel()
	{
		front = NULL;
		rear = NULL;
	}
	//function to get front
	void enqueue(T a1)
	{
		Queue<T>* new_Node = new Queue<T>;
		new_Node->data = a1;
		if (front == NULL) {
			front = rear = new_Node;
			rear->next = NULL;
			size++;
		}
		else {
			//now if the the queue is not empty
			rear->next = new_Node;
			rear = new_Node;
			rear->next = NULL;
			size++;
		}
	}
	Queue<T>* gfront()
	{
		return front;
	}
	bool is_empty()
	{
		if (size == 0)
		{
			return true;
		}
		else
			return false;
	}
	void dequeue()
	{
		if (front == NULL)
			return;
		Queue<T>* tfront = new Queue<T>;
		tfront = front;
		front = front->next;
		if (front == NULL)
		{
			rear = NULL;
		}
		size--;
		delete tfront;
	}
	int gsize()
	{
		return size;
	}
	void Display()
	{
		Queue<T>* tfront = front;
		int temp = gsize();
		while (temp != 0)
		{
			cout << tfront->data << " ";
			tfront = tfront->next;
			temp--;
		}
	}
};