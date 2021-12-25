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
        long long num = -1;
        vector<pair<Token, int>> tokens;

        auto addNumToken =
            [&num, &tokens]()
        {
            tokens.push_back({Token::Num, num});
            num = -1;
        };

        auto addOpToken =
            [&tokens](const Token& token)
        {
                tokens.push_back({token, 0});
        };

        auto isNum =
            [](const char& ch)
        {
                return '0' <= ch && ch <= '9';
        };

        auto it = s.begin();
        while (it != s.end())
        {
            auto ch = *it;
            while (isNum(ch))
            {
                num = (num == -1 ? 0 : num) * 10 + ch - 48;

                if (++it == s.end())
                    break;

                ch = *it;
            }

            if (num != -1) addNumToken();

            if      (ch == '+') addOpToken(Token::Add);
            else if (ch == '-') addOpToken(Token::Sub);
            else if (ch == '/') addOpToken(Token::Div);
            else if (ch == '*') addOpToken(Token::Mul);

            if (it != s.end()) ++it;
        }

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
        return output;
    }

    int evalRPN(vector<pair<Token, int>> rpn)
    {
        vector<int> stack;
        for (auto t : rpn)
        {
            if (t.first == Token::Num)
            {
                stack.push_back(t.second);
            }
            else
            {
                int n1 = stack.back(); stack.pop_back(); // denominator
                int n2 = stack.back(); stack.pop_back(); // numerator
                int result = 0;
                if      (t.first == Token::Add) result = n2 + n1;
                else if (t.first == Token::Sub) result = n2 - n1;
                else if (t.first == Token::Div) result = n2 / n1;
                else if (t.first == Token::Mul) result = n2 * n1;

                stack.push_back(result);
            }
        }
        return stack.back();
    }

    int calculate(string s)
    {
        auto tokens = toTokens(s);
        auto rpn = toRPN(tokens);
        auto result = evalRPN(rpn);
        return result;
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
    /* string s = "3+2*2"; */
    /* string s = " 3+5 / 2 "; */
    /* string s = " 3/2 "; */
    string s = "2147483647";
    Solution sol;
    auto r = sol.calculate(s);
    cout << r << endl;
    return 0;
}
