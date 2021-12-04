#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void rotate(vector<int>& nums, int k)
    {
		int kk = k % nums.size();
		vector<int> v;
		for (int i = nums.size() - kk; i < nums.size(); ++i)
		{
			v.push_back(nums[i]);
		}
		for (int i = 0; i < nums.size() - kk; ++i)
		{
			v.push_back(nums[i]);
		}
		for (int i = 0; i < nums.size(); ++i)
		{
			nums[i] = v[i];
		}
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

