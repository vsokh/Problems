#include <vector>
#include <iostream>
#include <string>

using namespace std;

void solve()
{
	int n = 0;
	cin >> n;

	string s;
	cin >> s;

	if (n % 3 != 0)
	{
		cout << "NO" << endl;
		return ;
	}

	int k = n / 3;
	int m = 0;
	int t = 0;
	cout << (2*m == t ? "YES" : "NO") << endl;
}

int main()
{
	int tests = 0;
	cin >> tests;
	while (tests--)
		solve();
	return 0;
}


