class Solution {
public:
    int evalRPN(vector<string>& tokens)
    {
        vector<int> stack;
        for (auto t : tokens)
        {
            if ('0' <= t[0] && t[0] <= '9')
            {
                stack.push_back(stoi(t));
            }
            else
            {
                int n1 = stack.back(); stack.pop_back();
                int n2 = stack.back(); stack.pop_back();
                int result = 0;
                if      (t == "+") result = n2 + n1;
                else if (t == "-") result = n2 - n1;
                else if (t == "/") result = n2 / n1;
                else if (t == "*") result = n2 * n1;

                stack.push_back(result);
            }
        }
        return stack.back();
    }
};
