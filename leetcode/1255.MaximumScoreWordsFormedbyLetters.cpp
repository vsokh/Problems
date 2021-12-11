#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution
{

public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score)
    {
        using amt = int;
        using scr = int;
        unordered_map<char, pair<amt, scr>> um(score.size());
        for (int i = 0; i < score.size(); ++i)
        {
            um[i + 97] = {0, score[i]};
        }

        for (auto ch : letters)
        {
            um[ch] = {++um[ch].first, um[ch].second};
        }

        int s = 0;
        priority_queue<int, vector<int>, greater<int>> q;
        for (auto w : words)
        {
            s = 0;
            unordered_map<char, int> charsAmount;
            for (auto ch : w)
            {
                ++charsAmount[ch];
            }
            for (auto [ch, amt] : charsAmount)
            {
                auto it = um.find(ch);
                if (it == um.end() || it->second.first < amt)
                {
                    s = 0;
                    break;
                }
                else
                {
                    s += it->second.second * amt;
                }
            }
            q.push(s);
        }

        auto print = [](auto q)
        {
            while (!q.empty())
            {
                auto e = q.top(); q.pop();
                cout << e << " ";
            }
            cout << endl;
        };
        print(q);
        cout << q.size() << endl;

        return q.empty() ? 0 : q.top();
    }
};

int main()
{
	Solution s;
    auto words = vector<string>{"dog","cat","dad","good","cc"};
    auto letters = vector<char>{'a','a','c','d','d','d','g','o','o'};
    auto score = vector<int>{1,0,9,5,0,0,3,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0};
    cout << s.maxScoreWords(words, letters, score) << endl;
	return 0;
}
