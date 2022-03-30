#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size();
        int mid = left + (right - left) / 2;
		while (left < right)
		{
            if (nums[mid] == target)
            {
                return mid;
            }
            if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
            mid = left + (right - left) / 2;
		}
		return mid;
    }
};

int main()
{
	Solution s;
	{
		vector<int> nums = {1,3,5,6}; int target = 5;
		cout << (s.searchInsert(nums, target) == 2) << endl;
	}
	{
		vector<int> nums = {1,3,5,6}; int target = 2;
		cout << (s.searchInsert(nums, target) == 1) << endl;
	}
	{
		vector<int> nums = {1,3,5,6}; int target = 7;
		cout << (s.searchInsert(nums, target) == 4) << endl;
	}
	{
		vector<int> nums = {1,3,5,6}; int target = 0;
		cout << (s.searchInsert(nums, target) == 0) << endl;
	}
	return 0;
}
