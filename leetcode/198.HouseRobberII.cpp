#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums, vector<int>& mem, int i, int start) {
        if (start == 0 && nums.size()-1 == i) {
            return 0;
        }

        if (i >= nums.size()) {
            return 0;
        }

        if (mem[i] != -1) {
            return mem[i];
        }

        mem[i] = nums[i] + max(rob(nums, mem, i + 2, start), rob(nums, mem, i + 3, start));

        return mem[i];
    }

    int rob(vector<int>& nums) {
        vector<int> mem(nums.size(), -1);
        return max({rob(nums, mem, 0, 0), rob(nums, mem, 1, 1), rob(nums, mem, 2, 2)});
    }
};

int main()
{
    Solution s;
    /* vector<int> v{2,7,9,3,1}; */
    vector<int> v{2,0,0,4,0};
    cout << s.rob(v) << endl;
    return 0;
}
