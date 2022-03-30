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
        int tmpSum = nums[0];
        int sum = nums[0];
        for (int i = 1; i < nums.size(); ++i)
        {
            tmpSum = std::max(nums[i], tmpSum + nums[i]);
            sum = std::max(tmpSum, sum);
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
