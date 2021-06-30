from .graph import Graph
from .dfs import dfs_search


def test_dfs():
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

    pred = dfs_search(g, 0)
    expected = [-1, 0, -1, 4, 1, 2]

    assert pred == expected
