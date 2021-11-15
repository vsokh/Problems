
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        if (r*c > mat.size()*mat[0].size())
            return mat;

        vector<int> tmp(r*c);
		for (int i = 0; i < mat.size(); ++i)
			for (int j = 0; j < mat[0].size(); ++j)
				tmp[(i * mat.size())+j] = mat[i][j];

        vector<vector<int>> res(r, vector<int>(c));
		for (int i = 0; i < res.size(); ++i)
			for (int j = 0; j < res[0].size(); ++j)
				res[i][j] = tmp[(i * res.size())+j];
        return res;
    }
};


int main() {
	Solution s;
	{
		vector<vector<int>> v = {{1,2},{3,4}};
		int r = 1, c = 4;
		for (auto& arr : s.matrixReshape(v, r, c))
		{
			for (auto& e : arr)
				cout << e << " ";
			cout << endl;
		}
	}
	{
		vector<vector<int>> v = {{1,2,3,4}};
		int r = 2, c = 2;
		for (auto& arr : s.matrixReshape(v, r, c))
		{
			for (auto& e : arr)
				cout << e << " ";
			cout << endl;
		}
	}
	{
		vector<vector<int>> v = {{1,2,3,4}};
		int r = 3, c = 2;
		for (auto& arr : s.matrixReshape(v, r, c))
		{
			for (auto& e : arr)
				cout << e << " ";
			cout << endl;
		}
	}
	return 0;
}
