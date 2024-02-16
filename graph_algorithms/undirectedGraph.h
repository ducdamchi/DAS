#pragma once

#include "adts/edge.h"
#include "adts/graph.h"
#include "adts/stlBST.h"
#include "directedGraph.h"

/**
 * UndirectedGraph is a class representing undirected, weighted graphs.
 * Vertices in this graph class are labeled 0,...,n-1.
 * 
 * UndirectedGraph leverages the existing DirectedGraph class.
 * each undirected edge (u,v) is stored as two directed edges: u-->v and v-->u
 */
class UndirectedGraph : public DirectedGraph {
public:
  UndirectedGraph(int numVertices);
  void insertEdge(int src, int dest, int weight=1);
};
