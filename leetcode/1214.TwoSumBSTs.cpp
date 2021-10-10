
#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
#define nl "\n"

#define ull unsigned long long
#define ll long long

#define f first
#define s second
#define mp make_pair
#define pb push_back

#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl

#define vl vector<ll>
#define sl set<ll>
#define pl pair<ll, ll>

void setIO(string name = "")
{
	cin.tie(0)->sync_with_stdio(0);
	if (name.size()) {
		freopen((name+".in").c_str(), "r", stdin);
		freopen((name+".out").c_str(), "w", stdout);
	}
}
 //Definition for a binary tree node.
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
    void bstToVec(TreeNode* root, vector<int> &vec) {
		// in-order
		if (root == nullptr)
			return;

		bstToVec(root->left, vec);
		vec.push_back(root);
		bstToVec(root->right, vec);
    }
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        vector<int> v1; bstToVec(root1, v1);
        vector<int> v2; bstToVec(root2, v2);
        for (int i : v1) {
            for (int j : v2) {
                if (i + j == target)
                    return true;
            }
        }
        return false;
    }
};

int main()
{
	setIO();
	/* TreeNode*2,1,4] */
	/* [1,0,3] */
	/* 5 */
	return 0;
}
