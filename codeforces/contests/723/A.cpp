
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

ll t, m, k, n;

void solve()
{
	cin>>n;
	vll v(2*n); for(auto &t:v)cin>>t;
	if (n>1){
		for(ll i=1,j=1;i<=2*n+1;++i,++j){
			j%=2*n;
			j=j==0?1:j;
			if (2*v[j]==v[j-1]+v[j+1])
				swap(v[j], v[j-1]);
		}
	}
	for(auto t:v)cout<<t<<" ";
	cout<<nl;
}

int main()
{
	cin >> t;
	while (t--)
		solve();
	return 0;
}

