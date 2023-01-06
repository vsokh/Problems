#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> s;
        auto isNum = [](const string& s) {
            if ('0' <= s[0] && s[0] <= '9') {
                return true;
            }
            return s.size() > 1 && ('0' <= s[1] && s[1] <= '9');
        };

        for (auto tkn : tokens) {
            if (isNum(tkn)) {
                s.push_back(stoi(tkn));
            } else {
                int n1 = s.back(); s.pop_back();
                int n2 = s.back(); s.pop_back();
                int result = 0;

                if (tkn == "+") result = n2+n1;
                else if (tkn == "-") result = n2-n1;
                else if (tkn == "*") result = n2*n1;
                else if (tkn == "/") result = n2/n1;

                s.push_back(result);
            }
        }
        return s.back();
    }
};

int main()
{
    Solution s;
    vector<string> tokens {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    cout << s.evalRPN(tokens) << endl;
    return 0;
}
