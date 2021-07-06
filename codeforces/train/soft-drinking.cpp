// https://codeforces.com/problemset/problem/151/A

#include <iostream>
#include <vector>

using namespace std;

void solve()
{
	int n,k,l,c,d,p,nl,np;
	cin >> n >> k >> l >> c >> d >> p >> nl >> np;
	cout << min(c*d, min((k*l)/nl, p/np))/n << endl;
}

int main(void)
{
	solve();
	return 0;
}
