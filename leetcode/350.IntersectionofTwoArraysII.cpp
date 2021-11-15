
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		vector<int> A = nums1.size() > nums2.size() ? nums1 : nums2;
		vector<int> B = nums1.size() > nums2.size() ? nums2 : nums1;
		vector<int> O;

		unordered_map<int, int> um;
		for (int& i : B)
			++um[i];

		// 2, 2
		for (int i = 0; i < A.size(); ++i)
		{
			if (um[A[i]])
				O.push_back(A[i]);
			else
				O.clear();
		}
		return O;
    }
};

int main() {
	Solution s;
	{
		vector<int> v1 = {1, 2, 2, 1}, v2 = {2, 2};
		for (auto& i : s.intersect(v1, v2))
			cout << i << " ";
		cout << endl;
	}
	{
		vector<int> v1 = {4, 9, 5}, v2 = {9, 4, 9, 8, 4};
		for (auto& i : s.intersect(v1, v2))
			cout << i << " ";
		cout << endl;
	}
	return 0;
}
