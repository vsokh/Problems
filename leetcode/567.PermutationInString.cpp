#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> map;
        for (auto& ch: s1)
            ++map[ch];

        int i = 0, j = s1.size();
        for (int n = 0; n < s2.size(); n = (n+j)%s2.size())
        {
            auto tmp = map;
            for (int m = i; m != j; ++m)
                if (tmp[s2[i]] && --tmp[s2[i]])
        }

        return false;
    }
};

int main()
{
    Solution s;
    {
        string s1 = "aab", s2 = "eidbaaooo";
        cout << (s.checkInclusion(s1,s2) == true) << endl;
    }

    {
        string s1 = "ab", s2 = "eidboaoo";
        cout << (s.checkInclusion(s1,s2) == false) << endl;
    }
    return 0;
}
