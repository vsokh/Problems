#include <vector>
#include <iostream>
#include <set>
#include <math.h>
#include <algorithm>
#include <iostream>

using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)

set<int> st;

void solve()
{
	int n = 0;
	cin >> n;
	int k = 0;
	cin >> k;

	vector<int> vec;
	int v = 0;
	rep(i, 0, n) {
		cin >> v; vec.push_back(v);
	}

	int o = min(vec[0], k);
	vec[0] -= o;
	vec[n-1] += o;
	rep(i, 0, n) {
		cout << vec[i] << " ";
	}
	cout << endl;
}

int main()
{
	int t = 0;
	cin >> t;

	while (t--)
		solve();
	return 0;
}

