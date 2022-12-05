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
    void inorderTraversal(vector<int>& v, TreeNode* node)
    {
        if (!node) return;

        inorderTraversal(v, node->left);
        v.push_back(node->val);
        inorderTraversal(v, node->right);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        inorderTraversal(result, root);
        return result;
    }
};

int main()
{
    return 0;
}
