#include <iostream>

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;

        int y = 0;
        int tmp = x;
        while (tmp > 0)
        {
            y = (long long)y * 10 + tmp % 10;
            tmp /= 10;
        }
        return y == x;
    }
};

int main()
{
    Solution s;
    std::cout << s.isPalindrome(1221) << std::endl;
    return 0;
}
