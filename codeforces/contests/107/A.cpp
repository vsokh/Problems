#include <vector>
#include <iostream>

using namespace std;

void solve()
{
	int n = 0; cin >> n;
	vector<int> v;

	int k = 0;
	for (int i = 0; i < n; i++) {
		cin >> k;
		v.push_back(k);
	}
	int r = 0;
	for (int i = 0; i < n; i++) {
		if (v[i] == 1 || v[i] == 3) ++r;
	}
	cout << r << endl;
}

int main()
{
	int tests = 0; cin >> tests;
	while (tests--) {
		solve();
	}
	return 0;
}

