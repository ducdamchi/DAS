#pragma once

#include "adts/edge.h"
#include "adts/graph.h"
#include "adts/stlBST.h"

/**
 * DirectedGraph is a class representing directed, weighted graphs.
 * Vertices in this graph class are labeled 0,...,n-1.
 * The graph is stored in an adjacency list
 *   adjList is an array of Edge vectors -- each vector stores
 *   the edges incident to one vertex
 */
class DirectedGraph : public Graph {
public:
  DirectedGraph(int numVertices);
  virtual ~DirectedGraph();

  int numVertices();
  virtual void insertEdge(int src, int dest, int weight=1);
  virtual vector<int> getNeighbors(int source);
  virtual vector<Edge> getOutgoingEdges(int source);
  
private:
  vector<Edge> *adjList;
  int n;
};
