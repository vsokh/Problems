#include <__nullptr>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat)
    {
        vector<vector<int>> result(mat.size(), vector<int>(mat[0].size()));
        for (int i = 0; i < mat.size(); ++i) {
            for (int j = 0; j < mat[0].size(); ++j) {
                if (!mat[i][j])
                    continue;

                int left = j - 1 >= mat[0].size() ? -1 : j - 1;
                int up = i - 1 >= mat.size() ? -1 : i - 1;

                if (left == -1)
                    left = up;

                if (up == -1)
                    up = left;

                result[i][j] = max(result[i][left], result[up][j]) + 1;
            }
        }
        return result;
    }
};

int main()
{
    return 0;
}
