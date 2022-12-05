#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

enum class TokenType
{
    Unknown, Num, Minus, Plus, OpenPar, ClosePar
};

struct Token
{
    TokenType type{None};
    int value{-1};
};

class Solution
{
    public:
        void removeWhitespaces(string& s)
        {
            s.erase(remove(s.begin(), s.end(), ' '), s.end());
        }

        vector<Token> tokenize(string s)
        {
            vector<Token> result;
            auto it = s.begin();
            while (it != s.end()) {
                switch (*it) {
                    case '(':
                        result.emplace_back(TokenType::OpenPar);    ++it;
                    case ')':
                        result.emplace_back(TokenType::ClosePar);   ++it;
                    case '+':
                        result.emplace_back(TokenType::Plus);       ++it;
                    case '-':
                        result.emplace_back(TokenType::Minus);      ++it;
                    default: // num
                        size_t pos{0};
                        auto num = stoi(string{it, s.end}, 0);
                        result.emplace_back(TokenType::Minus);
                }
            }
        }

        int calculate(string s)
        {
            if (s.empty()) {
                return 0;
            }

            removeWhitespaces(s);
            auto tokens = tokenize(s);

            int num{0};
            stack<char> stack; stack.push(s[0]);
            auto it = s.begin();
            while (!s.empty())
            {
                auto e = stack.top();
                switch (e) {
                    case '(':
                        // continue
                    case ')':
                        // pop
                    case '+': continue;
                    case '-': continue;
                    default: // num
                }
            }
            return num;
        }
};

int main()
{
    Solution sol;
    {
        string s = "1 + 1";
        std::cout << sol.calculate(s) << std::endl;
    }
    {
        string s= " 2-1 + 2 ";
        std::cout << sol.calculate(s) << std::endl;
    }
    {
        string s = "(1+(4+5+2)-3)+(6+8)";
        std::cout << sol.calculate(s) << std::endl;
    }
    return 0;
}

