#include <map>
#include <vector>

class Node {
public:
  int val;
  std::vector<Node *> neighbors;

  Node() {
    val = 0;
    neighbors = std::vector<Node *>();
  }

  Node(int _val) {
    val = _val;
    neighbors = std::vector<Node *>();
  }

  Node(int _val, std::vector<Node *> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }
};

class Solution {
  void dfs(const Node *node, Node *copy, std::map<int, Node *> &visited) {
    visited[node->val] = copy;
    for (auto n : node->neighbors) {
      if (visited.count(n->val) == 0) {
        Node *newnode = new Node(n->val);
        copy->neighbors.push_back(newnode);
        dfs(n, newnode, visited);
        continue;
      }

      copy->neighbors.push_back(visited[n->val]);
    }
  }

public:
  Node *cloneGraph(Node *node) {
    if (node == nullptr)
      return node;


    Node *copy = new Node(node->val);

    std::map<int, Node *> visited;
    visited[node->val] = copy;

    for (auto n : node->neighbors) {
      if (visited.count(n->val) == 0) {
        Node *newnode = new Node(n->val);
        copy->neighbors.push_back(newnode);
        dfs(n, newnode, visited);
        continue;
      }

      copy->neighbors.push_back(visited[n->val]);
    }

    return copy;
  }
};
