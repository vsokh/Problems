#include <bits/stdc++.h>

using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
#define nl "\n"

#define ull unsigned long long
#define ll long long

#define ulmx LLONG_MAX
#define lmx LLONG_MAX
#define lmn LLONG_MIN

#define ff first
#define ss second
#define mk make_pair
#define pb push_back

#define pri(i) printf("%lld\n", i);
#define prij(i,j) printf("%lld %lld\n", i, j);

#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl

#define vl vector<ll>
#define sl set<ll>
#define pl pair<ll, ll>

#define e9 1e9

#define setp(x) fixed<<setprecision(x)

int gcmp(const void *a, const void *b)
{ return (*(ll*)b - *(ll*)a); }

int lcmp(const void *a, const void *b)
{ return (*(ll*)a - *(ll*)b); }


ll t, m, k;

void solve()
{
	ll n, c;
	ll w, a, b;

	cin >> n >> c;
	w = 1; a = 0; b = 0;

	cin >> a;
	rep(i, 1, n) {
		cin >> b;
		int cc = b-a;
		if (cc<= c) w++;
		else w = cc > 0;
		a = b;
	}
	cout << w << endl;
}

int main()
{
	/* cin >> t; */
	/* while (t--) */
	solve();
	return 0;
}

