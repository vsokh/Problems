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

#include <algorithm>
class Solution {
public:
	int maxCoins(vector<int>& piles) {
		std::sort(piles.begin(), piles.end());
		int sum=0;
		for(int i=piles.size()/3; i<piles.size(); i+=2)
			sum+=piles[i];
		return sum;
    }
};

int main()
{
	setIO();
	Solution s;
	/* vector<int> v = {2,4,1,2,7,8}; */
	/* vector<int> v = {2,4,5}; */
	vector<int> v = {9,8,7,6,5,1,2,3,4};
	cout << s.maxCoins(v) << endl;
	return 0;
}
