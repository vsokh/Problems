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
        for (int i = 0; i < nums.size(); ++i) {
            map.insert({nums[i], i});
        }

        for (int i = 0; i < nums.size(); ++i) {
            int num = target-nums[i];
            if (auto it = map.find(num);
                     it != map.end() && it->second != i) {
                return {i, it->second};
            }
        }
        return {-1, -1};
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
