#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int fib(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;

        vector<int> v(n+1);
        v[0]=0; v[1]=1;
        for (int i = 2; i <= n; ++i) {
            v[i] = v[i-1]+v[i-2];
        }
        return v[n];
    }
};

int main()
{
    Solution s;
    cout << s.fib(0) << endl; // 1
    cout << s.fib(1) << endl; // 1
    cout << s.fib(2) << endl; // 1
    cout << s.fib(3) << endl; // 2
    cout << s.fib(4) << endl; // 3
    cout << s.fib(5) << endl; // 5
    cout << s.fib(6) << endl; // 5
    return 0;
}
