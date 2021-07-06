
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

void print_str(string s, ll n, ll k)
{
	for (ll i = 0; i<n; ++i)
		for (ll t = 0; t < k; ++t)
			cout << s[i];
	cout << nl;
}

void solve()
{
	ll m, n, k;
	cin >> m >> n >> k;
	string s = "";
	for (ll i = 0; i <= m; ++i) {
		getline(cin, s);
		if (s.empty()) continue;
		for (ll j = 0;j<k; ++j)
			print_str(s, n, k);
	}
}

int main()
{
	setIO("cowsignal");

	solve();
	return 0;
}
