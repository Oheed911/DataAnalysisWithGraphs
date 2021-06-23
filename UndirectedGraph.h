#pragma once

#include "DistributionStorageLinkList.h"
#include "AdjacencyMatrix.h"
#include "StackClass.h"
#include "Queue.h"
//implementation of undirected graph
NLDClass<int> storeWeaklyCC;
NLDClass<int> storePathDistribution;
template<class T>
class UndirectedGraph
{
	adjacencyMatrix<T>* undirectedGraphNode;
	int TotalNumberofNodesUndirectedGraph;
public:
	void BuildGraph(T t_size)
	{
		undirectedGraphNode = new adjacencyMatrix<T>[t_size];
		TotalNumberofNodesUndirectedGraph = t_size;
		for (int i = 0; i < t_size; i++)
		{
			undirectedGraphNode[i].objAdjList.head = NULL;
			undirectedGraphNode[i].valueofnode = 0;
		}
	}
	int checkRepetition(T searchElement)
	{
		for (int i = 0; i < TotalNumberofNodesUndirectedGraph; i++)
		{
			if (searchElement == undirectedGraphNode[i].valueofnode)
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
		for (int i = 0; i < TotalNumberofNodesUndirectedGraph; i++)
		{
			if (undirectedGraphNode[i].valueofnode == 0)
			{
				return i;
			}
			else
				continue;
		}
		return -1;
	}
	void insertEdgeUndirectedGraph(T tsrc, T tdest)
	{

		insertUnDirected(tsrc, tdest);
		insertUnDirected(tdest, tsrc);
	}
	//insertion function in the undirected graph
	void insertUnDirected(T t_source, T t_destination)
	{
		int index = checkRepetition(t_source);
		if (index >= 0)
		{
			node<T>* temp = undirectedGraphNode[index].objAdjList.gethead();
			bool NodeInList = false;
			while (temp != NULL)
			{
				if (temp->data == t_destination)
				{
					NodeInList = true;
					break;
				}
				temp = temp->next;
			}
			if (!NodeInList)
			{
				undirectedGraphNode[index].valueofnode = t_source;
				undirectedGraphNode[index].objAdjList.insert(t_destination);
			}
			else
				return;
		}
		else
		{
			int Eindex = checkemptyindex();
			if (Eindex == -1)
				cout << "Graph is FULL" << endl;
			else
			{
				undirectedGraphNode[Eindex].valueofnode = t_source;
				undirectedGraphNode[Eindex].objAdjList.insert(t_destination);
			}
		}
	}
	void DisplaySourceNodesUD()
	{
		int TotalNumberOfSourceNodes = 0;
		T check;
		for (int j = 0; j < TotalNumberofNodesUndirectedGraph; j++)
		{
			cout << "j:" << j << endl;
			check = undirectedGraphNode[j].valueofnode;
			bool indegree = false;
			for (int i = 0; i < TotalNumberofNodesUndirectedGraph; i++)
			{
				node<T>* temp = undirectedGraphNode[i].objAdjList.gethead();
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
				cout << undirectedGraphNode[j].valueofnode << endl;
				TotalNumberOfSourceNodes += 1;
			}
		}
		cout << "Total Number of Source Nodes Are : " << TotalNumberOfSourceNodes << endl;
	}
	int returnIndex(T searchnode)
	{
		for (int i = 0; i < TotalNumberofNodesUndirectedGraph; i++)
		{

			if (searchnode == undirectedGraphNode[i].valueofnode)
			{
				return i;
			}
			else
				continue;
		}
		return -1;
	}
	void BFS(T startnode)
	{
		//creating array of bool
		bool* Visit_array = new bool[TotalNumberofNodesUndirectedGraph];
		for (int i = 0; i < TotalNumberofNodesUndirectedGraph; i++)
		{
			Visit_array[i] = false;
		}

		tunnel<int> queue;
		int atindex = returnIndex(startnode);
		cout << startnode << endl;
		Visit_array[atindex] = true;

		queue.enqueue(startnode);
		while (!queue.is_empty())
		{
			startnode = returnIndex(queue.gfront()->data);
			cout << queue.gfront()->data << "  ";
			queue.dequeue();
			node<int>* temp = undirectedGraphNode[startnode].objAdjList.gethead();
			if (temp == NULL)
				cout << "sink:: " << undirectedGraphNode[startnode].valueofnode << endl;
			while (temp != NULL)
			{
				int i = returnIndex(temp->data);
				if (Visit_array[i] == false)
				{
					Visit_array[i] = true;
					queue.enqueue(temp->data);
				}
				temp = temp->next;
			}
		}
	}
	void DFSearch(T startnode)
	{

		//creating array of bool
		bool* Visit_array = new bool[TotalNumberofNodesUndirectedGraph];
		for (int i = 0; i < TotalNumberofNodesUndirectedGraph; i++)
		{
			Visit_array[i] = false;
		}
		stacklist<T> stackp;
		int atindex = returnIndex(startnode);
		cout << startnode << endl;
		Visit_array[atindex] = true;

		stackp.push(startnode);
		while (!stackp.isEmpty())
		{
			startnode = returnIndex(stackp.Peek()->data);
			cout << stackp.Peek()->data << " ";
			stackp.pop();
			node<int>* temp = undirectedGraphNode[startnode].objAdjList.gethead();
			if (temp == NULL)
				cout << "sink:: " << undirectedGraphNode[startnode].valueofnode << endl;
			while (temp != NULL)
			{
				int i = returnIndex(temp->data);
				if (Visit_array[i] == false)
				{
					Visit_array[i] = true;
					stackp.push(temp->data);
				}
				temp = temp->next;
			}
		}
	}
	//showing the number of the graph nodes
	void showGraphStruct()
	{
		int nvert = TotalNumberofNodesUndirectedGraph;
		cout << "Adjacency List\thead->Vertices\n";
		for (int i = 0; i < nvert; i++)
		{
			cout << undirectedGraphNode[i].valueofnode << ":";
			undirectedGraphNode[i].objAdjList.display();
		}
	}
	//calculating the nummber of bridges
	void calculateBridgeEdges(int source_vertex, bool* visiting_array, int* discTime, int* lowcheck, int* parentNodeStorage, long long int& CountBridgeEdges,int& time_t)
	{
		int atindex = returnIndex(source_vertex);
		//marking the visiting node as visited
		visiting_array[atindex] = true;
		//now initializing the discovery and low value for that vertex in a graph
		time_t += 1;
		discTime[atindex] = time_t;
		//now intiitalizing the low index with time
		lowcheck[atindex] = time_t;
		//now checking the adjacent vertices of the graph
		node<T>* iteratepointer = undirectedGraphNode[atindex].objAdjList.gethead();
		while (iteratepointer != NULL)
		{
			int i = returnIndex(iteratepointer->data);
			if (visiting_array[i] == false)
			{
				parentNodeStorage[i] = source_vertex;
				calculateBridgeEdges(iteratepointer->data, visiting_array, discTime, lowcheck, parentNodeStorage, CountBridgeEdges,time_t);
				if (lowcheck[atindex] < lowcheck[i])
				{
					lowcheck[atindex] = lowcheck[atindex];
				}
				else if (lowcheck[atindex] > lowcheck[i])
				{
					lowcheck[atindex] = lowcheck[i];
				}
				else if (lowcheck[atindex] == lowcheck[i])
				{
					lowcheck[atindex] = lowcheck[i];
				}
				if (lowcheck[i] > discTime[atindex])
				{
					CountBridgeEdges++;
				}
			}
			else if (iteratepointer->data != parentNodeStorage[atindex])
			{
				if (lowcheck[atindex] < lowcheck[i])
				{
					lowcheck[atindex] = lowcheck[atindex];
				}
				else if (lowcheck[atindex] > lowcheck[i])
				{
					lowcheck[atindex] = lowcheck[i];
				}
				else if (lowcheck[atindex] == lowcheck[i])
				{
					lowcheck[atindex] = lowcheck[i];
				}
			}
			iteratepointer = iteratepointer->next;
		}
	}
	void BridgeEdges()
	{
		bool* visiting_array = new bool[TotalNumberofNodesUndirectedGraph];
		int* discTime = new int[TotalNumberofNodesUndirectedGraph];
		int* lowcheck = new int[TotalNumberofNodesUndirectedGraph];
		int* parent = new int[TotalNumberofNodesUndirectedGraph];
		long long int cBE = 0;
		int time_t = 0;
		for (int i = 0; i < TotalNumberofNodesUndirectedGraph; i++)
		{
			parent[i] = 0;
			visiting_array[i] = false;
			discTime[i] = 0;
			lowcheck[i] = 0;
		}
		//now calling th calc bridge funciton
		for (int i = 0; i < TotalNumberofNodesUndirectedGraph; i++)
		{
			if (visiting_array[i] == false)
			{
				calculateBridgeEdges(undirectedGraphNode[i].valueofnode, visiting_array, discTime, lowcheck, parent, cBE, time_t);
			}
		}
		//printing the number of bridge edges
		cout << "The Total number of bridge edges in this graph are: " << cBE << endl;
	}
	//now finding the shortest path of the code
	int* shortestpath(int startingnode)
	{
		int source = returnIndex(startingnode);
		bool* visited = new bool[TotalNumberofNodesUndirectedGraph];
		int* dist = new int[TotalNumberofNodesUndirectedGraph];
		for (int i = 0; i < TotalNumberofNodesUndirectedGraph; i++)
		{
			dist[i] = -1;
			visited[i] = false;
		}
		dist[source] = 0;
		visited[source] = true;
		tunnel<T> queue;
		queue.enqueue(source);
		node<int>* temp = undirectedGraphNode[source].objAdjList.gethead();
		int curr = 0;
		while (!queue.is_empty())
		{
			curr = queue.gfront()->data;
			queue.dequeue();
			temp = undirectedGraphNode[curr].objAdjList.gethead();
			while (temp != NULL)
			{
				int i = returnIndex(temp->data);
				if (visited[i] == false)
				{
					visited[i] = true;
					queue.enqueue(i);
					dist[i] = dist[curr] + 1;
				}
				temp = temp->next;
			}
		}
		return dist;
	}
	//funciton to find the shortest path of every node
	void findingshortestpath()
	{
		for (int i = 0; i < TotalNumberofNodesUndirectedGraph; i++)
		{
			int* retpath = new int[TotalNumberofNodesUndirectedGraph];
			retpath = shortestpath(undirectedGraphNode[i].valueofnode);
			for (int i = 0; i < TotalNumberofNodesUndirectedGraph; i++)
			{
				if (retpath[i] != -1)
				{
					storePathDistribution.insertNLD(retpath[i]);
				}
			}
		}
	}
	//now finding the diameter of the graph
	int DiameterOfTheGraph()
	{
		int* visited = new int[TotalNumberofNodesUndirectedGraph];
		int count = 0;
		int maximum = 0;
		for (int k = 0; k < TotalNumberofNodesUndirectedGraph; k++)
		{
			visited = shortestpath(undirectedGraphNode[k].valueofnode);
			for (int i = 0; i < TotalNumberofNodesUndirectedGraph - 1; i++)
			{
				count = visited[i];
				for (int j = i + 1; j < TotalNumberofNodesUndirectedGraph; j++)
				{
					if (visited[i] < visited[j])
						count = visited[i];
				}
			}
			if (count > maximum)
			{
				maximum = count;
			}
		}
		return maximum;
	}
	//enhanced code
	AdjencencyList<T> EnhanceBfsForoutdegreeCalling(T startnode)
	{
		//now doing the bfs on the graph
		bool* Visit_array = new bool[TotalNumberofNodesUndirectedGraph];
		for (int i = 0; i < TotalNumberofNodesUndirectedGraph; i++)
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
			node<int>* temp = undirectedGraphNode[startnode].objAdjList.gethead();
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
	//now finding the distance 
	int weaklyConnectedComponents()
	{
		bool* markunique = new bool[TotalNumberofNodesUndirectedGraph];
		adjacencyMatrix<T>* calcweaklyCC = new adjacencyMatrix<T>[TotalNumberofNodesUndirectedGraph];
		for (int i = 0; i < TotalNumberofNodesUndirectedGraph; i++)
		{
			markunique[i] = true;
			calcweaklyCC[i].valueofnode = 0;
			calcweaklyCC[i].objAdjList.head = NULL;
		}
		for (int i = 0; i < TotalNumberofNodesUndirectedGraph; i++)
		{
			calcweaklyCC[i].valueofnode = undirectedGraphNode[i].valueofnode;
			//now copying the whole link list
			AdjencencyList<T> returnlist = EnhanceBfsForoutdegreeCalling(undirectedGraphNode[i].valueofnode);
			node<T>* copying = returnlist.gethead();
			while (copying != NULL)
			{
				calcweaklyCC[i].objAdjList.insert(copying->data);
				copying = copying->next;
			}
		}

		//now finding the unique elements
		for (int i = 0; i < TotalNumberofNodesUndirectedGraph - 1; i++)
		{
			node<T>* chec = calcweaklyCC[i].objAdjList.gethead();
			for (int j = i + 1; j < TotalNumberofNodesUndirectedGraph; j++)
			{
				node<T>* nextcheck = calcweaklyCC[j].objAdjList.gethead();
				while (chec != NULL)
				{
					bool notunique = false;
					T data = chec->data;
					nextcheck = calcweaklyCC[j].objAdjList.gethead();
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
		//finding the maximum size of the weakly connected component
		int max = 0;
		int findsize = 0;
		for (int i = 0; i < TotalNumberofNodesUndirectedGraph; i++)
		{
			findsize = 0;
			if (markunique[i] == true)
			{
				int count = 0;
				node<T>* temp = calcweaklyCC[i].objAdjList.gethead();
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
				storeWeaklyCC.insertNLD(findsize);
			}
		}
		//now making the array
		return max;
	}

};
