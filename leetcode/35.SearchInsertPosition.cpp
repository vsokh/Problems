#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size()-1;
        int m = l + (r - l) / 2;

        while (l <= r) {
            if (nums[m] == target) {
                return m;
            }

            if (nums[m] < target) {
                l = m + 1;
            } else {
                r = m - 1;
            }
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
