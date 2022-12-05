#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string makeGood(string s) {
        bool dirty = false;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] != '_' && ((toupper(s[i]) == s[i+1]) || (s[i] == toupper(s[i+1]))))
            {
                dirty = true;
                s[i] = '_';
                s[i+1] = '_';
            }
        }
        s.erase(remove(s.begin(), s.end(), '_'), s.end());
        if (dirty)
            return makeGood(s);
        return s;
    }
};

int main()
{
    Solution s;
    std::cout << s.makeGood("leEeetcode") << std::endl;
    std::cout << s.makeGood("abBAcC") << std::endl;
    return 0;
}
