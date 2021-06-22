#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <limits>
#include <list>
#include <vector>

using namespace std;

typedef pair<int, int> IntegerPair;
typedef list<IntegerPair> VertexList;
enum vertexColor { White, Gray, Black };
enum edgeType { Tree, Backward, Forward, Cross };

class Graph {

public:
  Graph() : n_(0), directed_(false) { vertices_ = new VertexList[1]; };
  Graph(int n) : n_(n), directed_(false) { vertices_ = new VertexList[n]; };
  Graph(int n, bool d) : n_(n), directed_(d) { vertices_ = new VertexList[n]; };
  ~Graph() {
    n_ = -1;
    delete[] vertices_;
  };

  // read-only information about graph
  const int numVertices() const { return n_; }
  bool isDirected() const { return directed_; }
  bool isEdge(int, int) const;
  bool isEdge(int, int, int &) const;
  int edgeWeight(int, int) const;
  VertexList::const_iterator begin(int u) const { return vertices_[u].begin(); }
  VertexList::const_iterator end(int u) const { return vertices_[u].end(); }

  // update edge structure of graph
  void addEdge(int u, int v) { addEdge(u, v, 1); }
  void addEdge(int, int, int);
  bool removeEdge(int, int);

protected:
  VertexList *vertices_;
  int n_;         // size of graph
  bool directed_; // is graph directed?
};

#endif /* _GRAPH_H_ */
