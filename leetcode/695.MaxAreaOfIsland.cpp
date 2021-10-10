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
	void countArea(vector<vector<int>> &G, vector<vector<int>> &grid, int i, int j, int &area) {
		if(i<0||i>=grid.size())return;
		if(j<0||j>=grid[i].size())return;
		if(!grid[i][j])return;
		if(G[i][j])return;

		++area;
		G[i][j]=1;
		countArea(G, grid, i, j-1, area);
		countArea(G, grid, i, j+1, area);
		countArea(G, grid, i-1, j, area);
		countArea(G, grid, i+1, j, area);
	}
    int areaOfIsland(vector<vector<int>>& grid) {
		int maxArea=0;
		vector<vector<int>> G;
		for(int i=0;i<grid.size();++i)
			for(int j=0;j<grid[i].size();++j)
				G[i][j]=0;
		for(int i=0;i<grid.size();++i){
			for(int j=0;j<grid[i].size();++j){
				int currArea=0;
				countArea(G, grid, i, j, currArea);
				maxArea=max(maxArea, currArea);
			}
		}
		return maxArea;
    }
};


int main()
{
	return 0;
}
