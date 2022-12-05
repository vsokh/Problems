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
    int height(TreeNode* root) {
        if (!root) {
            return 0;
        }
        return 1 + height(root->left);
    }

    int nullsOnTheLastLevel(TreeNode *root, int currHeight, int height) {
        if (!root) {
            return 0;
        }

        if (currHeight == height) {
            return !root->left + !root->right;
        }

        return nullsOnTheLastLevel(root->left, currHeight + 1, height);
    }

    int countNodes(TreeNode* root) {
        // O(h)
        int h = height(root);
        int cnt = 0;
        // O(h)
        for (auto i = 0; i < h; ++i) {
            cnt += pow(2, i);
        }
        return cnt - nullsOnTheLastLevel(root->left, 1, h-2) - nullsOnTheLastLevel(root->right, 1, h-2);
    }
};
