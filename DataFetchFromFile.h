#pragma once
#include <fstream>
#include <string>
#include "UndirectedGraph.h"
#include "DirectedGraph.h"
UndirectedGraph<int> UndirectedGraphObject;
DirectedGraph<int> Gobj;
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
				UndirectedGraphObject.BuildGraph(stoi(NumberOfNodes));
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
				UndirectedGraphObject.insertEdgeUndirectedGraph(stoi(iterate_source), stoi(iterate_dest));
			}
			else
				continue;
		}
	}
	Gobj.setGraph();
	//closing the file
	objFile.close();
}