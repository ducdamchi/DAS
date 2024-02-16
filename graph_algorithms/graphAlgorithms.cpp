
#include <stdexcept>
#include <vector>

using std::vector;

#include "adts/edge.h"
#include "adts/graph.h"
#include "adts/stlStack.h"
#include "adts/dictionary.h"
#include "adts/stlHashTable.h"
#include "adts/stlQueue.h"
#include "adts/stlList.h"
#include "adts/stlMinPriorityQueue.h"


/**
 * Returns all vertices reachable from the source vertex
 * @param g A pointer to the Graph object.
 * @param src The source vertex.
 * @return a vector of vertices reachable from src if a path exists
 */
vector<int> reachableDFS(Graph *g, int src) {

    vector<int> result;
    STLStack<int> stack;
    STLHashTable<int,bool> visited;

    stack.push(src);
    while (!stack.isEmpty()){
      int current = stack.pop(); //is current type int?
      
      if (visited.contains(current)){
        continue;
      }

    
      visited.insert(current,true); //set current as visited
      result.push_back(current); //add current to result vector
      vector<int> neighbors = g->getNeighbors(current); //get all neighbors of current
      int size = neighbors.size();
      for (int i=0;i<size;i++){ //for each neighbor, if hasn't been visited, add it to the stack
        if (!visited.contains(neighbors[i])){
          stack.push(neighbors[i]);
        }
      }
      
    }
    return result;
}

/**
 * Returns the shortest length path found from the vertex src
 * to the vertex dest, using an unweighted breadth-first search of the graph.
 * @param g - pointer to Graph object
 * @param src - source vertex
 * @param dest - destination vertex
 * @return vector<int> - sequence of vertices in path from src to dest
 * @error throws runtime_error if no path exists
 */
vector<int> shortestLengthPathBFS(Graph *g, int src, int dest) {

  vector<int> path;
  STLQueue<int> queue;
  STLHashTable<int,int> previous;

  queue.enqueue(src);
  while (!queue.isEmpty()){
    int current = queue.dequeue();
    if (current == dest){
      break;
    }

    vector<int> neighbors = g->getNeighbors(current);
    int size = neighbors.size();
    for (int i=0;i<size;i++){
      //if we have no previous for this neigbor, set previous to be current
      if (!previous.contains(neighbors[i])){
        previous.insert(neighbors[i],current);
        queue.enqueue(neighbors[i]);
      }
    }

  }
  if (!previous.contains(dest)){
    throw std::runtime_error("No path exists");
  }
  
  else {
    vector<int> path;
    path.push_back(dest); //insert last element in previous
    int next = previous.get(dest); //getting pair value

    while (next != src){
      path.push_back(next);
      int temp = next;
      next = previous.get(temp);
    }
    path.push_back(src);

    //reversing the list
    int n = path.size();
    vector<int> reversed_path;
    for (int i=n-1;i>=0;i--){
      reversed_path.push_back(path[i]);
    }

    return reversed_path;
  }

  
}

    

/**
 * Dijkstra calculates the single source minimum distance to all other
 *   vertices in the graph from a src node
 * @param g - pointer to Graph object to search
 * @param src - source vertex
 * @return vector<int> - vector of distances from source vertex
 *     for any vertex that is not reachable from source, make the distance -1
 */
vector<int> singleSourceShortestPath(Graph *g, int src) {

  int n = g->numVertices();
  vector<int> cost;


  for (int i=0;i<n;i++){
    cost.push_back(-1);
  }

  STLMinPriorityQueue<int,int>* pq = new STLMinPriorityQueue<int,int>;
  cost[src] = 0;
  pq->insert(0,src);

  int currPriority, currVertex, currCost;
  int nextVertex, newCost;

  vector<Edge> edges;

  while (!pq->isEmpty()){

    currPriority = pq->peekPriority();
    currVertex = pq->remove();
    currCost = cost[currVertex]; 
    
    if (currCost == currPriority){

      edges = g->getOutgoingEdges(currVertex);

      for (int i= 0;i<edges.size();i++){

        nextVertex = edges[i].destination; 
        newCost = currCost + edges[i].weight;

        if (cost[nextVertex] == -1){ //if we haven't seen this vertex before 
          
          cost[nextVertex] = newCost; 
          pq->insert(newCost,nextVertex);
        }

        else if (newCost < cost[nextVertex]){ //have seen before, but found a better cost

          cost[nextVertex] = newCost;
          pq->insert(newCost, nextVertex);
        }
      }
    }
  }
  delete pq; 
  return cost;
}

/**
 * Prim's algorithm computes the value of the MST 
 *
 * @param g - pointer to Graph object to build MST for
 * @return vector<Edge> - edges in the MST
 * @error throws runtime_error if graph is not connected
 */
vector<Edge> computeMST(Graph *g) {

  vector<Edge> mst;
  vector<Edge> edges = g->getOutgoingEdges(0); //use 0 as random vertex.

  STLHashTable<int,int> visited;
  STLMinPriorityQueue<int,Edge> pq;

  Edge currEdge = Edge(0,0,-1);

  for (int i=0;i<edges.size();i++){

    pq.insert(edges[i].weight,edges[i]);

  }
  int n = g->numVertices();
  visited.insert(0,-1); //value doesn't matter, use -1

  while (mst.size() < n-1 && (!pq.isEmpty())){

    currEdge = pq.remove();

    if (!visited.contains(currEdge.destination)){

      mst.push_back(currEdge);
      visited.insert(currEdge.destination,-1);
      edges = g->getOutgoingEdges(currEdge.destination);

      for (int i=0;i<edges.size();i++){

        pq.insert(edges[i].weight,edges[i]);

      }
    }
  }
  if (mst.size() < n-1){
    throw std::runtime_error(
    "graph is not connected");
  }
  
  int size = pq.getSize();
  for (int i=0;i<size;i++){
    pq.remove();
  }


  return mst;
}
	  
