import sys


class Graph:
    def __init__(self, n: int, directed: bool = False) -> None:
        self.n: int = n
        self.directed: bool = directed
        self.vertices: list[list[(int, int)]] = [[] for i in range(n)]

    def get_vertices_num(self) -> int:
        return self.n

    def get_vertices(self, u: int) -> list[(int, int)]:
        return self.vertices[u]

    def is_directed(self) -> bool:
        return self.directed

    def is_edge(self, u: int, v: int) -> bool:
        if u > self.n or v > self.n:
            return False

        return any(v_ == v for (v_, w_) in self.get_vertices(u))

    def add_edge(self, u: int, v: int, w: int = 1) -> None:
        if u > self.n or v > self.n:
            raise Exception("Graph.addEdge given vertex larger than size")

        edge = (v, w)
        self.vertices[u].append(edge)

        if not self.directed:
            edge_r = (u, w)
            self.vertices[v].append(edge_r)

    def remove_edge(self, u: int, v: int) -> None:
        self.vertices[u] = filter(lambda x: x[0] != v, self.get_vertices(u))

    def get_edge_weight(self, u: int, v: int) -> int:
        w_list = [w_ for (v_, w_) in self.get_vertices(u) if v_ == v]
        return w_list[0] if len(w_list) != 0 else -sys.sys.maxsize
