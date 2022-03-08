#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int deleteAndEarn(vector<int>& nums) {
        unordered_set<int> us(nums.begin(), nums.end());
        int maxPts = 0;
        for (auto e : nums)
        {
            int currPts = 0;
            deleteAndEarn(e, us, currPts);
            maxPts = max(currPts, maxPts);
        }
        return maxPts;
    }

    void deleteAndEarn(int num, unordered_set<int> us, int& currPts)
    {
        currPts += num;

        for (auto e : us)
        {
            std::cout << e <<",";
        }

        us.erase(std::remove_if(
                    us.begin(),
                    us.end(),
                    [&num](int i)
                    {
                        return i == num || i == num-1 || i == num+1;
                    }),
                    us.end());

        /* us.erase(num); */
        /* us.erase(num+1); */
        /* us.erase(num-1); */

        /* for (auto e : us) */
        /* { */
        /*     std::cout << e <<","; */
        /* } */
        /* cout << endl; */

        /* for (auto e : us) */
        /* { */
        /*     deleteAndEarn(e, us, currPts); */
        /* } */
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
