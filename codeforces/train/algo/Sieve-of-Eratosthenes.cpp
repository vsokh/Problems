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
}

int main()
{
	ll n = 1e6;
	cout << n << nl;

	vector<char> is_prime(n+1, true);
	is_prime[0] = is_prime[1] = false;

	for (ll i = 2; i<=n; i++) {
		if (is_prime[i] && i*i <= n) {
			for (int j = i*i; j <= n; j+=i) {
				is_prime[j] = false;
			}
		}
	}
	rep(i, 0, n+1) {
		if (is_prime[i])
			cout << i << " ";
	}
	cout << nl;
	return 0;
}

