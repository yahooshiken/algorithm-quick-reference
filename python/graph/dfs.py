from enum import Enum
from .graph import Graph


class Color(Enum):
    White = "White"
    Gray = "Gray"
    Black = "Black"


def dfs_visit(graph: Graph, u: int, pred: list[int], colors: list[Color]):
    colors[u] = Color.Gray

    for (v, w) in sorted(graph.get_vertices(u), key=lambda tup: tup[0]):
        if colors[v] == Color.White:
            print(u, v)
            pred[v] = u
            dfs_visit(graph, v, pred, colors)

    colors[u] = Color.Black


def dfs_search(graph: Graph, start: int) -> list[int]:
    n: int = graph.get_vertices_num()
    pred: list[int] = [-1 for _ in range(n)]
    colors: list[Color] = [Color.White for _ in range(n)]

    dfs_visit(graph, start, pred, colors)
    print(pred)

    for u in range(n):
        if colors[u] == Color.White:
            dfs_visit(graph, u, pred, colors)

    return pred
