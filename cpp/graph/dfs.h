#ifndef _DFS_H_
#define _DFS_H_

#include <sstream>

#include "graph.h"

class EdgeLabel {
public:
  // Constructor
  EdgeLabel(int src, int target, edgeType type)
      : src_(src), target_(target), type_(type){};
  // Getter
  int getSrc() { return src_; }
  int getTarget() { return target_; }
  edgeType getType() { return type_; }

  // String representation of edge type.
  string toString() {
    ostringstream oss;
    oss << "(" << src_ << "," << target_ << ") [";

    if (type_ == Tree) {
      oss << "Tree";
    } else if (type_ == Backward) {
      oss << "Back";
    } else if (type_ == Forward) {
      oss << "Forward";
    } else if (type_ == Cross) {
      oss << "Cross";
    }

    oss << "]";

    return oss.str();
  }

private:
  int src_;
  int target_;
  edgeType type_;
};

void dfsSearch(Graph const &graph, int s, vector<int> &pred);

#endif /* _DFS_H_ */