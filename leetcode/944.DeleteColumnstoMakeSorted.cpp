// abc
// bce
// cae

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int cols = strs.size();
        int cnt = 0;
        for (int i = 1; i < strs[0].size(); ++i) {
            for (int j = 0; j < strs.size(); ++j) {
                if (strs[j][i] < strs[j][i-1]) {
                    ++cnt;
                }
            }
        }
        return cnt;
    }
};
