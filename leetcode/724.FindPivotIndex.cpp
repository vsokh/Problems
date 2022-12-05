#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0, leftSum = 0;
        for (auto n : nums) sum += n;
        for (auto i=1;i<nums.size();++i) {
            if(sum - leftSum - nums[i] == leftSum)
                return i;
            leftSum += nums[i];
        }
        return -1;
    }
};

int main()
{
    {
        vector<int> v= {2,2,2};
        Solution s;
        auto i = s.pivotIndex(v);
        std::cout << i << std::endl;
    }
    {
        vector<int> v= {2,1,1};
        Solution s;
        auto i = s.pivotIndex(v);
        std::cout << i << std::endl;
    }
    {
        vector<int> v= {1,1,2};
        Solution s;
        auto i = s.pivotIndex(v);
        std::cout << i << std::endl;
    }
    {
        vector<int> v= {1,2,4};
        Solution s;
        auto i = s.pivotIndex(v);
        std::cout << i << std::endl;
    }
    {
        vector<int> v= {2,1,-1};
        Solution s;
        auto i = s.pivotIndex(v);
        std::cout << i << std::endl;
    }
    return 0;
}

