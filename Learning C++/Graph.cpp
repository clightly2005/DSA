#include <iostream>
#include <vector>
using namespace std;

//computers cant see a picture so we need a data structure to record which node connects to each other
//Example: University campus site map with the paths between each building and their set numbers: the graph is undirected and weighted.

//STEP 1 draw out matrix or list depending on what you will code

//Adjacency matrix = grid of V x V cells where V is no. of vertices. cell at row i, column j holds the weight from edge i to j. BEST FOR desnse graphs (lots of edges)

/*
* for this scenario the numbers are the weighted paths (amount of time to walk between each building)
* 
*			library		cafe	lecture	   gym		halls
* library		no		 4		   no		6		  no
* cafe			4		 no		   1		5		  9
* lecture		no		 1		   no		no		  7
* gym			6		 5		   no		no		  3
* halls			no	     9		   7		3		  no
*/



//Adjacency list = one list per vertex. Each vertex holds its actual neighbour stored as ( neighbour, weight) pairs. BEST FOR sparese graphs.
//this is the usual default

/*
* for this scenario library = 0, cafe = 1 and so on...
* the pair represents the next node it points to [1,] and the weight of that path [,4]
* 
* the list only stores edges that exist unlike a matrix which stores all the 'no' (infinity) blanks.
* 
* Array			Linked list
*
*	0		->	[1,4]  ->  [3,6] 
*	1		->	[0,4]  ->  [2,1]  -> [3,5]  ->  [4,9]	
*	2		->  [1,1]  ->  [4,7]
*	3		->  [0,6]  ->  [1,5]  -> [4,3]
*	4		->  [1,9]  ->  [2,7]  -> [3,3]
*/


class Graph {
//STEP 2 After turning the graph in question into a adj matrix /list^, make a graph class and decide what it needs to store 
private:
	//no of vertices = 5
	int totalVertices;

	//outer vector = a list of rows/one row per node, inner vector = a list of pairs: the vertex's neighbour and weight
	vector<vector<pair<int, int>>> adjList;

	//If we had: A=0, B=1, C=2, D=3, E=4
	//adjList[2] would be C's row: [ {0,1}, {1,2}, {3,5}, {4,12} ]
	//adjList[2][1] would be 2nd pair in row C: {1,2}
	//adjList[2][1].first is 1 meaning C connects to B

	//if a graph has no weights - DO NOT need a pair, vector<vector<int>> is enough where each row is a list of neighbour nodes


public:
	//constructor - sets up a starting state of object that is created when Graph is called so it needs an empty list the size of total vertices for add() to work
	Graph(int tv) {
		totalVertices = tv;
		adjList.resize(tv);
	};
	
	//add to adj list - outer vector being from, inner pair have to,weight?
	void addEdge(int from, int to, int weight) {
		//find row right now with from and add to the end of it with to and weight
		adjList[from].push_back({ to, weight });
		//since undirected graph the to also needs to know how to get back
		adjList[to].push_back({ from, weight });
	}



	void printMethod() {
		//loop through every vertex and print row 
		for (int i = 0; i < totalVertices; i++) {
			const vector<pair<int,int>>& row = adjList[i];
			cout << i << "->";

			//for each box in that row, print
			for (const auto& b : row) {//auto tells compiler what type it is
				cout << "[" << b.first << ", " << b.second << "] -> ";
			}
			cout << " null" << endl;
		}
	}


};
