
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
	ll N = 4;
	vl ans(N);
	vl s(N);
	for (ll i = 1; i<=3; ++i)
		s[i]=i;

	ll n, a, b, g;
	cin >> n;
	while (n--) {
		cin >> a >> b >> g;
		swap(s[a], s[b]);
		++ans[s[g]];
	}
	cout << max({ans[1], ans[2], ans[3]}) << nl;
}

int main()
{
	setIO("shell");

	solve();
	return 0;
}
