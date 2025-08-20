#include "solutions_133.hpp"

#include <gtest/gtest.h>

#include <unordered_set>

// ---------- Helper to free graph ----------
void freeGraph(Node* node, std::unordered_set<Node*>& visited) {
    if (!node || visited.count(node)) return;
    visited.insert(node);
    for (auto neighbor : node->neighbors) {
        freeGraph(neighbor, visited);
    }
    delete node;
}

void freeGraph(Node* node) {
    std::unordered_set<Node*> visited;
    freeGraph(node, visited);
}

// ---------- Test Fixture ----------
class Solutions_133_Test : public testing::Test {
   protected:
    Solution solution;

    bool compare(Node* node, Node* cloned_node,
                 std::unordered_set<Node*>& visited) {
        if (!node || !cloned_node) return node == cloned_node;

        if (visited.count(node)) return true;  // already checked
        visited.insert(node);

        if (node == cloned_node) return false;  // must be a distinct copy
        if (node->val != cloned_node->val) return false;
        if (node->neighbors.size() != cloned_node->neighbors.size())
            return false;

        for (size_t i = 0; i < node->neighbors.size(); i++) {
            if (!compare(node->neighbors[i], cloned_node->neighbors[i],
                         visited)) {
                return false;
            }
        }
        return true;
    }

    bool isCloneCorrect(Node* node, Node* cloned_node) {
        std::unordered_set<Node*> visited;
        return compare(node, cloned_node, visited);
    }
};

// ---------- Helpers to build graphs ----------
Node* buildSingleNodeGraph() { return new Node(1); }

Node* buildTwoNodeGraph() {
    Node* a = new Node(1);
    Node* b = new Node(2);
    a->neighbors.push_back(b);
    b->neighbors.push_back(a);
    return a;
}

Node* buildSquareGraph() {
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);

    n1->neighbors = {n2, n4};
    n2->neighbors = {n1, n3};
    n3->neighbors = {n2, n4};
    n4->neighbors = {n1, n3};

    return n1;
}

// ---------- Tests ----------
TEST_F(Solutions_133_Test, SingleNode) {
    Node* node = buildSingleNodeGraph();
    Node* cloned = solution.cloneGraph(node);

    EXPECT_TRUE(isCloneCorrect(node, cloned));

    freeGraph(node);
    freeGraph(cloned);
}

TEST_F(Solutions_133_Test, TwoNodes) {
    Node* node = buildTwoNodeGraph();
    Node* cloned = solution.cloneGraph(node);

    EXPECT_TRUE(isCloneCorrect(node, cloned));

    freeGraph(node);
    freeGraph(cloned);
}

TEST_F(Solutions_133_Test, SquareGraph) {
    Node* node = buildSquareGraph();
    Node* cloned = solution.cloneGraph(node);

    EXPECT_TRUE(isCloneCorrect(node, cloned));

    freeGraph(node);
    freeGraph(cloned);
}

TEST_F(Solutions_133_Test, NullGraph) {
    Node* cloned = solution.cloneGraph(nullptr);
    EXPECT_EQ(cloned, nullptr);

    freeGraph(cloned);  // safe, does nothing
}
