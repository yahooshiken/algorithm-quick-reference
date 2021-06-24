#ifndef _DIJKSTRA_H_
#define _DIJKSTRA_H_

#include "graph.h"

void dijkstra(Graph const &g, int s, vector<int> &dist, vector<int> &pred);

void dijkstraDense(Graph const &g, int s, vector<int> &dist, vector<int> &pred);

#endif