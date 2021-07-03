package graph

import (
	"errors"
	"math"
)

type Vertex struct {
	v      int
	weight int
}

type VertexList = []Vertex

type Graph struct {
	n        int
	directed bool
	vertices []VertexList
}

func NewGraph(n int, directed bool) Graph {
	var vertices = make([]VertexList, n)
	return Graph{n: n, directed: directed, vertices: vertices}
}

func (g *Graph) getVertices(u int) VertexList {
	return g.vertices[u]
}

func find(vertices VertexList, v int) (*Vertex, *int) {
	for i, vertex := range vertices {
		if vertex.v == v {
			return &vertex, &i
		}
	}

	return nil, nil
}

func (g *Graph) getEdgeWeight(u int, v int) int {
	vertex, _ := find(g.getVertices(u), v)
	if vertex != nil {
		return vertex.weight
	}

	return math.MinInt32
}

func some(vertices VertexList, v int) bool {
	for _, vertex := range vertices {
		if vertex.v == v {
			return true
		}
	}

	return false
}

func (g *Graph) isEdge(u int, v int) bool {
	if u > g.n || v > g.n {
		return false
	}

	return some(g.getVertices(u), v)
}

func (g *Graph) addEdge(u int, v int, w int) error {
	if u > g.n || v > g.n {
		return errors.New("Graph.addEdge given vertex larger than graph size")
	}

	edge := Vertex{v: v, weight: w}
	g.vertices[u] = append(g.getVertices(u), edge)

	if !g.directed {
		edgeR := Vertex{v: u, weight: w}
		g.vertices[v] = append(g.getVertices(v), edgeR)
	}

	return nil
}

func remove(vertex VertexList, i int) *VertexList {
	vertex = append(vertex[:i], vertex[i+1:]...)

	return &vertex
}

func (g *Graph) removeEdge(u int, v int) (bool, error) {
	vertex, index := find(g.getVertices(u), v)
	if vertex == nil {
		return false, errors.New("not found")
	}

	g.vertices[u] = *remove(g.getVertices(u), *index)

	return true, nil
}
