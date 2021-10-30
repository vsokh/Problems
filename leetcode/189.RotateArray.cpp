#include <iostream>
#include <vector>

using namespace std;

class Solution
{

public:
    void rotate(vector<int>& nums, int k)
    {
        int n = k%nums.size();
        vector<int> res;
        for (int i = nums.size()-n; i < nums.size(); ++i)
        {
            res.push_back(nums[i]);
        }
        for(int i = 0; i < nums.size()-n; ++i)
        {
            res.push_back(nums[i]);
        }
        for (int i = 0; i < nums.size(); ++i)
        {
            nums[i]=res[i];
        }
    }
};

int main()
{
    vector<int> v = {1,2,3,4,5,6,7}; int k = 3;
    Solution s; s.rotate(v, k);

    for (auto i : v)
        cout << i << " ";
    cout << endl;

    return 0;
}

