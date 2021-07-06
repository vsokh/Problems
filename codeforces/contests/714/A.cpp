#include <vector>
#include <iostream>

using namespace std;

void solve()
{
	int n = 0, k = 0;
	cin >> n; cin >> k;

	int kn = n / 3;
	if (k != 0 && (kn < k || n < 3))
		cout << -1 << endl;
	else {
	}

}

int main()
{
	int t = 0; cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}

