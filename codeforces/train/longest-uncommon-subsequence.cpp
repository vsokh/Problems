
//https://codeforces.com/problemset/problem/766/A

#include <iostream>
#include <vector>

using namespace std;

void solve()
{
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	int maxsize = max(s1.size(), s2.size());
	int minsize = min(s1.size(), s2.size());
	for (int i=0;i<maxsize;++i)
	{
		if (i >= minsize || s1[i] != s2[i])
		{
			cout << maxsize << endl;
			return ;
		}
	}
	cout << -1 << endl;
}

int main(void)
{
	solve();
	return 0;
}
