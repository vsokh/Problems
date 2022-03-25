#include <iostream>
#include <vector>

using namespace std;

class Solution {

public:
    void dfs(vector<vector<int>>& grid, vector<vector<int>>& visited, int r, int c, int& m)
    {
        if (r >= grid.size() || c >= grid[0].size())
            return;
        if (visited[r][c])
            return;
        if (grid[r][c] == 0)
            return;
        ++m;
        visited[r][c]=1;
        dfs(grid, visited, r, c+1, m);
        dfs(grid, visited, r, c-1, m);
        dfs(grid, visited, r+1, c, m);
        dfs(grid, visited, r-1, c, m);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid)
    {
        int maxAreaOfIsland = 0;
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size()));
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                int currAreaOfIsland = 0;
                if (!visited[i][j] && grid[i][j] != 0) {
                    dfs(grid, visited, i, j, currAreaOfIsland);
                    maxAreaOfIsland = max(maxAreaOfIsland, currAreaOfIsland);
                }
            }
        }
        return maxAreaOfIsland;
    }
};

int main()
{
    vector<vector<int>> v = {
        {0,0,1,0,0,0,0,1,0,0,0,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,1,1,0,1,0,0,0,0,0,0,0,0},
        {0,1,0,0,1,1,0,0,1,0,1,0,0},
        {0,1,0,0,1,1,0,0,1,1,1,0,0},
        {0,0,0,0,0,0,0,0,0,0,1,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,0,0,0,0,0,0,1,1,0,0,0,0}};
    Solution s;
    cout << "Exptected: 6" << endl;
    cout << "Actual: " << s.maxAreaOfIsland(v) << endl;
    return 0;
}
