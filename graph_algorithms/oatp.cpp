
#include <iostream>
#include <string>
#include <vector>
#include "adts/graph.h"
#include "undirectedGraph.h"
#include "graphAlgorithms.h"

using namespace std;

/**
 * Loads a graph in from standard input,
 *  according to the input specification for 
 *  the problem "On average they're purple"
 * @param n The number of vertices
 * @param m The number of edges
 * @return a pointer to an UndirectedGraph
 */
Graph* loadGraph(int n, int m) {
  int src,dest;

  // Graph stores vertices 0...n-1, but input uses vertices 1...n
  //   so create a graph with an extra vertex
  Graph *g = new UndirectedGraph(n+1);

  //user input existing cable connections.
  for (int i =0; i<m; i++) {
    cin >> src >> dest;
    g->insertEdge(src,dest); 
  }
  return g;
}


int main(int argc, char **argv) {

  //load data into a graph
  int n,m;
  
  cin >> n >> m;

  Graph *g = loadGraph(n,m);
  
  //find shortest path from 1 to n
  vector<int> shortest_path = shortestLengthPathBFS(g, 1, n);

  int mcl; //max color change

  //max color change is the length of the shortest path - 1.
  //which is the number of vertices in the vector - 2.
  // numVertices >= 2 in problem, so mcl >= 0;
  mcl = shortest_path.size() - 2;

  cout << mcl << endl;

  delete g;
  
  return 1;
}
