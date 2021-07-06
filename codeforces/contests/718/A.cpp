#include <bits/stdc++.h>

using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
#define nl "\n"

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
	ull a = 2050;
	ull b = 0;
	cin >> b;
	if (b % a == 0)
	{
		ull q = b / a;
		ull s = 0;
		while (q)
		{
			s += q % 10;
			q /= 10;
		}
		cout << s << nl;
	}
	else
		cout << -1 << nl;

}

int main()
{
	cin >> t;
	while (t--)
		solve();
	return 0;
}

