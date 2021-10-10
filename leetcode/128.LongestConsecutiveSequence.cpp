
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

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
		set<int> s;
		for (int n : nums)
			s.insert(n);

		// {100,4,200,1,3,2};
		// {1,2,3,4,100,200};
		for (int i = 0; i < v.size(); ++i) {
			int currSeq = 1;
			while (i < v.size() && v[i] == prev+1) {
				prev = v[i];
				++currSeq;
				++i;
			}
			prev = v[i];
			maxSeq = max(maxSeq, currSeq);
		}
		return maxSeq;
    }
    int longestConsecutive(vector<int>& nums) {
		// O(n)
		map<int, vector<int>> m;
		for (auto i : nums)
			m[i].push_back(i);

		vector<int> v;
		for (auto i : m)
			for (auto j : i.second)
				v.push_back(j);

		int maxSeq = 1, prev = v.empty() ? 0 : v[0];

		// {100,4,200,1,3,2};
		// {1,2,3,4,100,200};
		for (int i = 1; i < v.size(); ++i) {
			int currSeq = 1;
			while (i < v.size() && v[i] == prev+1) {
				prev = v[i];
				++currSeq;
				++i;
			}
			prev = v[i];
			maxSeq = max(maxSeq, currSeq);
		}
		return maxSeq;
    }
};

int main()
{
	Solution s;
	/* vector<int> v{100,4,200,1,3,2}; */
	vector<int> v{-1,3,7,2,5,8,4,6,0,1};
	cout << s.longestConsecutive(v) << endl;
	return 0;
}
