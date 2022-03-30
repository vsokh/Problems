#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution
{

public:
    bool containsDuplicate(vector<int>& nums)
	{
        std::unordered_map<int,int> m;
        for (const auto& num : nums)
        {
            ++m[num];
        }
        for (const auto& [num, cnt] : m)
        {
            if (cnt >= 2)
                return true;
        }
        return false;
    }
};

int main()
{
    Solution s;
    {
        std::vector<int> nums = {1,2,3,4};
        std::cout << s.containsDuplicate(nums) << std::endl;
    }
    {
        std::vector<int> nums = {1,1,1,3,3,4,3,2,4,2};
        std::cout << s.containsDuplicate(nums) << std::endl;
    }
	return 0;
}
