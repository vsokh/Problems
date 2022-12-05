#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    void count(TreeNode* node, int cnt, int max) {
        if (!node) return;
        if (node->val >= max) {
            ++cnt; max = node->val;
        }
        count(node->left, cnt, max);
        count(node->right, cnt, max);
    }

    int goodNodes(TreeNode* root) {
        int cnt=0;
        int max=INT_MIN;
        count(root, cnt, max);
        return cnt;
    }
};

int main() {
    return 0;
}
