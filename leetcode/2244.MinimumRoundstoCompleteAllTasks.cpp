#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int minimumRounds(vector<int>& tasks) {
        std::unordered_map<int,int> freq;
        for (auto t : tasks) {
            ++freq[t];
        }

        int rounds = 0;
        for (auto [_, n] : freq) {
            if (n == 1) {
                return -1;
            }
            if (n % 3 == 0) {
                rounds += n/3;
            } else {
                int m = n/3;
                int r = n - m;
                if (r == 1) {
                    rounds += m + (n - (m - 1) * 3) / 2;
                } else {
                    rounds += (n - m) / 2;
                }
            }
        }
        return rounds;
    }
};

int main()
{
    Solution s;
    /* vector<int> v{2,2,3,3,2,4,4,4,4,4}; */
    vector<int> v{2,2,3};
    cout << s.minimumRounds(v) << endl;
    return 0;
}

