************* USING GRAPH ALGORITHMS TO SOLVE CPP *************

In this project, I organized the data structures learned in class
in a way that they could be quickly modified to solve programming 
problems. To demonstrate, I picked my favorite four problems of 
varying difficulty on Kattis, and solved them with minimum code, 
relying mainly on the data structures that are already established.

***** Navigation *****

/KATTIS PROBLEMS folder contains the four problems, namely:
- Where's my Internet?? (WMI)       <requires Undirected Graph and DFS>
- On Average They're Purple (OATP)  <requires Undirected Graph and BFS>
- Cross Country (CC)                <requires Directed Graph and Dijkstra's algorithm>
- Minimum Spanning Tree (MST)       <requires Undirected Graph and Prim's algorithm>

graphAlgorithms, directedGraph, undirectedGraph: implementation of various ADTs.

wmi.cpp, oatp.cpp, cc.cpp, mst.cpp: where main solutions are written.

/test_data folder contains pre-written inputs to test the main solutions.
It could be run, i.e: ./wmi test_data/wmi-in3
