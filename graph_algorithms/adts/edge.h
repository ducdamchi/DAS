#pragma once

/**
 * An Edge is a class that represents a directed, weighted edge in a
 * graph.
 */
class Edge {
public:
  // This constructor specifies initial values of each data member
  Edge(int src, int dest, int wt) : source(src),
    destination(dest), weight(wt) {};

  // For unweighted graphs, initialize the "weight" to 1
  Edge(int src, int dest) : source(src),
    destination(dest), weight(1) {};


  int source;
  int destination;
  int weight;
};
