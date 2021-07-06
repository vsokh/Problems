#include <bits/stdc++.h>

using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
#define nl "\n"

#define ull unsigned long long
#define ll long long

#define ulmx LLONG_MAX
#define lmx LLONG_MAX
#define lmn LLONG_MIN

#define fi first
#define se second
#define mp make_pair
#define pb push_back

#define pri(i) printf("%lld\n", i);
#define prij(i,j) printf("%lld %lld\n", i, j);

#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl

#define vll vector<ll>
#define sll set<ll>
#define pll pair<ll, ll>

#define e9 1e9

#define setp(x) fixed<<setprecision(x)

ll n, m, a, b;

void solve()
{
	cin >> n >> m >> a >> b;
	if (m*a <= b)
		cout << n*a << nl;
	else {
		ll x = n/m;
		ll r = n-x*m;
		if (r*a <= b) cout << x*b + r*a << nl;
		else cout << b * (x + 1) << nl;
	}
}

int main()
{
	/* cin >> t; */
	/* while (t--) */
	solve();
	return 0;
}

