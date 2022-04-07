#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        // [({})]
        vector<char> stack;
        for (auto it = s.begin(); it != s.end(); ++it)
        {
            char& ch = *it;
            if (ch == '[' || ch == '(' || ch == '{') {
                stack.push_back(ch);
                continue;
            }

            if (stack.empty()) return false;

            char e = stack.back(); stack.pop_back();
            if (ch == ']' && e != '[') return false;
            if (ch == ')' && e != '(') return false;
            if (ch == '}' && e != '{') return false;
        }
        return stack.empty();
    }
};

int main()
{
    Solution s;
    cout << s.isValid("[({})]") << endl;
    cout << s.isValid("[]") << endl;
    cout << s.isValid("[]{}()") << endl;
    cout << s.isValid("[]{()") << endl;
    return 0;
}
