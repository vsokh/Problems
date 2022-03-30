#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> result(nums.size());
        int left = 0;
        int right = nums.size()-1;
        int idx = nums.size()-1;
        while (left <= right)
        {
            if (abs(nums[left]) > abs(nums[right]))
            {
                result[idx]=nums[left]*nums[left];
                ++left;
            }
            else
            {
                result[idx]=nums[right]*nums[right];
                --right;
            }
            --idx;
        }
        return result;
    }
};

int main()
{
	Solution s;
	{
		vector<int> in = {-4, -1, 0, 3, 10};
		const auto& ot = s.sortedSquares(in);
		for (auto& i : ot)
		{
			cout << i << " ";
		}
		cout << "\n";
	}

	{
		vector<int> in = {1, 2, 3, 4, 5};
		const auto& ot = s.sortedSquares(in);
		for (auto& i : ot)
		{
			cout << i << " ";
		}
		cout << "\n";
	}

	{
		vector<int> in = {-4, -3, -2, -1, 0};
		const auto& ot = s.sortedSquares(in);
		for (auto& i : ot)
		{
			cout << i << " ";
		}
		cout << "\n";
	}
	{
		vector<int> in = {0};
		const auto& ot = s.sortedSquares(in);
		for (auto& i : ot)
		{
			cout << i << " ";
		}
		cout << "\n";
	}

	return 0;
}
