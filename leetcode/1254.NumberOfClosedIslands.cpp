#include <iostream>
#include <vector>

using namespace std;

using vvi = vector<vector<int>>;

class Solution {
public:
    bool dfs(vvi& grid, vvi& visited, int i, int j)
    {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size())
            return false;

        if (visited[i][j] == 1)
            return true;

        if (grid[i][j] == 0)
            visited[i][j] = 1;

        if (grid[i][j] == 1)
            return true;

        return dfs(grid, visited, i - 1, j) && // up
               dfs(grid, visited, i, j - 1) && // left
               dfs(grid, visited, i + 1, j) && // down
               dfs(grid, visited, i, j + 1);
    }

    int closedIsland(vvi& grid)
    {
        int closed = 0;
        vvi visited(grid.size(), vector<int>(grid[0].size()));
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {
                if (!visited[i][j] && grid[i][j] == 0)
                {
                    closed += dfs(grid, visited, i, j);
                }
            }
        }
        return closed;
    }
};

int main()
{
    Solution s;
    {
        vvi grid = {{1,1,1,1,1,1,1,0},
                    {1,0,0,0,0,1,1,0},
                    {1,0,1,0,1,1,1,0},
                    {1,0,0,0,0,1,0,1},
                    {1,1,1,1,1,1,1,0}};
        std::cout << s.closedIsland(grid) << std::endl;
    }
    {
        vvi grid = {{0,0,1,0,0},
                    {0,1,0,1,0},
                    {0,1,1,1,0}};
        std::cout << s.closedIsland(grid) << std::endl;
    }
    {
        vvi grid = {{0,0,1,1,0,1,0,0,1,0},
                    {1,1,0,1,1,0,1,1,1,0},
                    {1,0,1,1,1,0,0,1,1,0},
                    {0,1,1,0,0,0,0,1,0,1},
                    {0,0,0,0,0,0,1,1,1,0},
                    {0,1,0,1,0,1,0,1,1,1},
                    {1,0,1,0,1,1,0,0,0,1},
                    {1,1,1,1,1,1,0,0,0,0},
                    {1,1,1,0,0,1,0,1,0,1},
                    {1,1,1,0,1,1,0,1,1,0}};
        std::cout << s.closedIsland(grid) << std::endl;
    }
    return 0;
}
