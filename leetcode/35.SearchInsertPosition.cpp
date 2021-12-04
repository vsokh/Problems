#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int searchInsert(vector<int>& nums, int target) {
		int l = 0, r = nums.size();
		int m = l + (r - l) / 2;
		while (l < r)
		{
			if (nums[m] == target)
				break;

			if (nums[m] < target)
				r = m;
			else
				l = m + 1;

			 m = l + (r - l) / 2;
		}
		return m;
    }
};

int main()
{
	Solution s;
	{
		vector<int> nums = {1,3,5,6}; int target = 5;
		s.searchInsert(nums, target);
	}
	{
		vector<int> nums = {1,3,5,6}; int target = 2;
		s.searchInsert(nums, target);
	}
	{
		vector<int> nums = {1,3,5,6}; int target = 7;
		s.searchInsert(nums, target);
	}
	{
		vector<int> nums = {1,3,5,6}; int target = 0;
		s.searchInsert(nums, target);
	}
	return 0;
}
