#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    // Top-to-bottom and memoization. Time: O(n), Space: O(n).
    int climb(unordered_map<int, int>& m, int n)
    {
        if (n == 0) return 1;
        if (n <  0) return 0;

        if (auto it = m.find(n); it != m.end()) {
            return it->second;
        }
        m.insert({n, climb(m, n - 1) + climb(m, n - 2)});
        return m[n];
    }
    int climbStairs(int n)
    {
        unordered_map<int, int> m;
        return climb(m, n - 1) + climb(m, n - 2);
    }
};

int main()
{
    Solution s;
    cout << s.climbStairs(45) << endl;
    return 0;
}
