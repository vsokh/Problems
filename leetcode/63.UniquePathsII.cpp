#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>>& obstacleGrid, int i, int j, int& up) {
        if (i > obstacleGrid.size()-1 || j > obstacleGrid[0].size()-1){
            return;
        }
        if (obstacleGrid[i][j]){
            return;
        }
        if (i == obstacleGrid.size()-1 && j == obstacleGrid[0].size()-1) {
            ++up; return;
        }
        dfs(obstacleGrid, i+1, j, up);
        dfs(obstacleGrid, i, j+1, up);

    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int up=0;
        dfs(obstacleGrid, 0, 0, up);
        return up;
    }
};

int main() {
	Solution s;
    vector<vector<int>> v{{0,0,0,0,0,1,0,1,0,0,0,0,1,0,0,0,0,0},{0,0,0,0,0,0,1,0,0,0,0,1,0,1,0,1,0,0},{1,0,0,0,0,0,1,0,0,0,0,0,1,0,1,1,0,1},{0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0},{0,0,0,0,0,1,0,0,0,0,1,1,0,1,0,0,0,0},{1,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0},{0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,0,0},{0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{1,1,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0},{0,0,1,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0},{0,1,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0},{0,0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,0,1},{0,1,0,1,0,1,0,0,0,0,0,0,0,1,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1},{1,0,1,1,0,0,0,0,0,0,1,0,1,0,0,0,1,0},{0,0,0,1,0,0,0,0,1,1,1,0,0,1,0,1,1,0},{0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,1,1,0,0,1,0,0,0,0,0,0,0,1,1,0,0,0},{0,0,0,0,0,0,1,0,1,0,0,1,0,1,1,1,0,0},{0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,1,1},{0,1,0,0,0,0,0,0,0,0,1,0,1,0,1,0,1,0},{1,0,0,1,0,1,0,0,1,0,0,0,0,0,0,0,0,0},{0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0},{0,1,0,0,0,0,0,1,0,0,0,0,0,0,1,1,1,0},{1,0,1,0,1,0,0,0,0,0,0,1,1,0,0,0,0,1},{1,0,0,0,0,0,1,1,0,0,0,1,0,0,0,0,0,0}};
    cout <<s.uniquePathsWithObstacles(v) << endl;
	return 0;
}
