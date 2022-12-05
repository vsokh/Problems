
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

using vi = vector<int>;

class Solution {
public:
     int search(vector<int>& nums, int target) {
         int l = 0;
         int r = nums.size()-1;
         while (l <= r) {
             int m = l + (r - l)/2;
             if (nums[m] == target) {
                 return m;
             }

             if (nums[m] < target) {
                 l = m + 1;
             } else {
                 r = m - 1;
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
