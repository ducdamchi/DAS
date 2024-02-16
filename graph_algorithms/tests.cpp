
#include <algorithm>
#include <fstream>
#include <string>
#include <vector>
#include <UnitTest++/UnitTest++.h>

#include "directedGraph.h"
#include "undirectedGraph.h"
#include "graphAlgorithms.h"
#include "adts/dictionary.h"
#include "adts/graph.h"

using namespace std;

/* helper check function that verifies there are no
   duplicate values in a vector */
template <typename T>
void noDupesCheck(vector<T> expr);

/* helper check function that verifies that
   two vectors are set equivalent. An item
   is in the first vector iff it is in the
   second vector.  */
template <typename T>
void vectorsEqualCheck(vector<T> first, vector<T> second);

/* helper function to check if two paths are equivalent */
void checkEqualPath(vector<int> expected, vector<int> actual);

template <class G = UndirectedGraph>
Graph *makeGraph(int size, vector<Edge> edges) {
  Graph *graph = new G(size);
  for(int i=0; i<edges.size(); i++) {
    Edge e= edges[i];
    graph->insertEdge(e.source, e.destination, e.weight);
  }

  return graph;
}

TEST(getEdges) {
  // Creates an undirected graph with 4 edges:
  // 0 {no edges to 0}
  // 1  ---       1     --- 2  ---  1  --- 4
  //    \                  /
  //     \                /
  //      1             1
  //        \          /
  //         \        /
  //            3
  // and queries getEdges to ensure duplicates are correctly removed
  Graph* graph = makeGraph(5,
      {
        {1,2,1}, {1,3,1}, {2,3,1}, {2,4,1}
      });
  vector<Edge> edges = graph->getOutgoingEdges(1);
  CHECK_EQUAL(2,edges.size());
  edges = graph->getOutgoingEdges(2);
  CHECK_EQUAL(3,edges.size());
  edges = graph->getOutgoingEdges(0);
  CHECK_EQUAL(0, edges.size());
  delete graph;
}

TEST(dfsTwoVertexGraph) {
  // This creates the *undirected* graph:
  //    0  --- 1 ---  1
  Graph *graph = makeGraph(2, {{0, 1, 1}});
  vector<int> zero = {0,1};
  vector<int> one = {0,1};
  vectorsEqualCheck(zero, reachableDFS(graph,0));
  vectorsEqualCheck(one, reachableDFS(graph,1));
  delete graph;
}

TEST(dfsTwoDisconnectedVertices) {
  // This creates the *undirected* graph:
  //    0                 1
  Graph *graph = makeGraph(2, {});
  vector<int> empty = {};
  vector<int> zero = {0};
  vector<int> one = {1};
  vectorsEqualCheck(zero, reachableDFS(graph, 0));
  vectorsEqualCheck(one, reachableDFS(graph, 1));
  delete graph;
}

TEST(dfsThreeVertexDirectedGraph) {
  // This call makes a *directed* graph!
  Graph *graph = makeGraph<DirectedGraph>(3,
          {
              {0, 1, 1}, {0, 2, 1},
          });
  vector<int> zero = {0,1,2};
  vector<int> one = {1};
  vector<int> two = {2};
  vectorsEqualCheck(zero, reachableDFS(graph, 0));
  vectorsEqualCheck(one, reachableDFS(graph, 1));
  vectorsEqualCheck(two, reachableDFS(graph, 2));
  delete graph;
}


TEST(bfsThreeVertexClique) {
  // This call makes an undirected graph.
  Graph *graph = makeGraph(3,
      {
          {0, 1, 1}, {0, 2, 1}, {1, 2, 1},
      });
  vector<int> path = {0, 2};
  checkEqualPath(path, shortestLengthPathBFS(graph, 0, 2));
  path = {0, 1};
  checkEqualPath(path, shortestLengthPathBFS(graph, 0, 1));
  delete graph;
}

