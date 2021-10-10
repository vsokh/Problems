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
		int getClosestIdx(const vector<int>& indexes, int p, int q, int x) {
			int mid = (p+q)/2;
			/* cout << "\tmid: " << mid << nl; */
			while (0 < mid && mid < indexes.size()) {
				if (indexes[mid] == x) break;
				if (indexes[mid] > x) q = mid;
				else p = mid+1;
				if (p == q) break;
				mid = (p+q)/2;
				/* cout << "\tmid: " << mid << nl; */
			}
			return abs(indexes[mid]-x);
		}

		vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries)
		{
			// To do:
			// 1. Create hash
			// 2. Use binary search to find a closest index h[q[j].c].i to index q[j].i
			// 3. Evaluate Time and Space complexity
			// 4. Read solution
			vector<vector<int>> colorsPositions(4);
			for (int i = 0; i < colors.size(); ++i) //O(m)
				colorsPositions[colors[i]].push_back(i);
			cout << "\nclrs table:\n";
			for (int i = 1; i < colorsPositions.size(); ++i) {
				auto clrs = colorsPositions[i];
				cout << i << ": ";
				for (int c : clrs)
					cout << c << " ";
				cout << nl;
			}

			vector<int> result(queries.size());
			for (int i = 0; i< queries.size(); ++i) { //O(n)
				auto indexes = colorsPositions[queries[i][1]];
				auto x = queries[i][0];
				auto p = lower_bound(indexes.begin(), indexes.end(), x);
				/* result[i] = indexes.empty() ? -1 : getClosestIdx(indexes, 0, indexes.size(), x); // O(log n) */
				if (p!=indexes.begin() && abs(*(p-1)-x) < abs(*p-x))--p;
				/* cout << "clr: " << queries[i][1] << ", idx: " << queries[i][0] << ", *p = " << *p << nl; */
				result[i] = indexes.empty() ? -1 : abs(*p-x); // O(log n)
			}
			//O(m + n log n)
			return result;
		}
};

int main()
{
	/* { */
	/* 	vector<int> c{1,1,2,1,3,2,2,3,3}; */
	/* 	vector<vector<int>> q{{1,3},{2,2},{6,1}}; */
	/* 	Solution s; */
	/* 	auto dis = s.shortestDistanceColor(c, q); */
	/* 	for (int d : dis) { */
	/* 		cout << d << " "; */
	/* 	} */
	/* 	cout << nl; */
	/* } */
	/* { */
	/* 	vector<int> c{3,2,2,1,3,1,1,1,3,1}; */
	/* 	vector<vector<int>> q{{4,1},{9,2},{4,2},{8,1},{0,3},{2,1},{2,3},{6,3},{4,1},{1,2}}; */
	/* 	Solution s; */
	/* 	auto dis = s.shortestDistanceColor(c, q); */
	/* 	cout << "output:   "; */
	/* 	for (int d : dis) { */
	/* 		cout << d << " "; */
	/* 	} */
	/* 	cout << nl; */
	/* 	cout << "expected: "; */
	/* 	for (int d : {1,7,2,1,0,1,2,2,1,0}) { */
	/* 		cout << d << " "; */
	/* 	} */
	/* 	cout << nl; */
	/* } */
	{
		vector<int> c{3,1,1,2,3,3,2,1,2,3,1,1,3,2,3,1,1,1,1,2,2,1,2,2,2,1,1,1,1,2,3,3,3,1,3,2,1,1,2,2,1,3,1,2,1,1,2,2,1,2};
		vector<vector<int>> q{{10,2},{0,1},{32,3},{1,1},{41,1},{48,3},{0,3},{46,2},{48,2},{28,1},{47,2},{11,2},{49,3},{3,3},{40,1},{1,2},{42,2},{47,2},{36,3},{23,1},{7,3},{47,2},{13,3},{36,1},{17,2},{46,2},{38,2},{0,1},{38,3},{36,3},{33,1},{11,3},{39,2},{10,2},{44,3},{5,1},{36,3},{44,3},{38,1},{9,1},{9,1},{35,3},{10,1},{9,1},{0,3},{1,1},{0,3},{28,1},{22,3},{15,1}};
		Solution s;
		auto dis = s.shortestDistanceColor(c, q);
		cout << "output:   ";
		for (int d : dis) {
			cout << d << " ";
		}
		cout << nl;
		cout << "expected: ";
		for (int d : {2,1,0,0,1,7,0,0,1,0,0,2,8,1,0,2,1,0,2,2,2,0,1,0,2,0,0,1,3,2,0,1,0,2,3,2,2,3,1,1,1,1,0,1,0,0,0,0,8,0}) {
			cout << d << " ";
		}
		cout << nl;
	}
	return 0;
}
