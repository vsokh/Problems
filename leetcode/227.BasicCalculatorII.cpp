#include <vector>
#include <iostream>

using namespace std;

class Solution
{
private:
        enum class Token
        {
            Add, Sub, Div, Mul, Num
        };

public:
    vector<pair<Token, int>>
        toTokens(string s)
    {
        int num = -1;
        vector<pair<Token, int>> tokens;

        auto addNumToken = [&num, &tokens]()
        {
            if (num != -1)
            {
                tokens.push_back({Token::Num, num});
            }
            num = -1;
        };

        auto addOpToken = [&addNumToken, &tokens](const Token& token)
        {
            addNumToken();
            tokens.push_back({token, 0});
        };

        for_each(s.begin(),
                 s.end(),
                 [&](const auto& ch)
                 {
                     if (ch == ' ')
                     {
                         addNumToken();
                         return;
                     }

                     if ('0' <= ch && ch <= '9')
                     {
                         num = (num == -1 ? 0 : num) * 10 + ch - 48;
                         return;
                     }

                     if      (ch == '+') addOpToken(Token::Add);
                     else if (ch == '-') addOpToken(Token::Sub);
                     else if (ch == '/') addOpToken(Token::Div);
                     else if (ch == '*') addOpToken(Token::Mul);});
        return tokens;
    }

    vector<pair<Token, int>>
        toRPN(const vector<pair<Token, int>>& tokens)
    {
        vector<pair<Token, int>> output;
        vector<Token> opStack;

        auto isHigh = [](const auto& tkn)
        {
            vector<Token> high = {Token::Mul, Token::Div};
            return any_of(high.begin(), high.end(), [&](auto t){ return t == tkn; });
        };
        auto isLow = [](const auto& tkn)
        {
            vector<Token> low = {Token::Add, Token::Sub};
            return any_of(low.begin(), low.end(), [&](auto t){ return t == tkn; });
        };

        for_each(tokens.begin(),
                 tokens.end(),
                 [&](const auto& p)
                 {
                    if (p.first == Token::Num)
                    {
                        output.push_back(p);
                    }
                    else
                    {
                        auto o1 = p.first;
                        if (opStack.empty())
                        {
                            opStack.push_back(o1);
                            return;
                        }
                        auto o2 = opStack.back();
                        while (!opStack.empty() &&
                                ((isLow(o1) && isHigh(o2))  ||
                                 (isLow(o1) && isLow(o2))   ||
                                 (isHigh(o1) && isHigh(o2)) ||
                                 (isLow(o1) && isLow(o2))))
                        {
                            output.push_back({o2, 0});
                            opStack.pop_back();

                            if (opStack.empty()) break;

                            o2 = opStack.back();
                        }
                        opStack.push_back(o1);
                    }
                 });
        for (auto op = rbegin(opStack); op != rend(opStack); ++op)
            output.push_back({*op, 0});
        for (auto t: output)
            cout << t << endl;
        return output;
    }

    int calculate(string s)
    {
        auto tokens = toTokens(s);
        auto rpn = toRPN(tokens);
        /* auto result = evalRPN(rpn); */

        return 0;
    }

    friend std::ostream& operator<<(std::ostream& o, const pair<Token, int>& t)
    {
        if      (t.first == Token::Add) o << "Add";
        else if (t.first == Token::Sub) o << "Sub";
        else if (t.first == Token::Div) o << "Div";
        else if (t.first == Token::Mul) o << "Mul";
        else if (t.first == Token::Num)  o << "Num";

        o << ": " << t.second;
        return o;
    }
};


int main()
{
    string s = "3+2*2";
    /* string s = " 3+5 / 2 "; */
    Solution sol; sol.calculate(s);
    return 0;
}
