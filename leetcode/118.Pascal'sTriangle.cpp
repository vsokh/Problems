#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows)
	{
		vector<vector<int>> v;
		// O(n2)
		for (int i = 0; i < numRows; ++i)
		{
			vector<int> row(i+1, 1);
			for (int j = 1; j < i; ++j)
			{
				row[j] = v[i-1][j-1] + v[i-1][j];
			}
			v.push_back(row);
		}
		return v;
    }
};

int main()
{
	Solution s;
	auto v = s.generate(2);
	for (auto& row : v)
	{
		for (auto& i : row)
			cout << i << " ";
		cout << endl;
	}
	return 0;
}
