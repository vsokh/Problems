#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int minFallingPathSum(vector<vector<int>>& matrix, vector<vector<int>>& mem, int n, int i, int j)
    {
        if (i >= n || j < 0 || j >= n) {
            return INT_MAX;
        }

        if ((i + 1) == n && j >= 0 && j < n) {
            return matrix[i][j];
        }

        if (mem[i][j]) {
            return mem[i][j];
        }

        mem[i][j] = min({
            minFallingPathSum(matrix, mem, n, i + 1, j),     // down
            minFallingPathSum(matrix, mem, n, i + 1, j - 1), // down-left
            minFallingPathSum(matrix, mem, n, i + 1, j + 1)  // down-right
        }) + matrix[i][j];

        return mem[i][j];
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int minSum = INT_MAX;
        vector<vector<int>> mem(n, vector<int>(n));
        for (int j = 0; j < n; ++j) {
            minSum = min(minSum, minFallingPathSum(matrix, mem, n, 0, j));
        }
        return minSum;
    }
};

