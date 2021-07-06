
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
    int openLock(vector<string>& v, string target) {
		/* 1 step from 0000 is either of: {1000 0100 0010 0001 9000 0900 0090 0009} */
		/* 1 step from 0001 is either of: {0000 1001 0101 0011 9001 0901 0091 0002} */
		/* 1 step from 0010 is either of: {0000 1001 0101 0011 9010 0910 0019 0020} */
		/* ... */
		/* graph size 8*9999 */

		const int states = 5, moves = 4;
		vector<vector<int>> adj(states);
		for (int u=0;u<states;++u){
			sprintf(adj[u],"%d%d%d%d",);
		}
		for (int i =0; i<states; ++i) {
			cout << i<<"| ";
			for (int j = 0; j<moves+moves; ++j)
				cout << " " << adj[i][j];
			cout << nl;
		}
		// construct graph
		// use dijkstra to find a path
		return -1;
    }
};
int main()
{
	Solution s;
	vector<string> v;
	s.openLock(v, "");
	return 0;
}
