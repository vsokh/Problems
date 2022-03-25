#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
    public:
        int lengthOfLongestSubstring(string s)
        {
            if (s.size() == 1)
                return 1;

            int maxLen = 1;
            int left = 0;
            int right = 1;
            while (right < s.size())
            {
                int tmpLeft = left;
                while (tmpLeft < right)
                {
                    if (s[tmpLeft] == s[right])
                    {
                        left = tmpLeft+1;
                        break;
                    }
                    ++tmpLeft;
                }
                maxLen = max(maxLen, right - left + 1);
                ++right;
            }
            return maxLen;
        }
};

int main()
{
    Solution s;
    {
        string str = "abcabcbb";
        cout << s.lengthOfLongestSubstring(str) << endl;
    }
    /* { */
    /*     string str = "bbbbb"; */
    /*     cout << s.lengthOfLongestSubstring(str) << endl; */
    /* } */
    /* { */
    /*     string str = "pwwkew"; */
    /*     cout << s.lengthOfLongestSubstring(str) << endl; */
    /* } */
    /* { */
    /*     string str = ""; */
    /*     cout << s.lengthOfLongestSubstring(str) << endl; */
    /* } */
    /* { */
    /*     string str = "abcdeghijklnn"; */
    /*     cout << s.lengthOfLongestSubstring(str) << endl; */
    /* } */
    {
        string str = "abba";
        cout << s.lengthOfLongestSubstring(str) << endl;
    }
    return 0;
}
