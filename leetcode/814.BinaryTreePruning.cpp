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
    bool find1(TreeNode* node)
    {
        if (!node) return false;

        // dive
        auto left = find1(node->left);
        auto right = find1(node->right);

        // prune
        if (!left) node->left = nullptr;
        if (!right) node->right = nullptr;

        // check
        return left || right || node->val == 1;
    }

    TreeNode* pruneTree(TreeNode* root) {
        if (!root)
            return nullptr;

        if (!find1(root) && root->val != 1)
            return nullptr;

        return root;
    }
};

int main() {
    return 0;
}
