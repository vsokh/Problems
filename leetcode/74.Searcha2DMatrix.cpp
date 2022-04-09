#include <vector>
#include <vector>

using namespace std;
class Solution
{
public:
    int search(vector<int>& v, int target)
    {
        int l = 0;
        int r = v.size()-1;
        int mid = l + (r-l)/2;
        while (l < r)
        {
            int val = v[mid];
            if (val == target) {
                return mid;
            }
            if (target < val) {
                r = mid;
            } else {
                l = mid + 1;
            }
            mid = l + (r - l)/2;
        }
        return mid;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        vector<int> v;
        for (auto mat : matrix) {
            v.emplace_back(mat.back());
        }
        int row = search(v, target);
        int column = search(matrix[row], target);
        return matrix[row][column] == target;
    }
};

int main()
{
    return 0;
}
