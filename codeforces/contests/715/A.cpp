#include <vector>
#include <iostream>

using namespace std;

void solve()
{
	int n = 0;
	cin >> n;

	int k = 0;
	vector<int> e;
	vector<int> o;
	for (int i=0; i<n; ++i)
	{
		cin >> k;
		if (k % 2 == 0)
			e.push_back(k);
		else
			o.push_back(k);
	}
	for (int i=0; i<e.size(); ++i)
		cout << e[i] << " ";
	for (int i=0; i<o.size(); ++i)
		cout << o[i] << " ";
	cout << endl;
}

int main()
{
	int tests = 0;
	cin >> tests;
	while (tests--)
		solve();
	return 0;
}

