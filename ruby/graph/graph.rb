class Graph
  def initialize(num, directed: false)
    @num = num
    @vertices = Array.new(num) { [] }
    @directed = directed || false
  end

  attr_reader :num, :directed

  def is_edge(u, v)
    return false if u > @num || v > @num

    @vertices[u].any? { |vertex| vertex[0] == v }
  end

  def get_edge_weight(u, v)
    weight = @vertices[u].find { |vertex| vertex[0] == v }
    return weight if weight.present?

    -(2**(0.size * 8 - 2))
  end

  def add_edge(u, v, w = 1)
    raise Exception, 'This is an exception' if u > @num || v > @num

    edge = [v, w]
    @vertices[u].append(edge)

    if @directed
      edge_r = [u, w]
      @vertices[u].append(edge_r)
    end
  end

  def remove_edge(u, v)
    @vertices[u].delete_if { |x| x[0] == v }
  end
end
