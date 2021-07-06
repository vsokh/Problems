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
#define alp "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

int gcmp(const void *a, const void *b)
{ return (*(ll*)b - *(ll*)a); }

int lcmp(const void *a, const void *b)
{ return (*(ll*)a - *(ll*)b); }


ll t, m, k;

void solve()
{
	string s;
	getline(cin, s);

	string a = alp;
	bool ok = true;
	ll o = 0;
	vll q;
	for (ll i = 0; i < s.size();i++)
	{
		o = 0;
		ok = true;
		for (ll j = 0; j < 26; j++)
		{
			for (ll k = 0; k < 26; k++)
			{
				if (i+k < s.size() && a[j] == s[i+k])
					o++;
				if (o > 1)
				{
					ok = false;
					break ;
				}
			}
			if (!ok) break;
		}
		if (!ok) continue;
		cout << s[i] << nl;

		/* for (ll j = i; j < i+26; j++) */
		/* { */
		/* 	if (s[j] == '?') */
		/* 		q.pb(j); */
		/* } */
		/* vector<char> e; */
		/* for (ll j = i; j < i+26; j++) */
		/* { */
		/* 	bool was = false; */
		/* 	for (ll k = 0; k < 26; k++) */
		/* 	{ */
		/* 		if (alp[j] == s[j+k]) */
		/* 		{ */
		/* 			was = true; */
		/* 			break; */
		/* 		} */
		/* 	} */
		/* 	if (!was) */
		/* 		e.pb(alp[j]); */
		/* } */
		/* if (e.size() != q.size()) continue; */

		/* for (int i =0; i<e.size();i++) */
		/* 	s[q[i]] = e[i]; */
		/* break ; */
	}
	if (ok)
		yes;
	else
		no;
	/* if (ok) */
	/* { */
	/* 	for (int i =0; i<s.size();i++) */
	/* 	{ */
	/* 		if (s[i] == '?') */
	/* 			s[i] = 'A'; */
	/* 	} */
	/* 	for (int i =0; i<s.size();i++) */
	/* 		cout << s[i]; */
	/* 	cout << nl; */
	/* } */
	/* else */
	/* 	cout << -1 << nl; */
}

int main()
{
	/* cin >> t; */
	/* while (t--) */
	solve();
	return 0;
}

