#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution
{
public:
    bool exist(vector<vector<char>>& board, int i, int j, int k, vector<vector<int>> visited, string word)
    {
        if (word.size() == k) {
            return true;
        }

        if (i < 0 || board.size() <= i ||
            j < 0 || board[0].size() <= j) {
            return false;
        }

        if (visited[i][j]) {
            return false;
        }

        visited[i][j]=1;

        if (word[k] == board[i][j])
        {
            return exist(board, i + 1, j, k + 1, visited, word) ||
                   exist(board, i - 1, j, k + 1, visited, word) ||
                   exist(board, i, j + 1, k + 1, visited, word) ||
                   exist(board, i, j - 1, k + 1, visited, word);
        }
        return false;
    }

    bool exist(vector<vector<char>>& board, string word)
    {
        vector<vector<int>> visited(board.size(), vector<int>(board[0].size()));
        for (auto i = 0; i < board.size(); ++i) {
            for (auto j = 0; j < board[0].size(); ++j) {
                if (exist(board, i, j, 0, visited, word)) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main()
{
    Solution s;
    vector<vector<char>> v{
        {'A','A','A','A','A','A'},
        {'A','A','A','A','A','A'},
        {'A','A','A','A','A','A'},
        {'A','A','A','A','A','A'},
        {'A','A','A','A','A','A'},
        {'A','A','A','A','A','A'}};
    string word = "AAAAAAAAAAAAAAB";
    std::cout << s.exist(v, word) << std::endl;
    return 0;
}

