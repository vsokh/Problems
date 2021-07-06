
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
	int const N = 3;
	vl m(N); vl c(N);
	for (ll i = 0; i < N; ++i)
		cin >> c[i] >> m[i];
	for (ll i = 0; i < N+1; ++i) {
		ll next = (i+1)%N, prev = i%N;
		ll sum = m[next] + m[prev];
		m[next] = sum > c[next] ? c[next] : sum;
		m[prev] = sum > c[next] ? sum - c[next] : 0;
	}
}

int main()
{
	setIO("mixmilk");

	solve();
	return 0;
}
