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
    bool isLeaf(TreeNod* n) {
        return n && !n->left && !n->right;
    }

    int maxSumSubArray(TreeNode *n, long long& maxSum) {
        if (!n) {
            return INT_MIN;
        }

        if (isLeaf(n)) {
            return n->val;
        }

        long long currSum = max(maxSumSubArray(n->left, maxSum), maxSumSubArray(n->right, maxSum));

        currSum = max(n->val, currSum + n->val);
        maxSum = max(currSum, maxSum);

        return currSum;
    }

    int maxPathSum(TreeNode* root) {
        long long maxSum = INT_MIN;
        long long currSum = INT_MIN;
        maxSumSubArray(root, maxSum, currSum);
        return maxSum;
    }
};

