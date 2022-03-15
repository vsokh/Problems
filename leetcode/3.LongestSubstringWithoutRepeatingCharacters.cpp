#include <iostream>
#include <unordered_map>

using namespace std;

class Solution
{
    public:
        int lengthOfLongestSubstring(string s)
        {
            if (s.empty()) return 0;

            unordered_map<char, long> charToPos;
            long len = 0;
            auto p1 = s.begin();
            auto p2 = s.begin();
            cout << s << " " << s.size() << endl;
            while (p2!=s.end()) {
                if (auto it = charToPos.find(*p2); it != charToPos.end()) {
                    cout << "IF: ";
                    cout << *p2 << " " << (p2-s.begin()) << endl;

                    p1 = s.begin() + it->second + 1;
                    it->second = p2-s.begin();
                }
                else {
                    cout << "ELSE: ";
                    cout << *p2 << " " << (p2-s.begin()) << endl;
                    charToPos.insert({*p2, p2-s.begin()});
                }
                ++p2;
                len = std::max(len, p2-p1);
            }
            return len;
        }
};

int main()
{
    Solution s;
    /* { */
    /*     string str = "abcabcbb"; */
    /*     cout << s.lengthOfLongestSubstring(str) << endl; */
    /* } */
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