TEST(bfsFiveVertex) {
  // This call makes an undirected graph.
  Graph *graph = makeGraph(5, {{0, 1, 1},
                                             {1, 2, 1},
                                             {2, 3, 1},
                                             {0, 4, 1},
                                             {4, 3, 1}});
  vector<int> path = {0,4,3};
  checkEqualPath(path, shortestLengthPathBFS(graph, 0, 3));
  delete graph;
}

TEST(bfsFiveVertexDirected) {
  // This call makes a directed graph.
  Graph *graph =
      makeGraph<DirectedGraph>(5, {{0, 1, 1},
                                                 {1, 2, 1},
                                                 {2, 3, 1},
                                                 {3, 4, 1},
                                                 {4, 0, 1}});
  vector<int> path = {0,1,2,3};
  checkEqualPath(path, shortestLengthPathBFS(graph, 0, 3));
  delete graph;
}



TEST(ssspFiveVertex) {
  // This call makes an undirected graph.
  Graph *graph = makeGraph(5, {{0, 1, 3},
                                             {1, 2, 4},
                                             {2, 3, 2},
                                             {0, 4, 5},
                                             {4, 3, 6}});
  vector<int> results = 
    singleSourceShortestPath(graph,0);
  CHECK_EQUAL(9, results[3]);
  CHECK_EQUAL(7, results[2]);
  CHECK_EQUAL(5, results[4]);
  delete graph;
}

TEST(ssspFiveVertexDirected) {
  // This call makes a directed graph.
  Graph *graph =
      makeGraph<DirectedGraph>(5, {{3, 2, 3},
                                                 {2, 1, 4},
                                                 {1, 0, 2},
                                                 {0, 4, 5},
                                                 {4, 3, 6}});
  vector<int> results =
    singleSourceShortestPath(graph, 0);
  CHECK_EQUAL(11, results[3]);
  CHECK_EQUAL(14, results[2]);
  CHECK_EQUAL(5, results[4]);
  delete graph;
}

TEST(mst) {
  Graph *graph = makeGraph(9, {{0,2,2},
			       {0,3,3},
			       {1,3,8},
			       {2,4,1},
			       {2,5,4},
			       {3,6,5},
			       {4,7,2},
			       {5,7,7},
			       {5,8,3},
			       {6,8,2}});
  vector<Edge> mst = computeMST(graph);
  vector<Edge> expectedMST = {{0,2,2},
			       {0,3,3},
			       {1,3,8},
			       {2,4,1},
			       {2,5,4},
			       {3,6,5},
			       {4,7,2},
			       {5,8,3},
			       {6,8,2}};
  int accum=0;
  for(int i=0; i<mst.size(); i++) {
    accum += mst[i].weight;
  }
  CHECK_EQUAL(25, accum);
  delete graph;
}

int main() { return UnitTest::RunAllTests(); }

void checkEqualPath(vector<int> expected, vector<int> actual) {
  CHECK_EQUAL(expected.size(), actual.size());
  for(int i=0; i<expected.size(); i++) {
    CHECK_EQUAL(expected.at(i), actual.at(i));
  }

}

template <typename T>
void noDupesCheck(vector<T> expr){
    auto vec = expr;
    auto it = vec.begin();
    while (it < vec.end()) {
      if (find(it + 1, vec.end(), *it) != vec.end()) {
        CHECK_EQUAL(to_string(*it) + " to be unique in vector",
                    to_string(*it) + " in vector twice");
      }
      it++;
    }
}

template <typename T>
void vectorsEqualCheck(vector<T> first, vector<T> second){
    auto expected = first;
    auto actual = second;
    noDupesCheck(actual);
    CHECK_EQUAL(expected.size(), actual.size());
    for (int i = 0; i < expected.size(); i++) {
      if (find(actual.begin(), actual.end(), expected[i]) ==
          actual.end()) {
        CHECK_EQUAL(to_string(expected[i]) + " to be in vector", "no such result");
      }
    }
    for (int i = 0; i < actual.size(); i++) {
      if (find(expected.begin(), expected.end(), actual[i]) ==
          expected.end()) {
        CHECK_EQUAL(to_string(actual[i]) + " not to be in vector",
                    to_string(actual[i]) + " in vector");
      }
    }
  }
