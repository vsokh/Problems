#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define vvi vector<vector<int>>
#define pb push_back
#define nl "\n"

class Solution {
	public:
		void print(vector<vector<int>> const& memo)
		{
			for (int i = 0; i < memo.size(); ++i) {
				cout << i << ": ";
				for (int j = 0; j < memo[i].size(); ++j)
					if (memo[i][j] == -1)
						printf("%2d ", memo[i][j]);
					else
						printf("%2s ", memo[i][j] == 1 ? "X" : "O" );
				cout << endl;
			}
		}
		bool isInterleave(
				string s1, int i,
				string s2, int j,
				string s3, int k,
				vector<vector<int>>& memo)
		{
			/* printf("Memo: i(%d), j(%d), k(%d)\n", i,j,k); */
			/* print(memo); */
			/* cout << endl; */
			if (i == s1.length()) return s2.substr(j) == s3.substr(k);
			if (j == s2.length()) return s1.substr(i) == s3.substr(k);
			if (memo[i][j] != -1) return memo[i][j];

			bool ans = false;
			if (s1[i] == s3[k])
				ans = isInterleave(s1, i+1, s2, j, s3, k+1, memo);
			if (s2[j] == s3[k])
				ans = isInterleave(s1, i, s2, j+1, s3, k+1, memo);
			memo[i][j] = ans;
			return ans;
		}

		bool isInterleave(string s1, string s2, string s3) {
			if (s1.length() + s2.length() != s3.length())
				return false;

			int n = s1.length(), m = s2.length();
			vector<vector<int>> memo(n, vector<int>(m, -1));

			return isInterleave(s1, 0, s2, 0, s3, 0, memo);
		}
};

int main()
{
	Solution s;
	string s1 = "aabcc";
	string s2 = "dbbca";
	string s3 = "aadbbcbcac";
	cout << s.isInterleave(s1, s2, s3) << nl;
	/* string s1 = "abc"; */
	/* string s2 = "def"; */
	/* string s3 = "abcdef"; */
	/* string s4 = "abde"; */
	/* cout << (s1.substr(0, 2) + s2.substr(0, 2) == s4) << nl; */
	return 0;
}

