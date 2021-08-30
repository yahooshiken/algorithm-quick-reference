from .graph import Graph
from .bfs import bfs_search


def test_bfs():
    n: int = 6
    g: Graph = Graph(n, True)

    g.add_edge(0, 3)
    g.add_edge(0, 1)
    g.add_edge(1, 4)
    g.add_edge(2, 5)
    g.add_edge(2, 4)
    g.add_edge(3, 1)
    g.add_edge(4, 3)
    g.add_edge(5, 5)

    pred = bfs_search(g, 0)
    expected = [-1, 0, -1, 0, 1, -1]

    assert pred == expected
