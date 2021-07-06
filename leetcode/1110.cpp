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

#include <algorithm>
class Solution {
public:
	set<int> to_del;
	set<int> visited;
	vector<TreeNode*> result;
	template<typename F>
	void dfs(TreeNode* n, F f) {
		visited.insert(n->val);
		if (n->left && visited.find(n->left->val) == visited.end())
			dfs(n->left, f);
		if (n->right && visited.find(n->right->val) == visited.end())
			dfs(n->right, f);
		f(n);
	}
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
		for(auto t:to_delete) to_del.insert(t);
		dfs(root, [this](TreeNode *n){if(to_del.find(n->val)!=to_del.end())n->val=0;});
		visited.clear();
		dfs(root, [](TreeNode *n){cout << n->val << nl;});
		/* dfs(root, [this](TreeNode *n){ */
		/* 		cout << "entry: "<< n->val << nl; */
				/* if (n->left && n->left->val==0){ */
				/* 	cout << "L, f: "<< n->val << nl; */
				/* 	n->left=nullptr; */
				/* 	} */
				/* if (n->right && n->right->val==0){ */
				/* 	cout << "R, f: "<< n->val << nl; */
				/* 	n->right=nullptr; */
				/* 	} */
				/* if (n->val!=0) */
				/* 	result.push_back(n); */
				/* }); */
		return result;
	}
};

int main()
{
	setIO();
	TreeNode *root  = new TreeNode(1);
	TreeNode *left  = new TreeNode(2); left->left  = new TreeNode(4); left->right  = new TreeNode(5);
	TreeNode *right = new TreeNode(3); right->left = new TreeNode(6); right->right = new TreeNode(7);
	root->left = left;
	root->right = right;
	Solution s;
	vector<int> d = {3,5};
	vector<TreeNode*> v = s.delNodes(root, d);
	for(auto n:v) cout << n->val << " ";
	cout << nl;
	return 0;
}
