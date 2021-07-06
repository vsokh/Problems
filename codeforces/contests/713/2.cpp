#include <vector>
#include <iostream>

using namespace std;

void solve()
{
	int n = 0;
	cin >> n;

	vector<string> vs;
	string s;
	int nn = n;

	while (n >= 0)
	{
		getline(cin, s);
		if (!s.empty())
			vs.push_back(s);
		--n;
	}

	pair<int, int> p1(-1, -1);
	pair<int, int> p2(-1, -1);
	for (int i = 0; i < nn; ++i) {
		for (int j = 0; j < nn; ++j) {
			if (vs[i][j] == '*') {
				if (p1.first == -1) {
					p1.first = i;
					p1.second = j;
				}
				else if (p2.first == -1) {
					p2.first = i;
					p2.second = j;
				}
			}
		}
	}

	if (p1.first == p2.first) {
		if (p1.first == nn-1){
			p1.first--;
			p2.first--;
		}
		else {
			p1.first++;
			p2.first++;
		}
		vs[p1.first][p1.second] = '*';
		vs[p2.first][p2.second] = '*';
	}
	else if (p1.second == p2.second) {
		if (p1.second == nn-1) {
			p1.second--;
			p2.second--;
		}
		else {
			p1.second++;
			p2.second++;
		}
		vs[p1.first][p1.second] = '*';
		vs[p2.first][p2.second] = '*';
	}
	else {
		vs[p1.first][p2.second] = '*';
		vs[p2.first][p1.second] = '*';
	}


	for (int i = 0; i < nn; ++i) {
		for (int j = 0; j < nn; ++j) {
			cout << vs[i][j];
		}
		cout << endl;
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

