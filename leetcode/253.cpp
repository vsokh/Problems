


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
		int minMeetingRooms(vector<vector<int>>& intervals) {
			// count maxRooms
			// store active meetings
			auto printQ = [](priority_queue<int, vector<int>, std::greater<int>> q) {
				while (!q.empty()) {
					auto n = q.top(); q.pop();
					cout << n << " ";
				};
				cout << nl;
			};

			sort(intervals.begin(), intervals.end());

			priority_queue<int, vector<int>, std::greater<int>> q;
			for (auto interval : intervals) {
				if (!q.empty() && q.top() <= interval[0]) {
					q.pop();
				}

				q.push(interval[1]);
				/* printQ(q); */
			}
			return q.size();
		}
};

int main()
{
	setIO();
	Solution s;
	/* vector<vector<int>> v = {{0,30},{5,10},{15,20}}; */
	/* vector<vector<int>> v = {{1,3},{7, 10}}; */
	/* vector<vector<int>> v = {{7,10},{2, 4}}; */
	vector<vector<int>> v = {{1,5},{8,9},{8,9}};
	cout << s.minMeetingRooms(v) << nl;
	return 0;
}
