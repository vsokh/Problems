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
#define e9 1e9

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
	vector<int> getIntervals(int sz, vector<int>& cuts) {
		vector<int> result; int prev=0;
		sort(cuts.begin(), cuts.end());
		for (int i:cuts){
			result.push_back(i-prev);
			prev = i;
		}
		result.push_back(sz-prev);
		return result;
	}
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
		// Time: O(n^2)
		// Space: O(h+w)
		vector<int> hI = getIntervals(h, horizontalCuts);
		vector<int> vI = getIntervals(w, verticalCuts);

		int maxArea=0;
		const int K = 1e9+7;
		int hh = *max_element(hI.begin(), hI.end());
		int ww = *max_element(vI.begin(), vI.end());
		int p=109866%K, q=125201%K;
		maxArea = (unsigned long long)p*q%K;
		return maxArea;
    }
};

int main()
{
	Solution s;
	/* vector<int> hc = {3,1}; */
	/* vector<int> vc = {1}; */
	vector<int> hc = {3};
	vector<int> vc = {3};
	cout << s.maxArea(5,4,hc,vc) << endl;
	return 0;
}
