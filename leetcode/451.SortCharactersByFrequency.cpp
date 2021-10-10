
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
	template<typename T>
	void printQueue(T q) {
		while (!q.empty()) {
			auto p = q.top(); q.pop();
			cout << p.first << ": " << p.second << endl;
		}
	}
    string frequencySort(string s) {
		map<char, int> m;
		for (char ch : s) ++m[ch];

		using Pair = pair<char, int>;

		auto cmp = [](Pair const& p1, Pair const&  p2)
		{ return p1.second < p2.second; };

		priority_queue<Pair, vector<Pair>, decltype(cmp)> q(cmp);
		for (auto p : m) q.push(p);

		string ss;
		while (!q.empty()) {
			auto p = q.top(); q.pop();
			while (p.second--)
				ss += p.first;
		}
		return ss;
    }
};

int main()
{
	Solution s;

	cout << s.frequencySort("tree") << endl;
	cout << s.frequencySort("ttttttttttttttttr") << endl;
	cout << s.frequencySort("cccaaa") << endl;
	cout << s.frequencySort("Aabb") << endl;
	return 0;
}
