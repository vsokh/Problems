#include <vector>
#include <iostream>

using namespace std;

int bad = 3;
int isBadVersion(int n)
{
	return n >= bad;
}

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 0;
        int right = n;
        int mid = left + (right - left)/2;
        while (left < right)
        {
            if (isBadVersion(mid))
            {
                right = mid;
            }
            else
            {
                left = mid+1;
            }
            mid = left + (right - left)/2;
        }
        return mid;
    }
};

int main()
{
	Solution s;
	cout << s.firstBadVersion(5) << endl;
	cout << bad << endl;
	return 0;
}
