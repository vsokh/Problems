#include <vector>
#include <iostream>

class Solution {
public:
    int calculate(string s)
    {
        int result = 0;
        auto vec = split(s);
        auto rpn = createRPN(vec);
        return calculateRPN(rpn);
    }
};

int main()
{
	return 0;
}
