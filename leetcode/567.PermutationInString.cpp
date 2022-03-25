#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        for (auto i = s2.begin(); i < s2.end(); ++i) {
            bool yes = is_permutation(s1.begin(), s1.end(), i);
            if (yes)
                return true;
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

    {
        string s1 = "ab", s2 = "eidbaooo";
        cout << (s.checkInclusion(s1,s2) == true) << endl;
    }
    return 0;
}
