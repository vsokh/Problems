#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
	bool checkRows(vector<vector<char>>& board) {
		unordered_set<char> set;
		int rows = board.size();
		int columns = board[0].size();
		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < columns; ++j) {
				auto& num = board[i][j];
				if (num == '.') continue;

				if (auto it = set.find(num);
						it != set.end()) {
					return false;
				} else {
					set.insert(num);
				}
			}
			set.clear();
		}
		return true;
	}

	bool checkColumns(vector<vector<char>>& board) {
		unordered_set<char> set;
		int rows = board.size();
		int columns = board[0].size();
		for (int i = 0; i < columns; ++i) {
			for (int j = 0; j < rows; ++j) {
				auto& num = board[j][i];
				if (num == '.') {
					continue;
				}

				if (auto it = set.find(num);
						 it != set.end()) {
					return false;
				} else {
					set.insert(num);
				}
			}
			set.clear();
		}
		return true;
	}
	bool check3x3(vector<vector<char>>& board, int s, int e) {
		unordered_set<char> set;
		for (int i = s; i < s + 3; ++i) {
			for (int j = e; j < e + 3; ++j) {
				char num = board[i][j];
				if (num == '.') {
					continue;
				}

				auto it = set.find(num);
				if (it != set.end()) {
					return false;
				} else {
					set.insert(num);
				}
			}
		}
		return true;
	}

	bool checkEach3x3(vector<vector<char>>& board) {
		int rows = board.size();
		int columns = board[0].size();
		for (int i = 0; i < rows; i += 3) {
			for (int j = 0; j < columns; j += 3) {
				if (!check3x3(board, i, j)) {
					return false;
				}
			}
		}
		return true;
	}

	bool isValidSudoku(vector<vector<char>>& board) {
		bool r = checkRows(board);
		bool c = checkColumns(board);
		bool x = checkEach3x3(board);
		return r && c && x;
	}
};

int main() {
	Solution s;
	vector<vector<char>> board =
	{{'.','.','.','.','5','.','.','1','.'},
	 {'.','4','.','3','.','.','.','.','.'},
	 {'.','.','.','.','.','3','.','.','1'},
	 {'8','.','.','.','.','.','.','2','.'},
	 {'.','.','2','.','7','.','.','.','.'},
	 {'.','1','5','.','.','.','.','.','.'},
	 {'.','.','.','.','.','2','.','.','.'},
	 {'.','2','.','9','.','.','.','.','.'},
	 {'.','.','4','.','.','.','.','.','.'}};
	cout << s.isValidSudoku(board) << endl;

	return 0;
}
