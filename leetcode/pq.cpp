
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

template<typename T>
void print_queue(T q) {
	cout << "PQ: " << nl;
	while (!q.empty()) {
		auto el = q.top(); q.pop();
		cout << el << " ";
	}
	cout << nl;
}

int main()
{
	auto cmp = [](int after, int before) {
		return before < after;
	};

	priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
	const auto data = {1, 8, 4, 5, 4};
	for (int i : data)
		pq.push(i);
	print_queue(pq);
	return 0;
}
