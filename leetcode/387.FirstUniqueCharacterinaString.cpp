#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> map;
        for (int i = 0; i < s.size(); ++i)
        {
            if (map.find(s[i]) != map.end())
                map[s[i]]=-1;
            else
                map[s[i]]=i;
        }

        int result = -1;
        for (auto& [ch, idx] : map)
        {
            if (idx != -1)
                result = (result == -1 || result > idx) ? idx : result;
        }
        return result;
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
