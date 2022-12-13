#include <vector>
#include <iostream>

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

class Solution
{
public:
    int maxDiif(TreeNode* n, int mx, int mn)
    {
        if (!n) return abs(mx - mn);

        mx = max(n->val, mx);
        mn = min(n->val, mn);

        return max(maxDiif(n->left, mx, mn), maxDiif(n->right, mx, mn));
    }

    int maxAncestorDiff(TreeNode* root)
    {
        if (!root) {
            return 0;
        }

        return maxDiff(root, root->val, root->val);
    }
};

int main()
{
    return 0;
}
