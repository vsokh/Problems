#include <vector>
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    void inorder(vector<TreeNode*>& vec, TreeNode* root)
    {
        if (!root) return;

        inorder(vec, root->left);
        vec.push_back(root);
        inorder(vec, root->right);
    }

    vector<int> findTwoSwapped(vector<TreeNode*>& vec) {
        int a = -1, b = -1;
        int p = 0, c = 1;
        for (;c < vec.size(); ++c, ++p) {
            if (vec[p]->val > vec[c]->val) {
                if (a==-1)
                    a = p;
                b = c;
            }
        }
        return {a, b};
    }

    void recoverTree(TreeNode* root) {
        vector<TreeNode*> vec;
        inorder(vec, root);
        vector<int> swapped = findTwoSwapped(vec);
        int a = swapped[0], b = swapped[1];
        swap(vec[a]->val, vec[b]->val);
    }
};

int main()
{
	/* { */
	/* TreeNode n1(1); TreeNode n3(3); TreeNode n4(4); TreeNode n2(2); */
	/* n3.left = &n1; n4.left = &n2; n3.right = &n4; */
	/* Solution s; s.recoverTree(&n3); s.printTree(&n3); */
	/* } */
	/* { */
	/* TreeNode n1(1); TreeNode n3(3); TreeNode n2(2); */
	/* n3.right = &n2; n1.left = &n3; */
	/* Solution s; s.recoverTree(&n1); s.printTree(&n1); */
	/* } */
	/* { */
	TreeNode n1(1); TreeNode n2(2); TreeNode n3(3);
	n1.left = &n2; n1.right = &n3;
	Solution s; s.recoverTree(&n1);
	/* } */
	/* vector<int> v{1,2,6,4,5,3}; */
	/* pair<int, int> p = find_two_swapped(v); */
	/* cout << "f: " << p.first << " s: " << p.second << endl; */
	return 0;
}
