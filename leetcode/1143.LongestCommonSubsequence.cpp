#include <vector>

mem:
    0 1 2
    a c e
0 a 0 0 0
1 b 0 0 0
2 c 0 0 0
3 d 0 0 0
4 e 0 0 2

[i,j] = len
[0,0] = 0
[1,1] = 1
[1,2] = 1

  /* a b c d e */
/* a 3 */
/* c   0 2 */
/* e       0 1 */

/* The result of the comparison: */
/* 1. Eq: down-right */
/* 2. NoEq: go back, then check separately right(i, j + 1) and down(i + 1, j) */

/* What value to store at map[i][j]? - We can store the amount of the previously plus current one mapped characters or zero. */
/* How to get the longest value? - When you met the end of any of the two strings - start backtracking, counting the total length. */

class Solution
{
public:
    int longestCommonSubsequence(vector<vector<int>>& mem, string s1, string s2, int i, int j, int N, int M, int len)
    {
        if (i >= N || j >= M) {
            return len;
        }

        // cout << s1[i] << " " << s2[j] << " : " << i<< "," <<j<< " "<<len << endl;

        if (mem[i][j] > len) {
            return mem[i][j];
        }

        if (s1[i] == s2[j]) {
            mem[i][j] = max(mem[i][j], longestCommonSubsequence(mem, s1, s2, i + 1, j + 1, N, M, len + 1));
        } else {
            mem[i][j] = max({mem[i][j], longestCommonSubsequence(mem, s1, s2, i, j + 1, N, M, len),
                                        longestCommonSubsequence(mem, s1, s2, i + 1, j, N, M, len)});
        }
        return mem[i][j];
    }

    int longestCommonSubsequence(string text1, string text2)
    {
        vector<vector<int>> mem(text1.size(), vector<int>(text2.size()));
        int len = longestCommonSubsequence(mem, text1, text2, 0, 0, text1.size(), text2.size(), 0);
        /* for (int i = 0; i < mem.size(); ++i) { */
        /*     for (int j = 0; j < mem[0].size(); ++j) { */
        /*         cout << mem[i][j] << " "; */
        /*     } */
        /*     cout << endl; */
        /* } */
        return len;
    }
};

int main()
{
    return 0;
}

