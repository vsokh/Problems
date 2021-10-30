#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int clr, int newColor)
    {
        if (sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size())
            return;
        if (image[sr][sc] != clr)
            return;

        image[sr][sc]=newColor;
        floodFill(image, sr-1, sc, clr, newColor);
        floodFill(image, sr, sc-1, clr, newColor);
        floodFill(image, sr+1, sc, clr, newColor);
        floodFill(image, sr, sc+1, clr, newColor);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if (image[sr][sc]!=newColor)
            dfs(image, sr, sc, image[sr][sc], newColor);
        return image;
    }
};

int main()
{
    return 0;
}
