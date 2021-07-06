#include <bits/stdc++.h>

using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
#define nl "\n"

#define ull unsigned long long
#define ll long long
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

/* bool gcmp(ull a, ull b) */
/* { */
/*   return a > b; */
/* } */

/* bool lcmp(ull a, ull b) */
/* { */
/*   return a < b; */
/* } */

ll t, n, m;

int gcmp(const void * a, const void * b)
{
  return ( *(ll*)b - *(ll*)a );
}

int lcmp(const void * a, const void * b)
{
  return ( *(ll*)a - *(ll*)b );
}

void solve()
{
	cin >> n >> m;

	ll a[n*m];
	ll ma[n*m];
	for (int i=0;i<n*m;i++)
	{
		cin >> a[i];
		ma[i] = a[i];
	}
	qsort(ma, n*m, sizeof(ll), lcmp);
	for (int i=0;i<n*m;i++)
	{
		if (i%m == 0) cout << nl;
		cout << a[i] << " ";
	}
	cout << nl;
	for (int i=0;i<n*m;i++)
	{
		if (i%m == 0) cout << nl;
		cout << ma[i] << " ";
	}
}

int main()
{
	cin >> t;
	while (t--)
		solve();
	return 0;
}

