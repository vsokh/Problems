
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
	ll n, k; cin >> n >> k;
	vl v(n); for (ll &t: v) cin >> t;

	ll ans = 0;
	for (ll i = 0; i < n; ++i) {
		ll tmp = 0;
		for (ll j = 0; j < n; ++j) {
			if (v[j] >= v[i] && v[j] - v[i] <= k) ++tmp;
		}
		ans = max(ans, tmp);
	}
	cout << ans << nl;
}

int main()
{
	setIO("diamond");
	solve();
	return 0;
}
