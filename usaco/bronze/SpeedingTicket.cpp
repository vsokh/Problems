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

void solve()
{
	ll n, m; cin >> n >> m;

	ll len, limit;
	ll currMile = 0;
	ll const N = 100;
	vl road(N);
	ll j = 0;
	for (ll i = 0; i < n; ++i) {
		cin >> len >> limit;
		currMile += len;
		for (;j < currMile; ++j) road[j] = limit;
		j = currMile;
	}
	ll speed; currMile = 0; j = 0;
	vl travel(N);
	for (ll i = 0; i < n; ++i) {
		cin >> len >> speed;
		currMile += len;
		for (;j < currMile; ++j) travel[j] = speed;
		j = currMile;
	}
	ll maxD = 0;
	for (ll i = 0; i < N; ++i) {
		ll d = travel[i] - road[i];
		if (maxD < d) maxD = d;
	}
	cout << maxD << nl;
}

int main()
{
	setIO("speeding");

	solve();
	return 0;
}
