#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void floodFill(vector<vector<int>>& image, int i, int j, int newColor, int oldColor) {
        if (i >= image.size() || j >= image[0].size())
            return;
        if (image[i][j] != oldColor)
            return;
        if (image[i][j] == newColor)
            return;

        image[i][j] = newColor;
        floodFill(image, i, j + 1, newColor, oldColor);
        floodFill(image, i, j - 1, newColor, oldColor);
        floodFill(image, i - 1, j, newColor, oldColor);
        floodFill(image, i + 1, j, newColor, oldColor);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        floodFill(image, sr, sc, newColor, image[sr][sc]);
        return image;
    }
};

int main()
{
    return 0;
}
