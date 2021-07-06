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
	ll x, y, m; cin >> x >> y >> m;
	ll X = m/x, Y = m/y;
	ll k = 0, p = 0, high = 0;
	for (ll i = 0; i <= X; ++i) {
		for (ll j = 0; j <= Y; ++j) {
			ll tmp = i*x + j*y;
			if (tmp > m) break ;
			if (high <= tmp) {
				k = i; p = j; high = tmp;
			}
		}
	}
	cout << k*x + p*y << nl;
}

int main()
{
	setIO("pails");
	solve();
	return 0;
}
