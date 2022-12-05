#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    /* Input: s = "abbaca" */
    /* Output: "ca" */

    string removeDuplicates(string s)
    {
        if (s.size() <= s) {
            return s;
        }

        std::vector<char> stack; stack.push_back(s[i]);
        for (auto i = 1; i < s.size(); ++i) {
            if (!stack.empty()) {
                auto top = stack.back();
                if (top == s[i]) {
                    stack.pop_back();
                } else {
                    stack.push_back(s[i]);
                }
            } else {
                stack.push_back(s[i]);
            }
        }

        return {stack.begin(), stack.end()};
    }
};

int main()
{
    return 0;
}
