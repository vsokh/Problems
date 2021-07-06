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
		void fillInorder(TreeNode* root, vector<TreeNode*>& in_order) {
			if (root == nullptr) return;

			fillInorder(root->left, in_order);
			in_order.push_back(root);
			fillInorder(root->right, in_order);
		}

		pair<int, int> find_two_swapped(vector<TreeNode*> &nums) {
			int n = nums.size();
			int x,y; x = y = -1;
			for (int i = 0; i < n-1; ++i) {
				if (nums[i+1]->val < nums[i]->val) {
					y = i+1;
					if (x == -1)
						x = i;
					else
						break;
				}
			}
			return {x, y};
		}

		void recoverTree(TreeNode* root) {
			stack<TreeNode*> stk;
			TreeNode *x = nullptr, *y = nullptr, *pred = nullptr;

			while (!stk.empty() || root != nullptr) {
				while (root != nullptr) {
					stk.push(root);
					root = root->left;
				}
				root = stk.top(); stk.pop();
				if (pred != nullptr && root->val < pred->val) {
					y = root;
					if (x == nullptr)
						x = pred;
					else
						break;
				}
				pred = root;
				root = root->right;
			}
			swap(x->val, y->val);
		}

		/* void recoverTree(TreeNode* root) { */
		/* 	vector<TreeNode*> in_order; */
		/* 	fillInorder(root, in_order); */

		/* 	auto p = find_two_swapped(); */
		/* 	swap(in_order[p.fisrt]->val, in_order[p.second]->val); */
		/* } */

		void printTree(TreeNode *root) {
			if (root == nullptr) return ;

			printTree(root->left);
			cout << root->val << " ";
			printTree(root->right);
		}
};

pair<int, int> find_two_swapped(vector<int> &nums) {
	int n = nums.size();
	int x,y; x = y = -1;
	for (int i = 0; i < n-1; ++i) {
		if (nums[i+1] < nums[i]) {
			y = i+1;
			if (x == -1)
				x = i;
			else
				break;
		}
	}
	return {x, y};
}

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
	s.printTree(&n1);
	/* } */
	/* vector<int> v{1,2,6,4,5,3}; */
	/* pair<int, int> p = find_two_swapped(v); */
	/* cout << "f: " << p.first << " s: " << p.second << endl; */
	return 0;
}
