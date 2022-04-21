#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(int n, vector<int>& nums) {
        // 2,7,9,3,1,6
        nums[n]
       //        2(0)
       //    9(2)   [7](1)
       //    3(3) 1(4)
       // 1(4) 6(5)
       //
       //       7(1)
       //    3(3)  1(4)
       //  6(5)
       //
       //       9(2)
       //    1(4)  6(5)
    }

    int rob(vector<int>& nums) {
        int sum = 0;
        for (int n = 0; n < nums.size(); ++n) {
            sum = max(sum, rob(n, nums);
        }
        return sum;
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
