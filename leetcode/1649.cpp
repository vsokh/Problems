#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
#define nl "\n"

#define ull unsigned long long
#define ll long long

#define ff first
#define ss second
#define mp make_pair
#define pb push_back

#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl

#define vl vector<ll>
#define sl set<ll>
#define pl pair<ll, ll>

class Solution {
public:
    int createSortedArray(vector<int>& instructions) {
		int const mod = 1e9+7;
		int c = 0;
		multiset<int> s;
		for (int i : instructions) {
			auto L = distance(s.begin(), s.lower_bound(i));
			auto G = distance(s.upper_bound(i), s.end());
			/* cout << i << ": (" << L << ", " << G << ") -> " << min(L,G) << nl; */
			c = c%mod + min(L, G)%mod;
			s.insert(i);
		}
		return c;
    }
};

int main()
{
	/* set<int> s; */
	/* s.insert(1); */
	/* s.insert(5); */
	/* s.insert(6); */
	/* s.insert(2); */

	/* auto L = distance(s.begin(), s.lower_bound(6)); */
	/* auto G = distance(s.upper_bound(6), s.end()); */
	/* cout << L << nl; */
	/* cout << G << nl; */
	Solution s;
	/* vector<int> v{1,5,6,2}; */
	/* vector<int> v{1,2,3,6,5,4}; */
	/* vector<int> v{1,3,3,3,2,4,2,1,2}; */
	/* vector<int> v{1,3,2,(int)1e5, 6}; */
	cout << s.createSortedArray(v) << nl;
	return 0;
}
