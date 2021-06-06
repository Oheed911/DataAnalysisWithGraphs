
#include <fstream>
#include <iostream>
#include <string>
using namespace std;


//implementation of the link list
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

template <class T>
struct adjacencyMatrix
{
	AdjencencyList<T> objAdjList;
	T valueofnode;
};

//now the class of the graph

template<class T>
class DirectedGraph
{
private:
	adjacencyMatrix<T>* graphnode;
	int TotalNumberOfNodesinGraph;
public:
	void BuildGraph(T t_size)
	{
		graphnode = new adjacencyMatrix<T>[t_size];
		TotalNumberOfNodesinGraph = t_size;
		for (int i = 0; i < t_size; i++)
		{
			graphnode[i].objAdjList.head = NULL;
			graphnode[i].valueofnode = 0;
		}
	}
	int checkRepetition(T searchElement)
	{
		for (int i = 0; i < TotalNumberOfNodesinGraph; i++)
		{
			if (searchElement == graphnode[i].valueofnode)
			{
				return i;
			}
			else
				continue;
		}
		return -1;
	}
	int checkemptyindex()
	{
		for (int i = 0; i < TotalNumberOfNodesinGraph; i++)
		{
			if  (graphnode[i].valueofnode==0)
			{
				return i;
			}
			else
				continue;
		}
		return -1;
	}
	void insertEdge(T t_source, T t_destination)
	{
		int index = checkRepetition(t_source);
		if (index>=0)
		{
			graphnode[index].valueofnode = t_source;
			graphnode[index].objAdjList.insert(t_destination);
		}
		else
		{
			int Eindex = checkemptyindex();

			if (Eindex == -1)
				cout << "Graph is FULL" << endl;
			else
			{
				graphnode[Eindex].valueofnode = t_source;
				graphnode[Eindex].objAdjList.insert(t_destination);
			}
		}
	}
	void showGraphStruct()
	{
		int nvert = TotalNumberOfNodesinGraph;
		cout << "Adjacency List\thead->Vertices\n";
		for (int i = 0; i < nvert; i++)
		{
			cout << graphnode[i].valueofnode << ":";
			graphnode[i].objAdjList.display();
		}
	}
	void DisplayTotalNode()
	{
		cout << "TOTAL Number of Nodes in Graph is : ";
		cout << TotalNumberOfNodesinGraph << endl;
	}
	int calculateNumberofEdges()
	{
		int countNumberOfEdges = 0;
		for (int i = 0; i < TotalNumberOfNodesinGraph; i++)
		{
			countNumberOfEdges += 1;
			node<T>* temp=graphnode[i].objAdjList.gethead();
			while (temp->next != NULL)
			{
				countNumberOfEdges += 1;
				temp = temp->next;
			}
		}
		return countNumberOfEdges;
	}
	void DisplaySourceNodes()
	{
		int TotalNumberOfSourceNodes = 0;
		T check;
		for (int j = 0; j < TotalNumberOfNodesinGraph; j++)
		{
			check = graphnode[j].valueofnode;
			bool indegree = false;
			for (int i = 0; i < TotalNumberOfNodesinGraph; i++)
			{
				node<T>* temp = graphnode[i].objAdjList.gethead();
				while (temp!= NULL)
				{
					if (check == temp->data)
					{
						indegree = true;
						break;
					}
					temp = temp->next;
				}
				if (indegree)
					break;
				else 
					continue;
			}
			if (!indegree)
			{
				cout << graphnode[j].valueofnode << endl;
				TotalNumberOfSourceNodes += 1;
			}	
		}
		cout << "Total Number of Source Nodes Are : " << TotalNumberOfSourceNodes << endl;
	}
	//function to show the number of sink nodes
	void DisplayNumberOfSinkNodes()
	{
		int TotalNumberOfSinkNodes=0;
		
		for (int i = 0; i < TotalNumberOfNodesinGraph; i++)
		{
			bool outdegree = false;
			node<T>* temp = graphnode[i].objAdjList.gethead();
			if (temp != NULL)
			{
				outdegree = true;
			}
			else
			{
				outdegree = false;
			}
			if (!outdegree)
			{
				TotalNumberOfSinkNodes += 1;
			}
		}
		cout << "Total Number of Sink Nodes in Graph is : " << TotalNumberOfSinkNodes << endl;
	}

	void show()
	{
		for (int i = 0; i < TotalNumberOfNodesinGraph; i++)
			cout << graphnode[i].valueofnode << endl;
	}
};


DirectedGraph<int> Gobj;

//file reading code

void DataFetch(string filepath)
{
	fstream objFile;
	int countLine = 0;
	string NumberOfEdges = "";
	string NumberOfNodes = "";
	bool flag1 = true;
	bool flag2 = true;
	objFile.open(filepath);
	while (!objFile.eof())
	{
		countLine += 1;
		string ReadDataFromFile = "";
		//to store number of nodes and no of edges on line file 3
		string iterate_source = "";
		string iterate_dest = "";
		//reading one line
		getline(objFile, ReadDataFromFile);
		//For the nodes and edges
		//if string is not empty
		if (ReadDataFromFile != "")
		{
			if (countLine == 3)
			{
				for (int i = 0; i < ReadDataFromFile.length(); i++)
				{
					if (ReadDataFromFile[i] == ':' && flag1 == true)
					{
						i += 2;
						while (ReadDataFromFile[i] != ' ')
						{
							NumberOfNodes += ReadDataFromFile[i];
							i++;
						}
						flag1 = false;
					}
					if (ReadDataFromFile[i] == ':' && flag2 == true)
					{
						i += 2;
						while (i != ReadDataFromFile.length())
						{
							NumberOfEdges += ReadDataFromFile[i];
							i++;
						}
						flag2 = false;
					}
				}
				Gobj.BuildGraph(stoi(NumberOfNodes));
			}
			if (countLine > 4)
			{
				bool checkspace = false;
				for (int i = 0; i < ReadDataFromFile.length(); i++)
				{
					while (ReadDataFromFile[i] != '	')
					{

						iterate_source += ReadDataFromFile[i];
						i++;
					}
					if (ReadDataFromFile[i] == '	')
					{
						i++;
						while (i != ReadDataFromFile.length())
						{
							iterate_dest += ReadDataFromFile[i];
							i++;
						}
					}
				}
				Gobj.insertEdge(stoi(iterate_source), stoi(iterate_dest));
			}
			else
				continue;
		}
	}
	//closing the file
	objFile.close();
}
int main()
{
	string path = "C:\\Users\\Butt\\Desktop\\test.txt";
	DataFetch(path);
	Gobj.DisplayTotalNode();
	cout << "Number of Edges are : ";
	cout << Gobj.calculateNumberofEdges() << endl;
	Gobj.DisplaySourceNodes();
	Gobj.DisplayNumberOfSinkNodes();
	//Gobj.showGraphStruct();
}
