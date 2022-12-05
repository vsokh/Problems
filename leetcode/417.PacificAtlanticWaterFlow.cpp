
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    static constexpr int WHITE = 0;
    static constexpr int GREY = 1;
    static constexpr int BLACK = 2;

    bool pacific(vector<vector<int>>& heights, vector<vector<int>>& visited, int i, int m, int j, int n)
    {
        // go left/up
    }

    bool atlantic(vector<vector<int>>& heights, vector<vector<int>>& visited, int i, int m, int j, int n)
    {
        // go right/down
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> result;
        for (int i=0;i<m;++i){
            for (int j=0;j<n;++j){
                if (visited[i][j]) continue;

                if (pacific(heights, visited, i, m, j, n) && atlantic(heights, visited, i, m, j, n)){
                    result.push_back({i,j});
                }
            }
        }
    }
};

int main()
{
    return 0;
}
