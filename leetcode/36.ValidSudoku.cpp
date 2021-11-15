#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isValid3x3(vector<vector<char>>& board, vector<char>& v, int r, int c, int er, int ec)
    {
		if (r < 0 || r >= er || c < 0 || c >= ec)
			return false;

		auto& elem = board[r][c];
		if (elem != '.' && elem != ',' && v[elem - 48] != 0)
			return false;

		v[elem - 48] = 1;

		return true && isValid3x3(board, v, r - 1, c, er, ec)
					&& isValid3x3(board, v, r, c - 1, er, ec)
					&& isValid3x3(board, v, r + 1, c, er, ec)
					&& isValid3x3(board, v, r, c + 1, er, ec);
    }

    bool isValidSudoku(vector<vector<char>>& board)
	{
		int n = 9;
		unordered_set<int> set;
        for (int i = 0; i < n; ++i)
        {
			for (int j = 0; j < n; ++j)
			{
				for (int k = 0; k < 9; ++k)
				{
					if (board[i][j] != '.' && set.find(board[i][j]) != set.end())
						return false;
					set.insert(board[i][j]);
				}
				set.clear();
			}
        }
        return true;
    }
};

int main() {
	Solution s;
	vector<vector<char>> board =
		{{'5','3','.','.','7','.','.','.','.'}
		,{'6','.','.','1','9','5','.','.','.'}
		,{'.','9','8','.','.','.','.','6','.'}
		,{'8','.','.','.','6','.','.','.','3'}
		,{'4','.','.','8','.','3','.','.','1'}
		,{'7','.','.','.','2','.','.','.','6'}
		,{'.','6','.','.','.','.','2','8','.'}
		,{'.','.','.','4','1','9','.','.','5'}
		,{'.','.','.','.','8','.','.','7','9'}};

	cout << s.isValidSudoku(board) << endl;
	return 0;
}
