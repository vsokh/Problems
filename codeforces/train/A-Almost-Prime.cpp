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

int gcmp(const void *a, const void *b)
{ return (*(ll*)b - *(ll*)a); }

int lcmp(const void *a, const void *b)
{ return (*(ll*)a - *(ll*)b); }


ll t, m, k;

void solve()
{
	ll n;
	cin >> n;
	vector<char> p(n+1, true);
	p[0] = p[1] = false;
	for (ll i=2; i*i<=n; i++) {
		for (ll j = i*i; j <= n; j += i) {
			if (p[j] && j%i==0)
				p[j] = false;
		}
	}
	ll cnt1 = 0;
	for (ll i=2; i<=n; i++) {
		ll cnt2 = 0;
		for (ll j=2; j<=n; j++) {
			if (p[j] && i!=j && i%j==0)
				cnt2++;
		}
		if (cnt2 == 2) cnt1++;
	}
	cout << cnt1 << nl;
}

int main()
{
	/* cin >> t; */
	/* while (t--) */
	solve();
	return 0;
}

