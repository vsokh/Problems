#include <iostream>
#include <vector>

using namespace std;

class Solution {

public:
    void dfs(vector<vector<int>>& grid, vector<vector<int>>& visited, int r, int c, int& m)
    {
        if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size())
            return;
        if (grid[r][c]==0)
            return;
        if (visited[r][c]==1)
            return;

        visited[r][c]=1; ++m;
        dfs(grid, visited, r-1, c, m);
        dfs(grid, visited, r, c-1, m);
        dfs(grid, visited, r+1, c, m);
        dfs(grid, visited, r, c+1, m);

    }

    int maxAreaOfIsland(vector<vector<int>>& grid)
    {
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size()));
        int m = 0;
        for (int r = 0; r < grid.size(); ++r)
        {
            for (int c = 0; c < grid[0].size(); ++c)
            {
                int tmp = 0;
                if (visited[r][c]==0)
                {
                    dfs(grid, visited, r, c, tmp);
                }
                m=max(m,tmp);
            }
        }
        return m;
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
