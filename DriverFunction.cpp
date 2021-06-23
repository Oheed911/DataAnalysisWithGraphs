
#include "DataFetchFromFile.h"
int main()
{
	
	cout << "Inserting Data Into Graph...";
	string path = "C:\\Users\\Butt\\Desktop\\1.txt";
	DataFetch(path);
	cout << endl;
	cout << "Inserted Successfuly" << endl;
	cout << endl;
	string input;
	do
	{
		input = "";
		cout << "			" << "Menu" << endl;
		cout << endl;
		cout << "1. Display the number of nodes(5 marks)" << endl;
		cout << "2. Display the number of edges(5 marks)" << endl;
		cout << "3. Display the number of source nodes(5 marks)" << endl;
		cout << "4. Display the number of sink nodes(5 marks)" << endl;
		cout << "5. Display the number of isolated nodes (5 marks)" << endl;
		cout << "6. Display the Number of Bridge Edges" << endl;
		cout << "8. Display the shortest path length distribution(20 marks) " << endl;
		cout << "9. Display the Diameter Of the Graph." << endl;
		cout << "10. Display the in - degree distribution in the form of a table(10 marks)" << endl;
		cout << "11. Display the out - degree distribution in the form of a table(10 marks) " << endl;
		cout << "12. Display the size of the largest strongly connected component (SCC) (25 marks)" << endl;
		cout << "13. Display the size distribution of all SCCs (10 marks)" << endl;
		cout << "14. Display the size of the largest weakly connected component (WCC) (25 marks)" << endl;
		cout << "15. Display the size distribution of all WCCs(10 marks)" << endl;
		cout << "\033[1;31m";
		cout << "Choose from Above Options or enter q to quit" << endl;
		cout << "\033[0m";
		cin >> input;
		if (input == "1")
		{
			cout << "You have choosen option 1: " << endl;
			Gobj.DisplayTotalNode();
		}
		else if (input == "2")
		{
			cout << "Number of Edges in Graph Are: ";
			cout << Gobj.calculateNumberofEdges() << endl;
		}
		else if (input == "3")
		{
			Gobj.DisplaySourceNodes();
		}
		else if (input == "4")
		{
			cout << "Calculating Sink Node..." << endl;
			Gobj.DisplayNumberOfSinkNodes();
		}
		else if (input == "5")
		{
			Gobj.DisplayIsolatedNodes();
		}
		else if (input == "6")
		{
			cout << "Calculating Bridge Edges..." << endl;
			UndirectedGraphObject.BridgeEdges();
		}
		else if (input == "8")
		{
			cout << "Calculating Shortest Path Distribution...";
			UndirectedGraphObject.findingshortestpath();
			cout << endl;
			cout << "Calculated Successfuly" << endl;
			string input2 = "";
			cout << "1. You want to display the whole distribution table." << endl;
			cout << "2. You want to search in the distribution table." << endl;
			cin >> input2;
			if (input2 == "1")
			{
				storePathDistribution.displayDistributionGraph();
			}
			else if (input2 == "2")
			{
				int serchdist;
				cout << "Enter the value of distribution you want to search in distribution table. " << endl;
				cin >> serchdist;
				storePathDistribution.SearchD(serchdist);
			}
		}
		else if (input == "9")
		{
			cout << "calculating The Shortest path Distribution... ";
			int diam = UndirectedGraphObject.DiameterOfTheGraph();
			cout << endl;
			cout << "Diameter of the given Graph is: " << diam << endl;
		}
		else if (input == "10")
		{
			cout << "Calculating Indegree Disbtribution..." << endl;
			Gobj.IndegreeDistribution();
			storeIndegree.CalculateProbability(Gobj.getTotalNodes());
			cout << endl;
			cout << "Calculated Successfuly" << endl;
			string input2 = "";
			cout << "1. You want to display the whole distribution table." << endl;
			cout << "2. You want to search in the distribution table." << endl;
			cin >> input2;
			if (input2 == "1")
			{
				storeIndegree.displayProbdistribution();
			}
			else if (input2 == "2")
			{
				int serchdist;
				cout << "Enter the value of distribution you want to search in distribution table. " << endl;
				cin >> serchdist;
				storeIndegree.Search(serchdist);
			}
		}
		else if (input == "11")
		{
			cout << "Calculating outdegreedegree Disbtribution..." << endl;
			Gobj.OutDegreeDistribution();
			storeoutdegree.CalculateProbability(Gobj.getTotalNodes());
			cout << endl;
			cout << "Calculated Successfuly" << endl;
			string input2 = "";
			cout << "1. You want to display the whole distribution table." << endl;
			cout << "2. You want to search in the distribution table." << endl;
			cin >> input2;
			if (input2 == "1")
			{
				storeoutdegree.displayProbdistribution();
			}
			else if (input2 == "2")
			{
				int serchdist;
				cout << "Enter the value of distribution you want to search in distribution table. " << endl;
				cin >> serchdist;
				storeoutdegree.Search(serchdist);
			}
		}
		else if (input == "12")
		{
			cout << "Calculating Stronlgy connected component..." << endl;
			int max = Gobj.stronglyconnectedAlgorithm();
			cout << "The largest Size of the strongly connected component is : " << max << endl;
		}
		else if (input == "13")
		{
			cout << "Calculating Distribution of strongly connected component...";
			int max = Gobj.stronglyconnectedAlgorithm();
			cout << "Calculated Successfuly..." << endl;
			string input2 = "";
			cout << "1. You want to display the whole distribution table." << endl;
			cout << "2. You want to search in the distribution table." << endl;
			cin >> input2;
			if (input2 == "1")
			{
				storeSSC.displayDistributionGraph();
			}
			else if (input2 == "2")
			{
				int serchdist;
				cout << "Enter the value of distribution you want to search in distribution table. " << endl;
				cin >> serchdist;
				storeSSC.SearchD(serchdist);
			}
		}
		else if (input == "14")
		{
			int max = UndirectedGraphObject.weaklyConnectedComponents();
			cout << "The largest size of the weakly connected component is: " << max << endl;
		}
		else if (input == "15")
		{
			cout << "calculating Distribution..." << endl;
			UndirectedGraphObject.weaklyConnectedComponents();
			cout << "Calculated Successfuly..." << endl;
			string input2 = "";
			cout << "1. You want to display the whole distribution table." << endl;
			cout << "2. You want to search in the distribution table." << endl;
			cin >> input2;
			if (input2 == "1")
			{
				storeWeaklyCC.displayDistributionGraph();
			}
			else if (input2 == "2")
			{
				int serchdist;
				cout << "Enter the value of distribution you want to search in distribution table. " << endl;
				cin >> serchdist;
				storeWeaklyCC.SearchD(serchdist);
			}

		}
	} while (input != "q");
	return 0;
}