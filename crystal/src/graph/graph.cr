alias Vertex = Tuple(Int64, Int64)
alias VertexList = Array(Vertex)
INT64_MIN = -9223372036854775808_i64

class Graph
  def initialize(n : Int64, directed : Bool = false)
    @n = n
    @directed = directed
    @vertices = Array(VertexList).new(n) { [] of Vertex }
  end

  def n : Int64
    @n
  end

  def directed : Bool
    @directed
  end

  def get_vertices(u : Int64) : VertexList
    @vertices[u]
  end

  def get_edge_weight(u : Int64, v : Int64) : Int64
    vertex = @vertices[u].find({0, INT64_MIN}) { |vertex| vertex[0] == v }
    vertex[1]
  end

  def is_edge(u : Int64, v : Int64) : Bool
    u > @n || v > @n ? false : @vertices[u].any? { |vertex| vertex[0] == v }
  end

  def add_edge(u : Int64, v : Int64, w : Int64 = 1)
    raise Exception.new("Graph.addEdge given vertex larger than graph size") if u > @n || v > @n

    edge : Vertex = {v, w}
    @vertices[u] << edge

    if !@directed
      edge_r : Vertex = {u, w}
      @vertices[v] << (edge_r)
    end
  end

  def remove_edge(u : Int64, v : Int64)
    @vertices[u].reject! { |x| x[0] == v }
  end
end
