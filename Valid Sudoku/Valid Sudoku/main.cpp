/**
 * Runtime: 20 ms, faster than 76.39% of C++ online submissions for Valid Sudoku.
 * Memory Usage: 18.5 MB, less than 59.72% of C++ online submissions for Valid Sudoku.
 */

#include <vector>
#include <utility>

using namespace std;

class Solution {
public:
    
    void checkRows(vector<vector<char>>& board, bool& res)
    {
        for (int i = 0; i < 9; i++)
        {
            vector<bool> row(9, false);
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.') continue;
                if (row[board[i][j] - '1'])
                {
                    res = false;
                    return;
                }
                row[board[i][j] - '1'] = true;
            }
        }
    }
    
    void checkCols(vector<vector<char>>& board, bool& res)
    {
        for (int i = 0; i < 9; i++)
        {
            vector<bool> row(9, false);
            for (int j = 0; j < 9; j++)
            {
                if (board[j][i] == '.') continue;
                if (row[board[j][i] - '1'])
                {
                    res = false;
                    return;
                }
                row[board[j][i] - '1'] = true;
            }
        }
    }
    
    void checkSquare(vector<vector<char>>& board, vector<pair<int, int>>& squareStart, bool& res)
    {
        for (int i = 0; i < squareStart.size(); i++)
        {
            int sy = squareStart[i].first;
            int sx = squareStart[i].second;
            vector<bool> square(9, false);
            
            for (int dx = 0; dx < 3; dx++)
            {
                for (int dy = 0; dy < 3; dy++)
                {
                    if (board[sy + dy][sx + dx] == '.') continue;
                    if (square[board[sy + dy][sx + dx] - '1'])
                    {
                        res = false;
                        return;
                    }
                    square[board[sy + dy][sx + dx] - '1'] = true;
                }
            }
        }
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        bool res = true;
        vector<pair<int, int>> squareStart = {
            make_pair(0, 0),
            make_pair(0, 3),
            make_pair(0, 6),
            make_pair(3, 0),
            make_pair(3, 3),
            make_pair(3, 6),
            make_pair(6, 0),
            make_pair(6, 3),
            make_pair(6, 6),
        };
        
        checkRows(board, res);
        if (!res) return false;
        checkCols(board, res);
        if (!res) return false;
        checkSquare(board, squareStart, res);
        return res;
    }
};

int main()
{
    vector<vector<char>> input = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    Solution sol;
    sol.isValidSudoku(input);
    return 0;
}
