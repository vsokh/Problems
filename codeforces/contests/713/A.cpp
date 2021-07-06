#include <vector>
#include <iostream>

using namespace std;

void solve()
{
	int n = 0;
	cin >> n;

	int k = 0;
	vector<int> v;

	while (n--)
	{
		cin >> k;
		v.push_back(k);
	}

	for (int i = 1; i < v.size()-1; ++i) {
		int f = v[i-1], s = v[i], t = v[i+1];

		if (f == s && f != t) {
			cout << i+1+1 << endl;
			return ;
		}

		if (f == t && f != s) {
			cout << i+1 << endl;
			return ;
		}

		if (f != t && f != s) {
			cout << i-1+1 << endl;
			return ;
		}
	}
}

int main()
{
	int k = 0; cin >> k;
	while (k--) {
		solve();
	}
	return 0;
}

