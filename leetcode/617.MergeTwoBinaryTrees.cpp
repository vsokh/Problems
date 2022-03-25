
#include <__nullptr>
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {

    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void dfs(TreeNode* n) {
        if (!n)
            return;

        dfs(n->left);
        cout << n->val << " ";
        dfs(n->right);
    }

    void dfs(TreeNode* n1, TreeNode* n2) {
        if (!n1 || !n2)
            return;

        if (n1 && n2)
            n1->val += n2->val;

        if (!n1->left)
            n1->left = n2->left;
        else
            dfs(n1->left, n2->left);

        if (!n1->right)
            n1->right = n2->right;
        else
            dfs(n1->right, n2->right);
    }

    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        dfs(root1, root2);
        return root1;
    }
};

int main()
{
    auto* n5 = new TreeNode(5);
    auto* n3 = new TreeNode(3, n5, nullptr);
    auto* n2 = new TreeNode(2);
    auto* r1 = new TreeNode(1, n3, n2);

    auto* n4 = new TreeNode(4);
    auto* n1 = new TreeNode(1, nullptr, n4);
    auto* n7 = new TreeNode(7);
    auto* nn3 = new TreeNode(3, nullptr, n7);
    auto* r2 = new TreeNode(2, n1, nn3);

    Solution s;
    s.mergeTrees(r1, r2);

    return 0;
}
