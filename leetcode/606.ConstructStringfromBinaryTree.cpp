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
    void toStr(string& str, TreeNode* node) {
        if (!node)
            return;

        str += "(";
        str += to_string(node->val);
        str += ")";
        toStr(str, node->left);
        toStr(str, node->left);
    }

    string tree2str(TreeNode* root) {
        string result;
        toStr(result, root);
        return result;
    }
};

int main() {
    Solution s;
    return 0;
}
