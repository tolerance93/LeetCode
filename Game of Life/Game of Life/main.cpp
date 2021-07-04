/**
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions for Game of Life.
 * Memory Usage: 7 MB, less than 18.16% of C++ online submissions for Game of Life.
 */

#include "vector"

using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        m = board.size();
        n = board[0].size();
        
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                liveOrDie(board, i, j);
            }
        }
        
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                board[i][j] = board[i][j] >> 1;
            }
        }
    }
private:
    int m, n;
    
    void liveOrDie(vector<vector<int>>& board, int x, int y)
    {
        int count = 0;
        for (int cx = x - 1; cx < x + 2; cx++)
        {
            for (int cy = y - 1; cy < y + 2; cy++)
            {
                if (cx == x && cy == y) continue;
                if (isInBoard(cx, cy))
                {
                    if (board[cx][cy] & 1) count++;
                }
            }
        }
        if (board[x][y] & 1)
        {
            if (count < 2 || count > 3) board[x][y] = 1;
            else board[x][y] = 3;
        }
        else
        {
            if (count == 3) board[x][y] = 2;
        }
    }
    
    bool isInBoard(int x, int y)
    {
        if (x >= 0 && x < m && y >= 0 && y < n) return true;
        return false;
    }
};
