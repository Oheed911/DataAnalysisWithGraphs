#pragma once
#include <iostream>
using namespace std;
template <class T>
class Node_Link_Node
{
public:
	long long int count;
	double ProbabilityofEachNode;
	int distvalue;
	Node_Link_Node<T>* nextNLN;
	Node_Link_Node()
	{
		nextNLN = NULL;
		count = 0;
		distvalue = 0;
		ProbabilityofEachNode = 0;
	}
};


template <class T>
class NLDClass
{
public:
	Node_Link_Node<T>* heading;
	NLDClass()
	{
		heading = NULL;
	}
	//function to insert data in the link list of the distribution
	void insertNLD(T degree)
	{
		if (heading == NULL)
		{
			Node_Link_Node<T>* newNode = new Node_Link_Node<T>;
			newNode->distvalue = degree;
			newNode->count++;
			newNode->nextNLN = NULL;
			heading = newNode;
		}
		else
		{

			Node_Link_Node<T>* iterate = heading;
			Node_Link_Node<T>* temp = NULL;
			while (iterate != NULL && iterate->distvalue != degree)
			{
				temp = iterate;
				iterate = iterate->nextNLN;
			}
			if (iterate != NULL)
			{
				iterate->count++;
			}
			else
			{
				Node_Link_Node<T>* newNode = new Node_Link_Node<T>;
				newNode->distvalue = degree;
				newNode->count++;
				newNode->nextNLN = NULL;
				temp->nextNLN = newNode;
			}
		}
	}
	void displayProbdistribution()
	{
		Node_Link_Node<T>* iterate = heading;
		cout << "\033[1;31m";
		cout << "Degree Nodes" << "		" << "Number Of Nodes" << "		" << "DEGREE DISTRIBUTION" << endl;
		cout << "\033[0m";
		while (iterate->nextNLN != NULL)
		{
			cout << iterate->distvalue << "			" << iterate->count << "			" << iterate->ProbabilityofEachNode << endl;
			iterate = iterate->nextNLN;
		}
		cout << iterate->distvalue << "			" << iterate->count << "			" << iterate->ProbabilityofEachNode << endl;
	}
	void CalculateProbability(T nodes)
	{
		Node_Link_Node<T>* newNode = heading;
		while (newNode != NULL)
		{
			newNode->ProbabilityofEachNode = double(newNode->count) / nodes;
			newNode = newNode->nextNLN;
		}
	}
	void displayDistributionGraph()
	{
		Node_Link_Node<T>* iterate = heading;
		cout << "Size " << "		" << "Number Of Nodes" << endl;
		while (iterate->nextNLN != NULL)
		{
			cout << iterate->distvalue << "			" << iterate->count << endl;
			iterate = iterate->nextNLN;
		}
		cout << iterate->distvalue << "			" << iterate->count << endl;

	}

	void Search(T node)
	{
		Node_Link_Node<T>* newNode = heading;
		while (newNode != NULL && newNode->distvalue != node)
		{
			newNode = newNode->nextNLN;
		}
		if (newNode != NULL)
		{
			cout << "The Indegree Distribution of Nodes having inegree/outdegree, " << node << " is  :" << newNode->ProbabilityofEachNode << endl;
		}
		else
		{
			cout << "Cant Find the distribution value" << endl;
		}
	}
	void SearchD(T node)
	{
		Node_Link_Node<T>* newNode = heading;
		while (newNode != NULL && newNode->distvalue != node)
		{
			newNode = newNode->nextNLN;
		}
		if (newNode != NULL)
		{
			cout << "The number of nodes for distribution value ,  " << node << " is  :" << newNode->count<< endl;
		}
		else
		{
			cout << "Cant Find the distribution value" << endl;
		}
	}
};
