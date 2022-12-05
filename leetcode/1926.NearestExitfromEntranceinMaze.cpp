#include <vector>
#include <iostream>
#include <queue>

using namespace std;

class Solution
{
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance)
    {
        init(maze, entrance);

        int minDist{INT_MAX};
        vector<vector<int>> visited(_rows, vector<int>(_columns));
        queue<vector<int>> q; q.push(vector<int>{entrance[0], entrance[1], 0});
        int currDist{0};
        while (!q.empty()) {
            auto pos = q.front(); q.pop();
            auto row = pos[0];
            auto column = pos[1];
            auto currDist = pos[2];

            std::cout << row << " " << column;
            if (outOfRange(row, column)) {
                std::cout << " => out\n";
                continue;
            }

            if (isWall(maze[row][column])) {
                std::cout << " => wall\n";
                continue;
            }

            if (visited[row][column]) {
                std::cout << " => visited\n";
                continue;
            } else {
                std::cout << " => new";
                visited[row][column] = 1;
            }

            if (isExit(maze[row][column], row, column)) {
                std::cout << " => exit\n";
                minDist = std::min(currDist, minDist);
                continue;
            } else {
                std::cout << std::endl;
            }

            q.push(vector<int>{row+1, column, currDist + 1});
            q.push(vector<int>{row-1, column, currDist + 1});
            q.push(vector<int>{row, column-1, currDist + 1});
            q.push(vector<int>{row, column+1, currDist + 1});
        }
        return minDist == INT_MAX ? -1 : minDist;
    }

private:
    void init(vector<vector<char>>& maze, vector<int>& entrance)
    {
        _rows = maze.size();
        _columns = maze[0].size();

        _eRow = entrance[0];
        _eColumn = entrance[1];
    }

    bool outOfRange(int row, int column)
    {
        return row < 0 || row >= _rows || column < 0 || column >= _columns;
    }

    /* void search(vector<vector<char>>& maze, vector<vector<int>>& visited, int row, int column, int currDist, int& minDist) */
    /* { */
    /*     side = 'u'; */
    /*     search(maze, visited, row-1, column, currDist+1, minDist); // up */
    /*     side = 'd'; */
    /*     search(maze, visited, row+1, column, currDist+1, minDist); // down */
    /*     side = 'r'; */
    /*     search(maze, visited, row, column+1, currDist+1, minDist); // right */
    /*     side = 'l'; */
    /*     search(maze, visited, row, column-1, currDist+1, minDist); // left */
    /* } */

    bool isWall(char symb)
    {
        return symb == '+';
    }

    bool isExit(char symb, int row, int column)
    {
        if (row == _eRow && column == _eColumn) { // check on || (or)
            return false;
        }

        if (symb != '.') {
            return false;
        }

        return row == 0 || row == _rows-1 || column == 0 || column == _columns-1;
    }

private:
    int _rows{0};
    int _columns{0};

    int _eRow{0};
    int _eColumn{0};
};


int main()
{
    Solution s;
    vector<vector<char>> maze {
        {'+','.','+','+','+','+','+'},
        {'+','.','+','.','.','.','+'},
        {'+','.','+','.','+','.','+'},
        {'+','.','.','.','.','.','+'},
        {'+','+','+','+','.','+','.'}};

        // #_#####
        // #.#...#
        // #.#.#.#
        // #.....#
        // ####.#.
        //
    vector<int> entrance{0,1};
    std::cout << s.nearestExit(maze, entrance) << std::endl;
    return 0;
}
