#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> split(string s)
    {
        vector<string> v;
        do {
            auto wsp = find(s.begin(), s.end(), ' ');
            v.emplace_back(string{s.begin(), wsp});

            s.erase(s.begin(), wsp == s.end() ? s.end() : wsp+1);
        } while(!s.empty());
        return v;
    }

    string reverse(string s)
    {
        auto b = s.begin();
        auto e = s.end()-1;
        while (b < e)
        {
            swap(*b, *e);
            ++b; --e;
        }
        return s;
    }

    string reverseWords(string s)
    {
        string result;

        auto v = split(s);
        auto sz = v.size();

        for (size_t i = 0; i < sz; ++i)
        {
            result += reverse(v[i]) + (i + 1 != sz ? " " : "");
        }
        return result;
    }
};

int main()
{

	Solution s;
	string ss = "Let's take LeetCode contest";
	auto sss = s.reverseWords(ss);

	return 0;
}
