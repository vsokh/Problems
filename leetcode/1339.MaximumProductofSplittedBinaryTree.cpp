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

const unsigned int M = 1000000007;
class Solution {
public:
    long long treeSum(TreeNode* n) {
        if (!n) {
            return 0;
        }

        return n->val + treeSum(n->left) + treeSum(n->right);
    }

    long long maxProduct(TreeNode* n, long long maxSum, long long& product) {
        if (!n) {
            return 0;
        }

        long long currSum = maxProduct(n->left, maxSum, product) + maxProduct(n->right, maxSum, product) + n->val;
        product = max(product, (maxSum-currSum)*currSum);
        return currSum;
    }

    int maxProduct(TreeNode* root)
    {
        long long maxSum = treeSum(root);
        long long product = 0;

        maxProduct(root, maxSum, product);
        return product % M;
    }
};

int main()
{
    return 0;
}
