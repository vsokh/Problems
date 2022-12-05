#include <vector>

using namespace std;


class Solution {
public:
    void dfs(string s, int pos, int range, int& cnt)
    {
        auto tmp = s.substr(pos, range);
        if (tmp[0] <= '0' || '2' < tmp[0]) {
            return ;
        } else if ('6' < tmp[1]) {
            return ;
        } else {
            ++cnt;
        }

        dfs(s, pos+range, 1, cnt);
        dfs(s, pos+range, 2, cnt);

    }

    int numDecodings(string s) {
        int cnt=0;
        dfs(s, 0, 0, cnt);
        return cnt;
    }
};

int main()
{
    return 0;
}
