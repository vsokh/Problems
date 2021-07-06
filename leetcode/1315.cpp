
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
//
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
    void sumEven(TreeNode *n, int &sum, bool pred, bool gpred=false) {
		if (n==nullptr) return;
		if (gpred) sum+=n->val;
		sumEven(n->left, sum, n->val%2==0, pred);
		sumEven(n->right, sum, n->val%2==0, pred);
    }
    int sumEvenGrandparent(TreeNode* root) {
        int sum=0;
		sumEven(root->left, sum, root->val%2==0);
		sumEven(root->right, sum, root->val%2==0);
		return sum;
    }
};

int main()
{
	setIO();
	return 0;
}
