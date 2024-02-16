#include <iostream>
#include <string>
#include <vector>
#include "directedGraph.h"
#include "undirectedGraph.h"
#include "graphAlgorithms.h"
#include "adts/dictionary.h"
#include "adts/graph.h"

using namespace std;

template <class G = UndirectedGraph>
Graph *makeGraph(int size, vector<Edge> edges) {
  Graph *graph = new G(size);
  for(int i=0; i<edges.size(); i++) {
    Edge e= edges[i];
    graph->insertEdge(e.source, e.destination, e.weight);
  }

  return graph;
}

int main(int argc, char **argv) {
  /*
  Create example graph for minimum spanning tree.
  */
  // Graph *mst_g = makeGraph(9,
  //                          {
  //                            {0,2,2}, {0,3,3},
  //                            {1,3,8},
  //                            {2,4,1}, {2,5,4},
  //                            {3,6,5},
  //                            {4,7,2},
  //                            {5,7,7}, {5,8,3},
  //                            {6,8,2}
  //                          });
  // cout << "Test MST on inclass example here" << endl;

  // /*
  //   Create example graph for SSSP.
  // */
  // Graph *sssp_g = makeGraph<DirectedGraph>(5,
  //                                       {
  //                                         {0, 1, 10}, {0, 2, 3}, {0, 3, 20},
  //                                         {1, 3, 2},
  //                                         {2, 1, 2}, {2, 4, 15},
  //                                         {3, 4, 11}
  //                                       });
  // cout << "Test SSSP on inclass example from vertex 0 here" << endl;


  Graph* graph = makeGraph(6,
      {
        {1,2,1}, {1,3,1}, {2,3,1}, {2,4,1},{4,5,1}
      });

  vector<int> path = shortestLengthPathBFS(graph, 1, 5);
  for (int i =0;i<path.size();i++){
    cout << path[i] << endl;
  }

  return 0;
}
