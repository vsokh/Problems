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
	bool isCycle(int u, vector<vector<int>> &adj, vector<char> &visited, vector<char> &stack) {
		if (visited[u]) return false;

		visited[u] = stack[u] = 1;
		for (int v : adj[u]) {
			if (!visited[v] && isCycle(v, adj, visited, stack))
				return true;
			else if (stack[v])
				return true;
		}
		stack[u]=0;
		return false;
	}

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		vector<vector<int>> adj(numCourses);
		for (auto p:prerequisites){
			int u=p[1], v=p[0];
			adj[u].push_back(v);
		}
		vector<char> visited(numCourses), stack(numCourses);
		for (int u=0;u<numCourses;++u) {
			if (isCycle(u, adj, visited, stack))
				return false;
		}
		return true;
	}
};

int main()
{
	setIO();
	return 0;
}
