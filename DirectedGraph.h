#pragma once

//now the class of the graph
NLDClass<int> storeoutdegree;
NLDClass<int> storeIndegree;

//to store the distributionof the strongly connected components 
NLDClass<int> storeSSC;
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
			if (graphnode[i].valueofnode == 0)
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
		if (index >= 0)
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
	//void nserting those edges that have an outdegree of zero
	void setGraph()
	{
		for (int i = 0; i < TotalNumberOfNodesinGraph; i++)
		{
			node<T>* startnode = graphnode[i].objAdjList.gethead();
			while (startnode != NULL)
			{
				T check = startnode->data;
				bool found = false;
				for (int j = 0; j < TotalNumberOfNodesinGraph; j++)
				{
					if (check == graphnode[j].valueofnode)
					{
						found = true;
						break;
					}
				}
				if (found == false)
				{
					int Eindex = checkemptyindex();
					if (Eindex != -1)
					{
						graphnode[Eindex].valueofnode = check;
					}
				}
				startnode = startnode->next;
			}
		}
	}
	void showGraphStruct()
	{
		cout << "Adjacency List\thead->Vertices\n";
		for (int i = 0; i < TotalNumberOfNodesinGraph; i++)
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
			node<T>* temp = graphnode[i].objAdjList.gethead();
			while (temp != NULL)
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
				while (temp != NULL)
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
		int TotalNumberOfSinkNodes = 0;

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
	int indegree(T snode)
	{
		T check = snode;
		int indegree = 0;
		for (int i = 0; i < TotalNumberOfNodesinGraph; i++)
		{
			node<T>* temp = graphnode[i].objAdjList.gethead();
			while (temp != NULL)
			{
				if (check == temp->data)
				{
					indegree += 1;
					break;
				}
				temp = temp->next;
			}
		}
		return indegree;
	}
	int oudegree(T snode)
	{
		int outdegree = 0;
		int i = returnIndex(snode);
		node<T>* temp = graphnode[i].objAdjList.gethead();
		while (temp != NULL)
		{
			outdegree++;
			temp = temp->next;
		}
		return outdegree;
	}
	void DisplayIsolatedNodes()
	{
		int TotalNumberofisolatednodes = 0;

		for (int i = 0; i < TotalNumberOfNodesinGraph; i++)
		{
			if (indegree(graphnode[i].valueofnode) == 0 && oudegree(graphnode[i].valueofnode) == 0)
			{
				TotalNumberofisolatednodes++;
			}
		}
		cout << "Total Number of Isolated nodes Are: " << TotalNumberofisolatednodes << endl;
	}
	int returnIndex(T searchnode)
	{
		for (int i = 0; i < TotalNumberOfNodesinGraph; i++)
		{

			if (searchnode == graphnode[i].valueofnode)
			{
				return i;
			}
			else
				continue;
		}
		return -1;
	}
	void OutDegreeDistribution()
	{
		int outdegree = 0;
		for (int i = 0; i < TotalNumberOfNodesinGraph; i++)
		{
			outdegree = 0;
			node<T>* temp = graphnode[i].objAdjList.gethead();
			while (temp != NULL)
			{
				outdegree++;
				temp = temp->next;
			}
			storeoutdegree.insertNLD(outdegree);
		}
	}
	void IndegreeDistribution()
	{
		int TotalNumberOfSourceNodes = 0;
		T check;
		for (int j = 0; j < TotalNumberOfNodesinGraph; j++)
		{
			check = graphnode[j].valueofnode;
			int indegree = 0;
			for (int i = 0; i < TotalNumberOfNodesinGraph; i++)
			{
				node<T>* temp = graphnode[i].objAdjList.gethead();
				while (temp != NULL)
				{
					if (check == temp->data)
					{
						indegree += 1;
						break;
					}
					temp = temp->next;
				}
			}
			storeIndegree.insertNLD(indegree);
		}
	}
	void show()
	{
		for (int i = 0; i < TotalNumberOfNodesinGraph; i++)
			cout << graphnode[i].valueofnode << endl;
	}
	T getTotalNodes()
	{
		return TotalNumberOfNodesinGraph;
	}

	bool BFSForInalgorithmSCC(T startnode, T value_temp)
	{
		//creating array of bool
		bool* Visit_array = new bool[TotalNumberOfNodesinGraph];
		for (int i = 0; i < TotalNumberOfNodesinGraph; i++)
		{
			Visit_array[i] = false;
		}

		tunnel<int> queue;
		int atindex = returnIndex(startnode);
		Visit_array[atindex] = true;

		queue.enqueue(startnode);
		while (!queue.is_empty())
		{
			startnode = returnIndex(queue.gfront()->data);
			queue.dequeue();
			node<int>* temp = graphnode[startnode].objAdjList.gethead();
			while (temp != NULL)
			{
				int i = returnIndex(temp->data);
				if (value_temp == temp->data)
				{
					return true;
				}
				if (Visit_array[i] == false)
				{
					Visit_array[i] = true;
					queue.enqueue(temp->data);
				}
				temp = temp->next;
			}
		}
		return false;

	}

	//finding teh strongly connected componenets

	adjacencyMatrix<T>* InalgorithmForScc()
	{
		adjacencyMatrix<T>* storingArray;
		storingArray = new adjacencyMatrix<T>[TotalNumberOfNodesinGraph];
		for (int i = 0; i < TotalNumberOfNodesinGraph; i++)
		{
			storingArray[i].valueofnode = 0;
			storingArray[i].objAdjList.head = NULL;
		}
		for (int i = 0; i < TotalNumberOfNodesinGraph; i++)
		{
			T valueofS = graphnode[i].valueofnode;
			storingArray[i].objAdjList.insert(graphnode[i].valueofnode);
			storingArray[i].valueofnode = valueofS;
			for (int j = 0; j < TotalNumberOfNodesinGraph; j++)
			{

				if (BFSForInalgorithmSCC(graphnode[j].valueofnode, valueofS) && graphnode[j].valueofnode != valueofS)
				{
					storingArray[i].objAdjList.insert(graphnode[j].valueofnode);
				}
			}
		}
		return storingArray;
	}
	//algorithm for the finding of the outnodes in the graph
	AdjencencyList<T> EnhanceBfsForoutdegreeCalling(T startnode)
	{
		//now doing the bfs on the graph
		bool* Visit_array = new bool[TotalNumberOfNodesinGraph];
		for (int i = 0; i < TotalNumberOfNodesinGraph; i++)
		{
			Visit_array[i] = false;
		}
		tunnel<int> queue;
		int atindex = returnIndex(startnode);
		Visit_array[atindex] = true;
		AdjencencyList<T> StoringSingleOutArray;
		queue.enqueue(startnode);
		StoringSingleOutArray.insert(startnode);
		while (!queue.is_empty())
		{
			startnode = returnIndex(queue.gfront()->data);
			queue.dequeue();
			node<int>* temp = graphnode[startnode].objAdjList.gethead();
			while (temp != NULL)
			{
				int i = returnIndex(temp->data);
				if (Visit_array[i] == false)
				{
					Visit_array[i] = true;
					queue.enqueue(temp->data);
					StoringSingleOutArray.insert(temp->data);
				}
				temp = temp->next;
			}
		}
		return StoringSingleOutArray;
	}
	adjacencyMatrix<T>* outalgorithmForScc()
	{
		adjacencyMatrix<T>* storingoutarray;
		storingoutarray = new adjacencyMatrix<T>[TotalNumberOfNodesinGraph];

		for (int i = 0; i < TotalNumberOfNodesinGraph; i++)
		{
			storingoutarray[i].valueofnode = 0;
			storingoutarray[i].objAdjList.head = NULL;
		}
		//now traversing the bfs on the algoithm
		for (int i = 0; i < TotalNumberOfNodesinGraph; i++)
		{
			//now printing the nodes of the graph
			storingoutarray[i].valueofnode = graphnode[i].valueofnode;
			//now copying the whole link list
			AdjencencyList<T> returnlist = EnhanceBfsForoutdegreeCalling(graphnode[i].valueofnode);
			node<T>* copying = returnlist.gethead();
			while (copying != NULL)
			{
				storingoutarray[i].objAdjList.insert(copying->data);
				copying = copying->next;
			}
		}
		return storingoutarray;
	}
	//now finding the sttongly connected components
	int stronglyconnectedAlgorithm()
	{

		adjacencyMatrix<int>* storingoutArray = outalgorithmForScc();
		adjacencyMatrix<int>* storingArray = InalgorithmForScc();
		adjacencyMatrix<T>* SCCWithoutUnique = new adjacencyMatrix<T>[TotalNumberOfNodesinGraph];
		bool* markunique = new bool[TotalNumberOfNodesinGraph];
		for (int i = 0; i < TotalNumberOfNodesinGraph; i++)
		{
			markunique[i] = true;
			SCCWithoutUnique[i].valueofnode = 0;
			SCCWithoutUnique[i].objAdjList.head = NULL;
		}
		for (int i = 0; i < TotalNumberOfNodesinGraph; i++)
		{

			T valNode = storingArray[i].valueofnode;
			SCCWithoutUnique[i].valueofnode = valNode;
			for (int j = 0; j < TotalNumberOfNodesinGraph; j++)
			{
				if (valNode == storingoutArray[j].valueofnode)
				{
					//now finding the intersection in the files
					node<T>* invallinklist = storingArray[i].objAdjList.gethead();

					while (invallinklist != NULL)
					{
						T dataIn = invallinklist->data;
						node<T>* outvallinklist = storingoutArray[j].objAdjList.gethead();
						while (outvallinklist != NULL)
						{
							if (dataIn == outvallinklist->data)
							{
								SCCWithoutUnique[i].objAdjList.insert(dataIn);
								break;
							}
							outvallinklist = outvallinklist->next;
						}
						invallinklist = invallinklist->next;
					}
					break;
				}
			}
		}
		//now displayin the link lis
		//now finding th unique elements in the link lists
		//making the array of the bool

		for (int i = 0; i < TotalNumberOfNodesinGraph - 1; i++)
		{
			node<T>* chec = SCCWithoutUnique[i].objAdjList.gethead();
			for (int j = i + 1; j < TotalNumberOfNodesinGraph; j++)
			{
				node<T>* nextcheck = SCCWithoutUnique[j].objAdjList.gethead();
				while (chec != NULL)
				{
					bool notunique = false;
					T data = chec->data;
					nextcheck = SCCWithoutUnique[j].objAdjList.gethead();
					while (nextcheck != NULL)
					{
						if (chec->data == nextcheck->data)
						{
							markunique[j] = false;
							notunique = true;
							break;
						}
						nextcheck = nextcheck->next;
					}
					if (!notunique)
					{
						break;
					}
					chec = chec->next;
				}
			}
		}
		int max = 0;
		int findsize = 0;
		for (int i = 0; i < TotalNumberOfNodesinGraph; i++)
		{

			findsize = 0;
			if (markunique[i] == true)
			{
				int count = 0;
				node<T>* temp = SCCWithoutUnique[i].objAdjList.gethead();
				while (temp != NULL)
				{
					findsize++;
					count++;
					temp = temp->next;
				}
				if (count > max)
				{
					max = count;
				}
				storeSSC.insertNLD(findsize);
			}
		}

		return max;
	}

};