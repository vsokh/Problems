#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> map;

        for (char& ch : s) {
            ++map[ch];
        }

        for (int i = 0; i < s.size(); ++i) {
            int n = map[s[i]];
            if (n < 2) {
                return i;
            }
        }
        return -1;
    }
};

int main()
{
    Solution s;
    {
        string str = "leetcode";
        cout << s.firstUniqChar(str) << endl;
    }
    {
        string str = "loveleetcode";
        cout << s.firstUniqChar(str) << endl;
    }
    {
        string str = "aabb";
        cout << s.firstUniqChar(str) << endl;
    }
	return 0;
}
