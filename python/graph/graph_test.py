from .graph import Graph


def test_graph():
    n = 5
    directed = False
    g = Graph(n, directed)

    assert g.get_vertices_num() == n
    assert g.is_directed() == directed

    g.add_edge(0, 1)
    g.add_edge(1, 2)
    g.add_edge(1, 3)
    g.add_edge(1, 4)
    g.add_edge(2, 3)
    g.add_edge(4, 2)

    assert g.is_edge(0, 1)
    assert not g.is_edge(0, 2)
    assert g.get_edge_weight(0, 1) == 1

    g.remove_edge(0, 1)
    assert not g.is_edge(0, 1)
