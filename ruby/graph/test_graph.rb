require 'test/unit'
require_relative 'graph'

class GraphTest < Test::Unit::TestCase
  def setup
    @n = 5
    @directed = false
    @g = Graph.new(@n, directed: @directed)
  end

  def test_graph
    assert_equal(@n, @g.num)
    assert_equal(@directed, @g.directed)

    @g.add_edge(0, 1)
    @g.add_edge(1, 2)
    @g.add_edge(1, 3)
    @g.add_edge(1, 4)
    @g.add_edge(2, 3)
    @g.add_edge(4, 2)

    assert_true(@g.is_edge(0, 1))
    assert_false(@g.is_edge(0, 2))

    @g.remove_edge(0, 1)
    assert_false(@g.is_edge(0, 1))
  end
end
