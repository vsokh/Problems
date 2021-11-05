#include <iostream>

using namespace std;

class Solution
{

public:
    int hammingWeight(uint32_t n)
	{
		int w = 0;
		for (int i = 0; i < 32; ++i)
			w += (n>>i) & 1;
		return w;
    }
};

int main() {
	Solution s;
	cout << s.hammingWeight(0) << endl;
	return 0;
}
