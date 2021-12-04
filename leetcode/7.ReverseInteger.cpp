#include <iostream>


class Solution {
public:
    int reverse(int x)
    {
        int j = 0, n = 0;
        if (x < 0)
        {
            n = 1;
            x = -x;
        }
        while (x > 0)
        {
            ++i;
            int val = x % 10;
            x /= 10;
            if (val == 0 && j == 0)
                continue;

            j = j * 10 + val;
            if (j < 0)
                return 0;
        }
        return n ? -j : j;
    }
};

int main()
{
    Solution s;
    int v = (1<<31)-1;
    std::cout << s.reverse(v) << std::endl;
    std::cout << s.reverse(102) << std::endl;
    std::cout << s.reverse(120) << std::endl;
    std::cout << s.reverse(-123) << std::endl;
    std::cout << s.reverse(0) << std::endl;
    return 0;
}
