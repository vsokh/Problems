#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int>& nums, int target)
	{
        int ir, jr;
        ir=jr=0;
        unordered_map<int,int> m;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (m.find(target-nums[i]) != m.end())
            {
                ir = i;
                jr = m[target-nums[i]];
                break;
            }
            m[nums[i]]=i;
        }

        return {ir, jr};
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
