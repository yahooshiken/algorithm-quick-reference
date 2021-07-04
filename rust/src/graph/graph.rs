use std::convert::TryInto;

type Vertex = (usize, isize);
type VertexList = Vec<Vertex>;

trait GraphTrait {
  fn new(n: usize, directed: bool) -> Self;
  fn get_n(&self) -> usize;
  fn get_vertices(&self, u: usize) -> &VertexList;
  fn get_edge_weight(&self, u: usize, v: usize) -> isize;
  fn is_directed(&self) -> bool;
  fn is_edge(&self, u: usize, v: usize) -> bool;
  fn add_edge(&mut self, u: usize, v: usize, w: isize);
  fn remove_edge(&mut self, u: usize, v: usize) -> bool;
}

pub struct Graph {
  n: usize,
  directed: bool,
  vertices: Vec<VertexList>,
}

impl GraphTrait for Graph {
  fn new(n: usize, directed: bool) -> Self {
    Graph {
      n: n,
      directed: directed,
      vertices: vec![vec![]; n.try_into().unwrap()],
    }
  }

  fn get_n(&self) -> usize {
    return self.n;
  }

  fn get_vertices(&self, u: usize) -> &VertexList {
    return &self.vertices[u];
  }

  fn get_edge_weight(&self, u: usize, v: usize) -> isize {
    match self.get_vertices(u).into_iter().find(|&p| p.0 == v) {
      Some(vertex) => return vertex.1,
      None => return std::isize::MIN,
    }
  }

  fn is_directed(&self) -> bool {
    return self.directed;
  }

  fn is_edge(&self, u: usize, v: usize) -> bool {
    match self.get_vertices(u).into_iter().find(|&p| p.0 == v) {
      Some(_) => return true,
      None => return false,
    }
  }

  fn add_edge(&mut self, u: usize, v: usize, w: isize) {
    if u > self.n || v > self.n {
      panic!("Graph.addEdge given vertex larger than graph size");
    }

    let mut edge: VertexList = vec![(v, w)];
    self.vertices[u].append(&mut edge);

    if !self.is_directed() {
      let mut edge_r: VertexList = vec![(u, w)];
      self.vertices[v].append(&mut edge_r);
    }
  }

  fn remove_edge(&mut self, u: usize, v: usize) -> bool {
    match self.get_vertices(u).into_iter().position(|&p| p.0 == v) {
      Some(v_index) => {
        self.vertices[u].remove(v_index);
        if !self.directed {
          match self.get_vertices(v).into_iter().position(|&p| p.0 == u) {
            Some(u_index) => {
              self.vertices[v].remove(u_index);
            }
            None => (),
          }
        }
        true
      }
      None => false,
    }
  }
}

#[cfg(test)]
mod tests {
  use super::*;
  #[test]
  fn test_graph() {
    const N: usize = 5;
    const DIRECTED: bool = false;
    let mut g = Graph::new(N, DIRECTED);

    assert_eq!(g.n, N);
    assert_eq!(g.directed, DIRECTED);

    g.add_edge(0, 1, 1);
    g.add_edge(1, 2, 1);
    g.add_edge(1, 3, 1);
    g.add_edge(1, 4, 1);
    g.add_edge(2, 3, 1);
    g.add_edge(4, 2, 1);

    assert_eq!(g.is_edge(0, 1), true);
    assert_eq!(g.is_edge(0, 2), false);
    assert_eq!(g.get_edge_weight(0, 1), 1);

    g.remove_edge(0, 1);
    assert_eq!(g.is_edge(0, 1), false);
  }
}
