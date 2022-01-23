#include <iostream>
#include <vector>

using namespace std;

class Solution
{

public:
    vector<int> sequentialDigits(int low, int high)
    {
        int tmp = high;
        int N = 0;
        while (tmp > 0)
        {
            ++N;
            tmp /= 10;
        }

        vector<int> seqDigs;
        for (int x = 1; x < N; ++x)
        {
            int tmp = x;
            while (tmp <= high)
            {
                seqDigs.push_back(tmp);
                tmp = tmp * 10 + tmp % 10 + 1;
            }
        }

        vector<int> res;
        for (auto xx : seqDigs)
        {
            if (low <= xx && xx <= high)
                res.push_back(xx);
        }
        return res;
    }
};

int main()
{
    Solution s;
    auto res = s.sequentialDigits(100, 300);
    for (auto x : res)
        cout << x << endl;
    return 0;
}
