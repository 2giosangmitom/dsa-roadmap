#include <unordered_map>
#include <vector>
using namespace std;

// Definition for a Node.
class Node {
   public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
   private:
    Node* dfs(Node* node, unordered_map<Node*, Node*>& clone_map) {
        if (clone_map.contains(node)) {
            return clone_map[node];
        }
        Node* cloned_node = new Node(node->val);
        clone_map[node] = cloned_node;

        for (auto neighbor : node->neighbors) {
            Node* cloned_neighbor = dfs(neighbor, clone_map);
            cloned_node->neighbors.push_back(cloned_neighbor);
        }

        return cloned_node;
    }

   public:
    Node* cloneGraph(Node* node) {
        if (!node) {
            return node;
        }
        unordered_map<Node*, Node*> clone_map;
        return dfs(node, clone_map);
    }
};
