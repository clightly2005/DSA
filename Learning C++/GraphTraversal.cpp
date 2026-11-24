#include <queue>
#include <vector>
#include <iostream>
using namespace std;
//DFS and BFS

/*
	Depth First Search

		Goes as deep as possible down one path and backtracks and tries the next branch


	Implementation start pack:
		
		Visited array of bools, one per vertex. 
		Recursion - function marks current node as visited and calls itself on each unvisited neighbour
		    

	Use it for:

		Checking if path exists 
		Counting connected components
		Detecting cycles
		Topological sort
		Maze or sudoku

*/



/*
	Breadth First Search

		Explores in rings. First all nodes 1 edge away then 2 edges away and so on.


	Implementation start park:

		Use std::queue and FIFO
		Mark node as visited when you push it
		Add distance array (Start at 0, neighbour = current + 1)
		Add parent array (who discovered me)
		Following parent backwards from target rebuilds path


	Use it for:

		Shortest path when every edge costs the same
		Grid puzzles


	**** BFS ignores weights ****

*/


//Graph class - go to graph.cpp if need a refresher on this set up

class Graph {

private:

	int totalVertices;

	vector<vector<pair<int, int>>> adjList;

public:
	
	Graph(int tv) {
		totalVertices = tv;
		adjList.resize(tv);
	};

	void addEdge(int from, int to, int weight) {
		adjList[from].push_back({ to, weight });
		adjList[to].push_back({ from, weight });
	}

	void printGraph() {

		for (int i = 0; i < totalVertices; i++) {
			const vector<pair<int, int>>& row = adjList[i];
			cout << i << " -> ";

			for (const auto& b : row) {
				cout << "[" << b.first << ", " << b.second << "] ->";
			}

			cout << " null" << endl;
		}
	}



	void BFS(int start) {
		//queue of node numbers waiting to be processed
		queue<int> q;

		//visited node tracker list - all set to false
		vector<bool> visited(totalVertices, false);

		//mark start as visited
		visited[start] = true;

		//push starting node into queue
		q.push(start);

		while (!q.empty()) {
			int current = q.front(); //store front var from queue
			q.pop(); //remove front var from queue

			for (const auto& edgeNode : adjList[current]) {
				//get next node from first part of pair
				int neighbour = edgeNode.first;
				//if node isn't in visited list then set ti as visited and add to queue
				if (!visited[neighbour]) {
					visited[neighbour] = true;
					q.push(neighbour);
				}

			}

			cout << "Visiting " << current << " node" <<endl;
		}
	}


	void DFS(int start) {

	}

};


