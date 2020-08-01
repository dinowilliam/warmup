/************************************************************************************************************************************/
/*  Warmup                                                                                                                          */
/*  Dijkstra’s Shortest Path Algorithm                                                                                              */
/*  Graph Study                                                                                                                     */
/*  Program:graph.cpp                                                                                                               */
/*  By: William Ferreira de Paula                                                                                                   */
/*  Date: 30/07/2020                                                                                                                */
/************************************************************************************************************************************/

#include <iostream>

using namespace std;

// Stores adjacency list items
struct adjacentVertice {
	int value, cost;
	adjacentVertice* next;
};

// Structure to store edges
struct graphEdge {
	int startVertice, endVertice, weight;
};

class Graph{

	private:	
		int numberOfNodes;  // Number of nodes in the graph

	public:
	
		adjacentVertice **head; //Adjacency list as array of pointers
		
		// Constructor
		Graph(graphEdge edges[], int n, int N)  {
			
			// allocate new node
			head = new adjacentVertice*[N]();
			this->numberOfNodes = N;
			
			// initialize head pointer for all vertices
			for (int i = 0; i < N; ++i)
				head[i] = nullptr;
			
			// construct directed graph by adding edges to it
			for (unsigned i = 0; i < n; i++)  {
				int start_ver = edges[i].start_ver;
				int end_ver = edges[i].end_ver;
				int weight = edges[i].weight;
				// insert in the beginning
				adjacentVertice* newNode = getAdjListNode(end_ver, weight, head[start_ver]);
			
                // point head pointer to new node
				head[start_ver] = newNode;
       		 }
		}

		// Destructor
		~Graph() {
			for (int i = 0; i < N; i++)
				delete[] head[i];
				delete[] head;
		}

		// Insert new nodes into adjacency list from given graph
		adjacentVertice* getAdjacentListVertice(int value, int weight, adjNode* head) 	{
			adjacentVertice* newVertice = new adjVertice;
			newVertice->val = value;
			newVertice->cost = weight;
			
			newVertice->next = head;   // Point new node to current head

			return newVertice;
		}

		int getNumberOfNodes(){
			return numberOfNodes;
		}

};

// print all adjacent vertices of given vertex
void showAdjacentList(adjacentVertice* ptr, int i){

	while (ptr != nullptr) {
		cout << "(" << i << ", " << ptr->val
			<< ", " << ptr->cost << ") ";
		ptr = ptr->next;
	}

	cout << endl;
}

// graph implementation
int main(){

	// graph edges array.
	graphEdge edges[] = {
		// (x, y, w) -> edge from x to y with weight w
		{0,1,2},{0,2,4},{1,4,3},{2,3,2},{3,1,4},{4,3,3}
	};
	
	int N = 6;      // Number of vertices in the graph
	
	// calculate number of edges
	int n = sizeof(edges)/sizeof(edges[0]);
	
	// construct graph	
	Graph diagraph(edges, n, N);

	// print adjacency list representation of graph
	cout<<"Graph adjacency list "<<endl<<"(start_vertex, end_vertex, weight):"<<endl;
	
	for (int i = 0; i < N; i++)	{
		// display adjacent vertices of vertex i
		display_AdjList(diagraph.head[i], i);
	}

	return 0;
}
