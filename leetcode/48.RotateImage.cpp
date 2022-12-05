#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/* Input:  [[1,2,3],[4,5,6],[7,8,9]] */
/* Output: [[7,4,1],[8,5,2],[9,6,3]] */

class Solution
{
public:
    void rotate(vector<vector<int>>& matrix, int i, int j, int n)
    {
        auto right = [](vector<vector<int>>& matrix, const vector<int>& v)
        {
            int i = v[0], j = v[1], num = v[2], n = v[3];
            j=j+n-1;
            cout << i << " " << j << endl;
            int nextNum = matrix[i][j];
            matrix[i][j] = num;
            return vector<int>{i,j,nextNum,n};
        };

        auto down = [](vector<vector<int>>& matrix, const vector<int>& v)
        {
            int i = v[0], j = v[1], num = v[2], n = v[3];
            i=i+n-1;
            cout << i << " " << j << endl;
            int nextNum = matrix[i][j];
            matrix[i][j] = num;
            return vector<int>{i,j,nextNum,n};
        };

        auto left = [](vector<vector<int>>& matrix, const vector<int>& v)
        {
            int i = v[0], j = v[1], num = v[2], n = v[3];
            j=j-n+1;
            cout << i << " " << j << endl;
            int nextNum = matrix[i][j];
            matrix[i][j] = num;
            return vector<int>{i,j,nextNum,n};
        };

        auto up = [](vector<vector<int>>& matrix, const vector<int>& v)
        {
            int i = v[0], j = v[1], num = v[2], n = v[3];
            i=i-n+1;
            cout << i << " " << j << endl;
            int nextNum = matrix[i][j];
            matrix[i][j] = num;
            return vector<int>{i,j,nextNum,n};
        };

        int num = matrix[i][j];
        up(matrix, left(matrix, down(matrix, right(matrix, vector<int>{i , j, num, n}))));
    }

    void rotate(vector<vector<int>>& matrix)
    {
        int n = matrix.size();
        int i = 0; int j = 0;
        for (auto cnt=0;cnt<n;++cnt){
            rotate(matrix, i, cnt, n);
        }
        /* while (n) */
        /* { */
        /*     ++i; ++j; n /= 2; */
        /* } */
    }
};

int main() {
    auto print = [](vector<vector<int>>& v)
    {
        for (auto i=0; i<v.size();++i) {
            for (auto j=0; j<v.size();++j) {
                cout << v[i][j] << " \n"[j==v.size()-1];
            }
        }
    };
    vector<vector<int>> v = {{1,2,3},{4,5,6},{7,8,9}};
    print(v);
    cout << "\n";
    Solution{}.rotate(v);
    print(v);
    return 0;
}
