#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int countOnes(int n)
    {
        int count = 0;
        for (; n; ++count)
        {
            n &= n - 1;
        }
        return count;

    }

    int isPowerOf2(int n)
    {
        return n && !(n & (n - 1));
    }

    vector<int> countBits(int n)
    {
        int powerOf2 = 0;
        unordered_map<int, int> lookupTable;
        lookupTable[0]=0;
        lookupTable[1]=1;
        for (int i = 2; i <= n; ++i)
        {
            powerOf2 = isPowerOf2(i) ? i : powerOf2;
            lookupTable[i] = lookupTable[i-powerOf2]+1;
        }

        vector<int> ans(n+1);
        for (int i = 0; i <= n; ++i)
        {
            ans[i]=lookupTable[i];
        }
        return ans;
    }
};

int hammingWeight(int n)
{
    int cnt = 0;
    while (n > 0)
    {
        ++cnt;
        n &= n - 1;
    }
    return cnt;
}

int main()
{
    /* Solution s; */
    /* auto v = s.countBits(5); */
    /* for (auto i : v) */
    /*     cout << i << ", "; */
    /* cout << endl; */
    cout << hammingWeight(6) << endl;
    return 0;
}
