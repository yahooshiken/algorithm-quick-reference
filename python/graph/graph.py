import sys


class Graph:
    def __init__(self, n, directed=False):
        self.n = n
        self.directed = directed
        self.vertices = [[] for i in range(n)]

    def get_vertices_num(self):
        return self.n

    def get_vertices(self, u):
        return self.vertices[u]

    def is_directed(self):
        return self.directed

    def is_edge(self, u, v):
        if u > self.n or v > self.n:
            return False

        return any(v_ == v for (v_, w_) in self.get_vertices(u))

    def add_edge(self, u, v, w=1):
        if u > self.n or v > self.n:
            raise Exception("Graph.addEdge given vertex larger than size")

        edge = (v, w)
        self.vertices[u].append(edge)

        if not self.directed:
            edge_r = (u, w)
            self.vertices[v].append(edge_r)

    def remove_edge(self, u, v):
        self.vertices[u] = filter(lambda x: x[0] != v, self.get_vertices(u))

    def get_edge_weight(self, u, v):
        w_list = [w_ for (v_, w_) in self.get_vertices(u) if v_ == v]
        return w_list[0] if len(w_list) != 0 else -sys.sys.maxsize
