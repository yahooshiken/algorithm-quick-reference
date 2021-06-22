#ifndef _BFS_H_
#define _BFS_H_

#include <queue>

#include "graph.h"

void bfsSearch(Graph const &graph, int s, vector<int> &dist, vector<int> pred);

#endif