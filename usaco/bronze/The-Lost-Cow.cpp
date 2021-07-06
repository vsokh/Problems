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
	ll x, y;
	cin >> x >> y;
	ll dis = 0;
	ll s = 1;
	ll dir = 1;
	while (true) {
		if ((dir==1 && x<=y && x+s>=y) || (dir==-1 && x>=y && x-s<=y)) {
			dis += abs(y-x);
			break ;
		}
		else {
			dis += 2*s;
			s *= 2;
			dir *= -1;
		}
	}
	cout << dis << endl;
}

int main()
{
	setIO("lostcow");

	solve();
	return 0;
}
