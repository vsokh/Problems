
#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define vvi vector<vector<int>>
#define pb push_back
#define nl "\n"

class Solution {
public:
    int candy(vector<int>& ratings) {
		int i = 0, j = 1, k = 1, n = ratings.size();
		int ans = k;
		while (j < n) {
			if (ratings[i] <= ratings[j]) {
				k = 1; ans += k;
			}
			else {
				k += 1; ans += k;
			}
			++j; ++i;
		}
		return ans;
    }
};

int main()
{
	Solution s;
	vi v{1,0,2};
	cout << s.candy(v) << nl;
	return 0;
}

