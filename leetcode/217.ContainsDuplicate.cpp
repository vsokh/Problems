#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{

public:
    bool containsDuplicate(vector<int>& nums)
	{
		unordered_map<int, int> map;
		for (auto& i:nums)
			++map[i];

		for (auto& p:map)
			if (p.second >= 2)
				return true;

		return false;
    }
};

int main()
{
	return 0;
}
