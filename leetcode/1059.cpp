#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()

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

#define vi vector<int>
#define vvi vector<vector<int>>
#define pb push_back
#define nl "\n"

class Solution {
	public:
		void printAdj(vvi const& adj) {
			for (int u = 0; u < adj.size(); ++u) {
				cout << u << ": ";
				for (int v : adj[u])
					cout << v << " ";
				cout << endl;
			}
		}

		vvi toAdj(int n, vvi& edges) {
			vvi adj(n);
			for (auto uv : edges)
				adj[uv[0]].pb(uv[1]);
			return adj;
		}

		void dfs(int u,
				 int D,
				 bool& result,
				 vvi& adj,
				 vi&  visited,
				 vi&  outdegree,
				 vi&  onStack)
		{
			onStack[u]=visited[u]=true;
			for (int v : adj[u]) {
				++outdegree[u];
				if (!visited[v]) {
					dfs(v, D, result, adj, visited, outdegree, onStack);
					if (!result)
						return;
				}
				else if (onStack[v]) {
					result = false;
					return;
				}
			}
			onStack[u]=false;

			result &= u == D ? outdegree[u] == 0 : outdegree[u] != 0;
		}

		bool leadsToDestination(int n, vvi& edges, int source, int destination) {
			vi onStack(n), outdegree(n), visited(n);
			vvi adj = toAdj(n, edges);
			bool result = true;
			dfs(source, destination, result, adj, visited, outdegree, onStack);
			return result;
		}
};

int main() {
	Solution s;
	{
		int const n = 3;
		int const source = 0;
		int const destination = 2;
		vector<vector<int>> edges{{0,1},{0,2}};
		cout << s.leadsToDestination(n, edges, source, destination) << endl;
	}
	{
		int const n = 4;
		int const source = 0;
		int const destination = 3;
		vector<vector<int>> edges{{0,1},{0,3},{1,2},{2,1}};
		cout << s.leadsToDestination(n, edges, source, destination) << endl;
	}
	{
		int const n = 4;
		int const source = 0;
		int const destination = 3;
		vector<vector<int>> edges{{0,1},{0,2},{1,3},{2,3}};
		cout << s.leadsToDestination(n, edges, source, destination) << endl;
	}
	{
		int const n = 3;
		int const source = 0;
		int const destination = 2;
		vector<vector<int>> edges{{0,1},{1,1},{1,2}};
		cout << s.leadsToDestination(n, edges, source, destination) << endl;
	}
	{
		int const n = 2;
		int const source = 0;
		int const destination = 1;
		vector<vector<int>> edges{{0,1},{1,1}};
		cout << s.leadsToDestination(n, edges, source, destination) << endl;
	}
	{
		int const n = 1;
		int const source = 0;
		int const destination = 0;
		vector<vector<int>> edges{{0,0}};
		cout << s.leadsToDestination(n, edges, source, destination) << endl;
	}
	{
		int const n = 7;
		int const source = 0;
		int const destination = 5;
		vector<vector<int>> edges{{0,1},{0,2},{1,3},{2,4},{3,5},{4,5},{2,6}};
		cout << s.leadsToDestination(n, edges, source, destination) << endl;
	}
	return 0;
}
