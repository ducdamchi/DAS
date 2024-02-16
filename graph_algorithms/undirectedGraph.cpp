
#include "undirectedGraph.h"
#include <string>
#include <stdexcept>

using std::to_string;
using std::runtime_error;

UndirectedGraph::UndirectedGraph(int n): DirectedGraph(n) {}

void UndirectedGraph::insertEdge(int src, int dest, int weight) {
  // insert the edge as two directional edges.                                 
  // This lets getNeighbors to work without changes.

  // TO DO: implement this method
  this->DirectedGraph::insertEdge(src, dest, weight);
  this->DirectedGraph::insertEdge(dest, src, weight);
}
