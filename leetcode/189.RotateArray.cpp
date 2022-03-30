#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void rotate(vector<int>& nums, int k)
    {
        int sz = nums.size();
        int n = k%sz;
        vector<int> tmp(sz);
        for (int i = 0; i < n; ++i)
            tmp[i] = nums[sz-n+i];
        for (int i = 0; i < sz-n; ++i)
            tmp[n+i] = nums[i];
        nums = tmp;
    }
};

int main()
{
    vector<int> v = {0,1,2,3,4,5,6}; int k = 3;
    Solution s; s.rotate(v, k);

    for (auto i : v)
        cout << i << " ";
    cout << endl;

    return 0;
}
