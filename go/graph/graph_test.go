package graph

import (
	"testing"

	"github.com/stretchr/testify/assert"
)

func TestGraph(t *testing.T) {
	var n = 5
	var directed = false
	g := NewGraph(n, directed)

	assert.Equal(t, n, g.n)
	assert.Equal(t, directed, g.directed)

	g.addEdge(0, 1, 1)
	g.addEdge(1, 2, 1)
	g.addEdge(1, 3, 1)
	g.addEdge(1, 4, 1)
	g.addEdge(2, 3, 1)
	g.addEdge(4, 2, 1)

	assert.True(t, g.isEdge(0, 1))
	assert.False(t, g.isEdge(0, 2))
	assert.Equal(t, 1, g.getEdgeWeight(0, 1))

	g.removeEdge(0, 1)
	assert.False(t, g.isEdge(0, 1))
}
