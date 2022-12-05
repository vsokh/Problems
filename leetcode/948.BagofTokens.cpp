#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int score = 0;
        sort(tokens.begin(), tokens.end());

        int l = 0;
        int r = tokens.size()-1;
        while (l < r) {
            int min = tokens[l++];
            int max = tokens[r--];

            if (min <= power) {
                power -= min;
                ++score;
            } else if (score >= 1) {
                power += max;
                --score;
            } else {
                break;
            }
        }
        return score;
    }
};

int main()
{
    return 0;
}
