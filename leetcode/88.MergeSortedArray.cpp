
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        int i = 0, j = 0;
        vector<int> v;
        while (i < m && j < n)
        {
            if (nums1[i] < nums2[j])
            {
                v.push_back(nums1[i]);
                ++i;
            }
            else
            {
                v.push_back(nums2[j]);
                ++j;
            }
        }
        while (i < m)
        {
            v.push_back(nums1[i]);
            ++i;
        }
        while (j < n)
        {
            v.push_back(nums2[j]);
            ++j;
        }
        for (int i = 0; i < m + n; ++i)
        {
            nums1[i]=v[i];
        }
    }
};

int main() {
	Solution s;
	{
		 vector<int> nums1 = {1,2,3,0,0,0}; int m = 3;
		 vector<int> nums2 = {2,5,6}; int n = 3;
		 // i = 3, j = 1
		 // vector<int> res = {1, 2, 2, 3, 5, 6}
		 s.merge(nums1, m, nums2, n);
		 for (int& i : nums1)
			 cout << i << " ";
		 cout << "\n";
	}
	{
		 vector<int> nums1 = {1}; int m = 1;
		 vector<int> nums2 = {}; int n = 0;
		 s.merge(nums1, m, nums2, n);
		 for (int& i : nums1)
			 cout << i << " ";
		 cout << "\n";
	}
	{
		 vector<int> nums1 = {0}; int m = 0;
		 vector<int> nums2 = {1}; int n = 1;
		 s.merge(nums1, m, nums2, n);
		 for (int& i : nums1)
			 cout << i << " ";
		 cout << "\n";
	}
	return 0;
}
