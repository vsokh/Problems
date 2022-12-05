#include <iostream>
#include <vector>

using namespace std;

class Solution {
    constexpr int turnLeft = -1;
    constexpr int turnRight = 1;

public:
    void setBallsColumn(int& finalColumn, int row, int column, vector<vector<int>>& grid) {
        int moveTo = 0;
        int ok = true;

        if (grid[row][column] == turnLeft) {
            if (column == 0 && row != grid[0].size()-1) {
                ok = false;
            }

            if (grid[row][column+turnLeft] == turnRight) {
                ok = false;
            }

            moveTo = turnLeft;
        }

        if (grid[row][column] == turnRight) {
            if (column == grid.size()-1 && row != grid[0].size()-1) {
                ok = false;
            }

            if (grid[row][column+turnRight] == turnLeft) {
                ok = false;
            }

            moveTo = turnRight;
        }

        if (ok && column < grid.size()) {
            setBallsColumn(finalColumn, row+1, column + moveTo, grid);
            finalColumn = column;
        }
    }

    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int> answer(-1, grid.size());
        for (auto i : answer) {
            setBallsColumn(answer[i], 0, i, grid);
        }
        return answer;
    }
};

int main() {
    return 0;
}
