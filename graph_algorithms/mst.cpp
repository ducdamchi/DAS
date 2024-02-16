
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "adts/graph.h"
#include "undirectedGraph.h"
#include "graphAlgorithms.h"

using namespace std;


/**
 * Loads a graph in from standard input,
 *  according to the input specification for 
 *  the problem "Minimum Spanning Tree"
 * @param n The number of vertices
 * @param m The number of edges
 * @return a pointer to an UndirectedGraph
 */
Graph* loadGraph(int n, int m) {

  int src, dest, weight;

  //Don't need an extra vertex here
  Graph *g = new UndirectedGraph(n);

  //User input m lines of edge info.
  for (int i = 0; i < m; i++) {
    cin >> src >> dest >> weight;

    //for debugging
    // printf("from %d to %d costs %d\n", src, dest, weight);

    g->insertEdge(src, dest, weight); 
  }

  return g;
}

//function to compute cost of MST
int getMSTcost(vector<Edge> e) {
  int cost = 0;
  for (int i = 0; i < e.size(); i++) {
    cost += e[i].weight;
  }
  return cost;
}

void sortEdges(vector<Edge> &e) {

  //within each edge
  for (int i = 0; i < e.size(); i++) {

    //if the destination is < than source, swap them.
    if (e[i].destination < e[i].source) {
      swap(e[i].destination, e[i].source);

      //for debugging
      // printf("Swapped %d with %d\n", e[i].source, e[i].destination);
    }
  }
  //now in each Edge, src is always smaller than dest.

  //proceed to sort each Edge pair by lexicographic order.
  sort(e.begin(), e.end(), [](const Edge &a, const Edge &b) {
    return make_pair(a.source, a.destination) < make_pair(b.source, b.destination);
  });
}


int main(int argc, char **argv) {

  int n, m, cost;

  cin >> n >> m;

  while (!(n == 0 && m == 0)) {

    Graph *g = loadGraph(n, m);

    try {
      vector<Edge> mst = computeMST(g);

      //For debugging----before sorting
      // for (int i = 0; i < mst.size(); i++) {
      //   cout << mst[i].source << " " << mst[i].destination << endl;
      // }
      
      cost = getMSTcost(mst);

      cout << cost << endl;
      
      //For debugging-----after sorting
      // cout << "=====After sorting=====" << endl;

      
      sortEdges(mst);

      for (int i = 0; i < mst.size(); i++) {
        cout << mst[i].source << " " << mst[i].destination << endl;
      }
    }
    catch (const runtime_error &e) {
        cout << "Impossible" << endl;
    }

    delete g;
    cin >> n >> m;
  }
  return 1;
}
