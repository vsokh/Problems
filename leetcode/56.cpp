
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
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
		sort(intervals.begin(), intervals.end());

		vector<vector<int>> merged;
		for (auto interval : intervals) {
			if (merged.empty() || merged.back()[1] < interval[0])
				merged.push_back(interval);
			else
				merged.back()[1] = max(merged.back()[1], interval[1]);
		}
		return merged;
    }
};

int main()
{
	setIO();
	Solution s;
	vector<vector<int>> v = {{1,3},{8,10},{2,6},{15,18}};
	/* vector<vector<int>> v = {{1,2}}; */
	v = s. merge(v);
	cout << "[";
	for (auto i : v)
		cout << "[" << i[0] << "," << i[1] << "]";
	cout << "]\n";
	return 0;
}
