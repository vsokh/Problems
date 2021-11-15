
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		vector<int> res;
		int i = 0; int j = 0;
		while (i < m && j < n)
		{
			if (nums1[i] < nums2[j])
				res.push_back(nums1[i++]);
			else
				res.push_back(nums2[j++]);
		}
		while (i < m)
			res.push_back(nums1[i++]);
		while (j < n)
			res.push_back(nums2[j++]);
		for (int i = 0; i < m + n; ++i)
			nums1[i] = res[i];
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
