#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int>& nums, int target)
	{
		unordered_map<int, int> map;
		// O(n)
		for (int i = 0; i < nums.size(); ++i)
		{
			if (map.find(target-nums[i]) != map.end())
				return {map[target-nums[i]], i};
			map[nums[i]]=i;
		}
		return {};
	}
};

int main() {
	Solution s;
	{
		vector<int> v = {2,7,11,15}; int t = 9;
		for (auto& i : s.twoSum(v, t))
			cout << i << " ";
		cout << endl;
	}
	{
		vector<int> v = {0, 0, 1}; int t = 0;
		for (auto& i : s.twoSum(v, t))
			cout << i << " ";
		cout << endl;
	}
	return 0;
}
