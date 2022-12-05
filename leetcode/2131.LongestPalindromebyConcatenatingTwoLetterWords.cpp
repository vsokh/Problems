#include <algorithm>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

/* Input: words = ["lc","cl","gg"] */
/* Output: 6 */
/* Explanation: One longest palindrome is "lc" + "gg" + "cl" = "lcggcl", of length 6. */
/* Note that "clgglc" is another longest palindrome that can be created. */

class Solution
{
public:
    int longestPalindrome(vector<string>& words)
    {
        auto isPalindrom = [](const string& word)
        {
            return word[0] == word[1];
        };

        int cnt = 0;
        words.erase(remove_if(words.begin(), words.end(),
                    [&isPalindrom, &cnt](const string& word)
                    {
                        auto result = isPalindrom(word);
                        if (result) {
                            cnt += 2;
                        }
                        return result;
                    }), words.end());
        std::unordered_map<string, int> map;
        for (auto w : words) {
            if (auto it = map.find(w); it != map.end()) {
                ++it->second;
            } else {
                map.insert({w, 1});
            }
        }
        for (auto [w,i] : map) {
            if (auto it = map.find(string{w[1],w[0]}); it != map.end()) {
                    cnt += 4*i;
            }
            map.erase(it);
            /* std::cout << w << ":" << i << std::endl; */
        }
        return 0;
    }
};

int main()
{
    Solution s;
    vector<string> vec = {"lc", "cl", "gg", "ff"};
    s.longestPalindrome(vec);
    return 0;
}
