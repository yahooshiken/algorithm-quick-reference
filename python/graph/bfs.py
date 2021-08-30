import sys
from enum import Enum
from queue import Queue
from .graph import Graph


class Color(Enum):
    White = "White"
    Gray = "Gray"
    Black = "Black"


def bfs_search(graph: Graph, start: int) -> list[int]:
    n: int = graph.get_vertices_num()
    pred: list[int] = [-1 for _ in range(n)]
    dist: list[int] = [sys.maxsize for _ in range(n)]
    colors: list[Color] = [Color.White for _ in range(n)]

    dist[start] = 0
    colors[start] = Color.Gray

    q: Queue = Queue()
    q.put(start)

    while not q.empty():
        u: int = q.get()
        for (v, w) in graph.get_vertices(u):
            if colors[v] == Color.White:
                dist[v] = dist[u] + 1
                pred[v] = u
                colors[v] = Color.Gray
                q.put(v)

        q.get()
        colors[u] = Color.Black

    return pred
