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
	ll N = 0;
	cin >> N;

	vl X(N), Y(N);
	for (ll &t: X) cin >> t;
	for (ll &t: Y) cin >> t;

	ll high = 0;
	for (ll i = 0; i < N; i++) {
		for (ll j = i+1; j < N; j++) {
			ll dx = X[i] - X[j], dy = Y[i] - Y[j];
			high = max(high, dx*dx + dy*dy);
		}
	}
	cout << high << endl;
}

int main()
{
	setIO();

	ll t;
	/* cin >> t; */
	/* while (t--) */
	solve();
	return 0;
}
