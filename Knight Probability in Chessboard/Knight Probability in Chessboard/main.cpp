#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    
    int dx[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
    int dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
    
    bool isInBoard(int n, int row, int col)
    {
        if (row < 0 || row >= n) return false;
        if (col < 0 || col >= n) return false;
        return true;
    }
    
    double recurse(vector<vector<vector<double>>>& board, int n, int k, int row, int col)
    {
        if (k == 0)
        {
            board[row][col][k] = 1;
            return 1;
        }
        
        if (board[row][col][k] != 0) return board[row][col][k];
        else
        {
            double res = 0;
            for (int i = 0; i < 8; i++)
            {
                int curRow = row + dx[i];
                int curCol = col + dy[i];
                if (isInBoard(n, curRow, curCol))
                {
                    res += 0.125 * recurse(board, n, k - 1, curRow, curCol);
                }
            }
            board[row][col][k] = res;
        }
        return board[row][col][k];
    }
    
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double>>> board (n, vector<vector<double>>(n, vector<double>(k + 1, 0)));
        recurse(board, n, k, row, column);
        return board[row][column][k];
    }
};

int main()
{
    Solution sol;
    cout << sol.knightProbability(3, 2, 0, 0) << endl;
    return 0;
}
