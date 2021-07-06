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
    int minCostClimbingStairs(vector<int>& cost) {
		int s = 1e9;
		int i = -1;
		int k = 2;
		int p = 0;
		int n = cost.size();
		int nextStep = 0;
		int minCostSum = 0;
		while (i < n) {
			p = i + 1;
			s = 1e9;
			for (int j = p + 1; j <= min(p + k, n - 1); ++j) {
				if (cost[p] + cost[j] <= s && j >= nextStep) {
					s = cost[p] + cost[j];
					nextStep = p;
				}
			}
			p = i + 2;
			for (int j = p + 1; j <= min(p + k, n - 1); ++j) {
				if (cost[p] + cost[j] <= s && j >= nextStep) {
					s = cost[p] + cost[j];
					nextStep = p;
				}
			}
			cout << endl;
			i = nextStep;
			minCostSum += cost[i];
			cout << i << endl;
			if (i == 8)
				break;
		}
		return minCostSum;
    }
};
int main()
{
	Solution s;
	vector<int> v = {1,100,1,1,1,100,1,1,100,1};
	cout << s.minCostClimbingStairs(v) << endl;
	return 0;
}
