
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
	using ADJ = vector<vector<pair<int,int>>>;
	void dijkstra(int n, ADJ adj, vector<int>& D, int src) {
		auto cmp = [](pair<int,int> u, pair<int,int> v){
			return u.second - v.second;
		};
		priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> Q(cmp);
		Q.push({src, 0});
		while (!Q.empty()){
			auto p = Q.top(); Q.pop();
			int u = p.first, w = p.second;
			if (w > D[u]) continue;
			for (auto e:adj[u]) {
				int v = e.first, uv = e.second;
				if (D[v] > w + uv){
					D[v] = w + uv;
					Q.push({v, D[v]});
				}
			}
		}
	}

	void bellman_ford() {
	}

	int findTheCity(int n, vector<vector<int>>&& edges, int distanceThreshold) {
		vector<vector<int>> D(n);

		int inf = (int)1e9;
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < n; ++j) {
				D[i].push_back(inf);
			}
		}

		ADJ adj(n);
		for(auto e:edges) {
			int u=e[0], v=e[1], uv=e[2];
			adj[u].push_back({v,uv});
			adj[v].push_back({u,uv});
		}

		for(int i=0;i<n;++i)
			dijkstra(n, adj, D[i], i);

		int c=-1,m=n;
		for(int i=0;i<n;++i){
			int cm=0;
			for(int j=0;j<n;++j){
				if(i==j)continue;
				if(D[i][j]<=distanceThreshold)++cm;
			}
			if(cm<=m){ m=cm; c=i; }
		}
		return c;
	}
};

int main()
{
	setIO();
	Solution s;
	/* cout << s.findTheCity(4, {{0,1,3},{1,2,1},{1,3,4},{2,3,1}}, 4) << nl; */
	/* cout << s.findTheCity(5, {{0,1,2},{0,4,8},{1,2,3},{1,4,2},{2,3,1},{3,4,1}}, 2) << nl; */
	return 0;
}
