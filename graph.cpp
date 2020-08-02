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

		// Sets the number of the nodes
		void setNumberOfNodes(int value){
			this->numberOfNodes = value;
		}

	public:
	
		adjacentVertice **head; // Adjacency list as array of pointers
		
		// Constructor
		Graph(graphEdge edges[], int numberOfEdges, int numberOfNodes)  {
			
			// Allocate new node
			head = new adjacentVertice*[numberOfNodes]();
			setNumberOfNodes(numberOfNodes);
			
			// Initialize head pointer for all vertices
			for (int i = 0; i < numberOfNodes; ++i)
				head[i] = nullptr;
			
			// Construct directed graph by adding edges to it
			for (unsigned i = 0; i < numberOfEdges; i++)  {
				int startVertice = edges[i].startVertice;
				int endVertice = edges[i].endVertice;
				int weight = edges[i].weight;
				
				// Insert in the beginning
				adjacentVertice* newNode = getAdjacentListVertice(endVertice, weight, head[startVertice]);
			
                // Point head pointer to new node
				head[startVertice] = newNode;
       		}
		}

		// Destructor
		~Graph() {
			for (int i = 0; i < getNumberOfNodes(); i++)
				delete[] head[i];
				delete[] head;
		}

		// Insert new nodes into adjacency list from given graph
		adjacentVertice* getAdjacentListVertice(int value, int weight, adjacentVertice* head) 	{
			adjacentVertice* newVertice = new adjacentVertice();
			newVertice->value = value;
			newVertice->cost = weight;
			
			newVertice->next = head;   // Point new node to current head

			return newVertice;
		}

		int getNumberOfNodes(){
			return numberOfNodes;
		}

};

// Print all adjacent vertices of given vertex
void showAdjacentList(adjacentVertice* ptr, int i){

	while (ptr != nullptr) {
		cout << "(" << i << ", " << ptr->value
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
		showAdjacentList(diagraph.head[i], i);
	}

	return 0;
}
