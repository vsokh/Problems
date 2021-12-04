#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
		for (int& i : nums)
			i = i < 0 ? -i : i;
		int m = 0;
		for (int i = 0; i < nums.size(); ++i)
		{
			if (nums[m] > nums[i])
				m = i;
		}
		vector<int> A; A.push_back(nums[m]);
		int l = m - 1, r = m + 1;
		while (l >= 0 && r < nums.size())
		{
			if (nums[l] < nums[r])
				A.push_back(nums[l--]);
			else
				A.push_back(nums[r++]);
		}
		while (l >= 0)
			A.push_back(nums[l--]);
		while (r < nums.size())
			A.push_back(nums[r++]);
		return A;
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
