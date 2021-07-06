#include <bits/stdc++.h>

using namespace std;
#define nl "\n"

int decodeV(const string& s) {
	if (s.length() == 0)
		return 0;

	for (char ch : s) {
		if (ch < '0' || '9' < ch)
			return 0;
	}

	int k = 1, i = 0;
	while (i < s.length() - 1) {
		int tmp = stoi(s.substr(i, 2));
		cout << tmp << endl;
		k = tmp != 0 && tmp <= 26 ? k + 1 : k;
		i++;
	}
	return k;
}

int main()
{
	{
		string s = "1023";
		cout << decodeV(s) << nl;
	}
	{
		string s = "1262";
		cout << decodeV(s) << nl;
	}
	return 0;
}
