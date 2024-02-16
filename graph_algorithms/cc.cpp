
#include <iostream>
#include <string>
#include <vector>
#include "adts/graph.h"
#include "directedGraph.h"
#include "graphAlgorithms.h"


using namespace std;

/**
 * Loads a graph in from standard input,
 *  according to the input specification for 
 *  the problem "Cross country"
 * @param n The number of vertices
 * @return a pointer to an DirectedGraph
 */
Graph* loadGraph(int n) {

// First line data looks like this:
// 4 | 1 | 3  --> # vertices | src vertex | dest vertex
// Make a directed graph with n vertices
  Graph *g = new DirectedGraph(n+1);

// Next lines look like this:

// 0 1 3 14
// 2 0 4 22
// 3 10 0 7
// 13 8 2 0

// This is a square matrix, the horizontal line is 0
// because the time it takes to go from one vertice to itself is 0.
// We can access each element using a double for loop.

// declare variable to store weight (aka distance) of each edge.
  int weight;

  for (int i = 0; i < n; i++) {
    //i = current line
    for (int j = 0; j < n; j++) {
      //j = current col
      cin >> weight;

      // //for debugging
      // printf("Time from %d to %d: %d minutes\n", i, j, weight);

      g->insertEdge(i, j, weight);
    }
  }
  return g;
}


int main(int argc, char **argv) {
  
  int n, src, dest;

  cin >> n >> src >> dest;

  Graph *g = loadGraph(n);

  //store distance from src to all other reachable vertices.
  vector<int> d_from_src = singleSourceShortestPath(g, src);

  for (int i = 0; i < d_from_src.size(); i++) {

    // //for debugging
    // printf("Min time from %d to %d is: %d minutes\n", src, i, d_from_src[i]);

    if (i == dest) {
      cout << d_from_src[i] << endl;
      delete g;
      return 1;
    }
  }
  
  return 0;
}
