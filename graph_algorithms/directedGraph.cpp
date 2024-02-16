
#include "directedGraph.h"
#include <string>
#include <stdexcept>

using std::to_string;
using std::runtime_error;

DirectedGraph::DirectedGraph(int numVertices): n(numVertices) {
  adjList = new vector<Edge>[n];
}

DirectedGraph::~DirectedGraph() {
  delete[] adjList;
}

int DirectedGraph::numVertices() {
  return this->n;
}

void DirectedGraph::insertEdge(int src, int dest, int weight) {
  if((src < 0) || (src>=this->n)) {
    throw runtime_error("insertEdge: source vertex " + to_string(src)
			+ " doesn't exist");
  }
  if((dest < 0) || (dest >= this->n)) {
    throw runtime_error("insertEdge: destination vertex "
			+ to_string(dest) + " doesn't exist");
  }


  // see if (src, dest) already in graph
  for(int i=0; i<this->adjList[src].size(); i++) {
    if(this->adjList[src].at(i).destination == dest) {
      throw runtime_error("edge (" + to_string(src) + ", "+ to_string(dest) + ") already exists");
    }
  }

  this->adjList[src].push_back(Edge(src, dest, weight));
}





vector<int> DirectedGraph::getNeighbors(int source) {
  if((source < 0) || (source >= this->n)) {
    throw runtime_error("vertex " + to_string(source) + " doesn't exist");
  }

  vector<int> results;

  for(int i=0; i<this->adjList[source].size(); i++) {
    results.push_back(this->adjList[source].at(i).destination);
  }

  return results;
}

vector<Edge> DirectedGraph::getOutgoingEdges(int source) {
  if((source < 0) || (source >= this->n)) {
    throw runtime_error("vertex " + to_string(source) + " doesn't exist");
  }
  return this->adjList[source];
}
