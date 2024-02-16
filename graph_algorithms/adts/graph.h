#pragma once

#include <string>
#include <vector>
#include "edge.h"

using std::string;
using std::vector;

/**
 * Graph is a class representing directed, weighted graphs.
 * Vertices in this graph class are labeled 0,...,n-1.
 */
class Graph {
public:
  virtual ~Graph() {}

  virtual int numVertices() = 0;
  
  virtual void insertEdge(int src, int dest, int weight=0) = 0;

  virtual vector<int> getNeighbors(int source) = 0;

  virtual vector<Edge> getOutgoingEdges(int source) = 0;
  
  
public:
    Graph() { }
private:
    Graph(const Graph& other) = delete;
    Graph& operator=(const Graph& other) = delete;
};
