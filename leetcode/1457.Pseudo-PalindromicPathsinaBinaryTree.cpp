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
    void tree2arrays(TreeNode* node, vector<vector<int>>& arrs) {
        if (!node) return;

        cout << node->val << " ";
        tree2arrays(node->left, arrs);
        cout << "\n";
        tree2arrays(node->right, arrs);
    }

    bool isPseudoPalindrom(const vector<vector<int>& arrs) {
    }

    int pseudoPalindromicPaths (TreeNode* root) {
        int cnt = 0;
        vector<vector<int>> arrs; tree2arrays(root, arrs);
        for (const auto& arr : arrs) {
            cnt += isPseudoPalindrom(arr);
        }
        return cnt;
    }
};

int main() {
    return 0;
}
