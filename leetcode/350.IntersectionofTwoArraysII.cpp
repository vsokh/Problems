
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
    {
        vector<int> result;
        for (auto i : nums1)
        {
            vector<int> tmp;
            for (auto j : nums2)
            {
                if (i == j)
                    tmp.push_back(i);
                if (result.empty() || result.size() < tmp.size())
                    result = tmp;
            }
        }
        return result;
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
