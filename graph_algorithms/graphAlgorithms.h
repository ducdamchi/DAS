#pragma once

#include <vector>

using std::vector;

#include "adts/edge.h"
#include "adts/graph.h"

/**
 * Returns all vertices reachable from the source vertex
 * @param g A pointer to the Graph object.
 * @param src The source vertex.
 * @return a vector of vertices reachable from src if a path exists
 */
vector<int> reachableDFS(Graph *g, int src);

/**
 * Returns the shortest length path found from the vertex src
 * to the vertex dest, using an unweighted breadth-first search of the graph.
 * @param g - pointer to Graph object
 * @param src - source vertex
 * @param dest - destination vertex
 * @return vector<int> - sequence of vertices in path from src to dest
 * @error throws runtime_error if no path exists
 */
vector<int> shortestLengthPathBFS(Graph *g, int src, int dest);

/**
 * dijkstra calculates the single source minimum distance to all other
 *   vertices in the graph from a src node
 * @param g - pointer to Graph object to search
 * @param src - source vertex
 * @return vector<int> - vector of distances from source vertex
 *     for any vertex that is not reachable from source, make the distance -1
 */
vector<int> singleSourceShortestPath(Graph *g, int src);

/**
 * Prim's algorithm computes the value of the MST 
 *
 * @param g - pointer to Graph object to build MST for
 * @return vector<Edge> - edges in the MST
 * @error throws runtime_error if graph is not connected
 */
vector<Edge> computeMST(Graph *g);
