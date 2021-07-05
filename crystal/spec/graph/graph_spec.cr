require "../spec_helper"
require "../../src/graph/graph.cr"

describe Algorithm do
  it "graph" do
    n : Int64 = 5
    directed : Bool = false
    g = Graph.new(n, directed)
    g.n.should eq(n)
    g.directed.should eq(directed)

    g.add_edge(0, 1)
    g.add_edge(1, 2)
    g.add_edge(1, 3)
    g.add_edge(1, 4)
    g.add_edge(2, 3)
    g.add_edge(4, 2)

    g.is_edge(0, 1).should be_true
    g.is_edge(0, 2).should be_false
    g.get_edge_weight(0, 1).should eq(1)

    g.remove_edge(0, 1)
    g.is_edge(0, 1).should be_false
  end
end
