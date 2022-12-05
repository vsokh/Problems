#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*> q; q.push_back(root);
        while (!q.empty()) {
            auto n = q.front(); q.pop();
            std::cout << n << endl;
            for (auto e : n->children) {
                q.push(e);
            }
        }
        return {};
    }
};

int main() {
    return 0;
}
