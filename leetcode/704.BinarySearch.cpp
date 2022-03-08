
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

using vi = vector<int>;

class Solution
{
public:
     int search(vector<int>& nums, int target)
     {
         int left = 0;
         int right = nums.size();
         while (left < right)
         {
             int mid = left + (right - left)/2;
             if (nums[mid] == target)
             {
                 return mid;
             }
             else if (nums[mid] < target)
             {
                 left = mid + 1;
             }
             else
             {
                 right = mid;
             }
         }
         return -1;
     }
};

int main()
{
	Solution s;
	vi v1{-1,0,3,5,9,12};
	std::cout << s.search(v1, 9) << std::endl;

	vi v2{1,2,3,4};
	std::cout << s.search(v2, 5) << std::endl;

	vi v3{-1,0,3,5,9,12};
	std::cout << s.search(v3, 12) << std::endl;

	vi v4{1};
	std::cout << s.search(v4, 1) << std::endl;

	vi v5{1,2,3,4};
	std::cout << s.search(v5, 0) << std::endl;
	return 0;
}
