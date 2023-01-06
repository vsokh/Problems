#include <iostream>
#include <iterator>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int deleteAndEarn(vector<int>& nums, vector<int>& mem, int i) {
        vector<int> mem(nums.size());
        if (i >= nums.size()) {
            return 0;
        }
        if (mem[i]) {
            return mem[i];
        }
        mem[i] = nums[i] + deleteAndEarn(nums, mem, i);
        return mem[i];
    }

    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int maxEarn = INT_MIN;
        vector<int> mem(nums.size());
        for (int i = 0; i < nums.size(); ++i) {
            int currEarn = deleteAndEarn(nums, mem, i);
            maxEarn = max(maxEarn, currEarn);
        }

        return maxEarn;
    }
};

int main()
{
    /* vector<int> nums{3,4,2}; */
    vector<int> nums{2,2,3,3,3,4};
    Solution s;
    std::cout << s.deleteAndEarn(nums) << std::endl;
    return 0;
}
