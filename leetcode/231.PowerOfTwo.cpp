#include <iostream>
#include <vector>

using namespace std;

class Solution
{

public:
    bool isPowerOfTwo(int n)
	{
		return ((long)1 << 31)%n == 0;
    }
};

int main()
{
	Solution s;
	{
		std::vector<int> v = {-1, 2, 4, 8};
		for (auto& i: v)
			cout << s.isPowerOfTwo(i) << endl;
	}
	{
		std::vector<int> v = {-3, 3, 5, 7};
		for (auto& i: v)
			cout << s.isPowerOfTwo(i) << endl;
	}
	cout << s.isPowerOfTwo(0) << endl;
	return 0;
}
