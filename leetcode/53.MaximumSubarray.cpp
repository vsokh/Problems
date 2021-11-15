#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

using vec = vector<int>;

class Solution
{

public:
    int maxSubArray(vector<int>& nums)
	{
		vector<int> dp(nums.size()); dp[0] = nums[0];
		int sum = nums[0];
		for (int i = 1; i < nums.size(); ++i)
		{
			dp[i] = nums[i] + (dp[i-1] > 0 ? dp[i-1] : 0);
			sum = max(sum, dp[i]);
		}
		return sum;
    }
};

int main()
{
	Solution s;
	{
		vec v = {-2,1,-3,4,-1,2,1,-5,4};
		cout << s.maxSubArray(v) << endl;
	}
	{
		vec v = {1};
		cout << s.maxSubArray(v) << endl;
	}
	{
		vec v = {5, 4, -1, 7, 8};
		cout << s.maxSubArray(v) << endl;
	}
	return 0;
}
