

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
	void deepness(TreeNode *n,int &maxdeep,int currdeep=0)  {
		if (n==nullptr) return;
		maxdeep = max(++currdeep, maxdeep);
		deepness(n->left, currdeep, maxdeep);
		deepness(n->right, currdeep, maxdeep);
	}
	int deepestLeavesSumAux(TreeNode *n,int maxdeep,int currdeep=0)  {
		if (n==nullptr) return 0;
		if (maxdeep == ++currdeep) return n->val;
		return deepestLeavesSumAux(n->left, maxdeep, currdeep) + deepestLeavesSumAux(n->right, maxdeep, currdeep);
	}
	int deepestLeavesSum(TreeNode *root) {
		if (root==nullptr) return 0;
		int maxdeep = 0;
		deepness(root->left, maxdeep);
		deepness(root->right, maxdeep);
		return deepestLeavesSumAux(root->left, maxdeep) + deepestLeavesSumAux(root->right, maxdeep);
	}
};

int main()
{
	setIO();
	return 0;
}
