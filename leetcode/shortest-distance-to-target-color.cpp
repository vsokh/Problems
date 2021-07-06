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

class Solution {
public:

    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
		int C = 4, N = colors.size();
		vector<vector<int>> colorIndexes(C);
		for (int i = 0; i < N; ++i) // O(colors.length)
			colorIndexes[colors[i]].push_back(i);

		vector<vector<int>> colorsDis(C);
		for (int c = 1; c < C; ++c) { // O(3)
			auto idxs = colorIndexes[c];
			if (idxs.empty()) continue;

			int p = 0, q = idxs.size()-1;
			for (int i = 0; i < N; ++i) { // O(colors.length)
				p = i > idxs[p] && abs(idxs[p]-i) >= abs(idxs[min(p+1,q)]-i) ? min(p + 1, q) : p;
				colorsDis[c].push_back(abs(idxs[p]-i));
			}
		}
		/* for (int i = 1; i < C; ++i) { */
		/* 	cout << "clr: " << i << " - "; */
		/* 	for (int d = 0; d < N; ++d) { */
		/* 		cout << colorsDis[i][d] << " "; */
		/* 	} */
		/* 	cout << nl; */
		/* } */
		vector<int> result(queries.size());
		for (int i = 0; i < queries.size(); ++i) { // O(queries.length)
			int c = queries[i][1], idx = queries[i][0];
			auto d = colorsDis[c];
			result[i] = d.empty() ? -1 : d[idx];
		}
		// O(3*colors.length + queries.length) = O(max(colors.length, queries.length))
		return result;
    }

    /* vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) { */
		/* vector<vector<int>> colorIndexes(4); */
		/* for (int i = 0; i < colors.size(); ++i) */
			/* colorIndexes[colors[i]].push_back(i); */
		/* /1* for (int i = 0; i < colorIndexes.size(); ++i) { *1/ */
		/* /1* 	printf("[%d] - ", i); *1/ */
		/* /1* 	for (int j : colorIndexes[i]) *1/ */
		/* /1* 		printf("%d ", j); *1/ */
		/* /1* 	printf("\n"); *1/ */
		/* /1* } *1/ */

		/* const int inf = 1e9; */
		/* int minDis = inf; */
		/* vector<int> result(queries.size()); */
		/* for (int i = 0; i < queries.size(); ++i) { */
			/* minDis = inf; */
			/* auto indexes = colorIndexes[queries[i][1]]; */
			/* for (auto idx : indexes) */
				/* minDis = min(minDis, abs(idx-queries[i][0])); */
			/* result[i] = indexes.empty() ? -1 : minDis; */
		/* } */
		/* return result; */
    /* } */
};

int main()
{
	{
	vector<int> c{1,1,2,1,3,2,2,3,3};
	vector<vector<int>> q{{1,3},{2,2},{6,1}};
	Solution s;
	vector<int> r = s.shortestDistanceColor(c, q);
	for (int i : r)
		cout << i << " ";
	cout << endl;
	}
	{
	vector<int> c{1,2};
	vector<vector<int>> q{{0, 3}};
	Solution s;
	vector<int> r = s.shortestDistanceColor(c, q);
	for (int i : r)
		cout << i << " ";
	cout << endl;
	}
	return 0;
}
