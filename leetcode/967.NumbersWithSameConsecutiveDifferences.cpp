#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>

using namespace std;

class Solution {
public:
    void constructNum(vector<int>& nums, int num, int n, int k)
    {
        if (n == 0) {
            nums.push_back(num);
            return;
        }

        auto leftnum = (num%10) + k;
        if (0 <= leftnum && leftnum <= 9)
            constructNum(nums, num*10+leftnum, n-1, k);

        auto rightnum = (num%10) - k;
        if (leftnum == rightnum) return;
        if (0 <= rightnum && rightnum <= 9)
            constructNum(nums, num*10+rightnum, n-1, k);
    }

    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> nums;
        for (auto i = 1; i < 10; ++i) {
            constructNum(nums, i, n-1, k);
        }
        return nums;
    }
};

int main()
{
    Solution s;
    auto v = s.numsSameConsecDiff(3, 7);
    for (auto n : v) {
        cout << n << " ";
    }
    cout << endl;
    return 0;
}
