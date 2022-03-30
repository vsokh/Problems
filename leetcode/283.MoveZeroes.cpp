#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    void moveZeroes(vector<int>& nums)
    {
        for (int i = 0, j = 0; j < nums.size(); ++j)
        {
            if (nums[j] != 0)
            {
                swap(nums[i++], nums[j]);
            }
        }
    }
};

int main()
{
    vector<int> v = {0,1,0,3,12};

    Solution s;
    s.moveZeroes(v);

    for (auto i : v)
        cout << i << " ";
    cout << endl;
    return 0;
}
