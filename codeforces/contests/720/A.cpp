#include <bits/stdc++.h>

using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
#define nl "\n"

#define ll long long
#define ull unsigned long long
#define imx INT_MAX
#define lmx LLONG_MAX
#define imn INT_MIN
#define lmn LLONG_MIN

#define ff first
#define ss second
#define pb push_back

#define pri(i) printf("%d\n", i)
#define prij(i,j) printf("%d %d\n", i, j)
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl

#define vi vector<int>
#define si set<int>
#define pi pair<int, int>

#define setp(x) fixed<<setprecision(x)

ull t, n, k;

void solve()
{
	ll a, b;
	cin >> a >> b;
	if (b == 1) no;
	else {
		yes;
		cout << a << " " << a*b << " " << a*(b+1) << nl;
	}
}

int main()
{
	cin >> t;
	while (t--)
		solve();
	return 0;
}

