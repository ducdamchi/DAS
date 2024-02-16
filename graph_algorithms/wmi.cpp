
#include <iostream>
#include <vector>
#include <algorithm>
#include "adts/graph.h"
#include "undirectedGraph.h"
#include "graphAlgorithms.h"

using namespace std;

/**
 * Loads a graph in from standard input,
 *  according to the input specification for 
 *  the problem "Where's My Internet??"
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
  
  
  //collect all vertices reachable from House #1
  vector<int> r = reachableDFS(g, 1);

  //if all houses are reachable from 1
  if (r.size() == n) {
    cout << "Connected" << endl;
  }

  //if not all houses are reachable
  else {
    for (int i = 1; i <= n; i++) {

      //C++ extension algorithm for finding element in a vector.
      if (find(r.begin(), r.end(), i) != r.end()) {
        //If house found, do nothing.
      }
      else {
        //If house not found, prints house # (alr in increasing order)
        cout << i << endl;
      }
    }
  }
  delete g;
  
  return 1;
}
