/**
 * Runtime: 120 ms, faster than 98.39% of C++ online submissions for Word Search.
 * Memory Usage: 7.9 MB, less than 74.54% of C++ online submissions for Word Search.
 */

#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool found;
    
    void bfs(vector<vector<char>>& board, string word, int row, int col, int cur)
    {
        if (cur == word.size())
        {
            found = true;
            return;
        }
        
        if (row < 0 || row >= board.size()) return;
        if (col < 0 || col >= board[0].size()) return;
        if (board[row][col] != word[cur]) return;
        
        char c = board[row][col];
        board[row][col] = '*';
        
        bfs(board, word, row - 1, col, cur + 1);
        bfs(board, word, row , col - 1, cur + 1);
        bfs(board, word, row + 1, col, cur + 1);
        bfs(board, word, row, col + 1, cur + 1);
        
        board[row][col] = c;
    }
    
    
    bool exist(vector<vector<char>>& board, string word) {
        int row = (int) board.size();
        int col = (int) board[0].size();
        
        unordered_set<char> set;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (set.find(board[i][j]) == set.end())
                {
                    set.insert(board[i][j]);
                }
            }
        }
        
        for (int i = 0; i < word.size(); i++)
        {
            if (set.find(word[i]) == set.end()) return false;
        }
        
        found = false;
        
        for (int r = 0; r < row; r++)
        {
            for (int c = 0; c < col; c++)
            {
                if (board[r][c] == word[0])
                {
                    bfs(board, word, r, c, 0);
                    if (found) return true;
                }
            }
        }
        return found;
    }
};

class Solution2
{
    bool exist(vector<vector<char>>& board, string word) {
        for (unsigned int i = 0; i < board.size(); i++)
            for (unsigned int j = 0; j < board[0].size(); j++)
                if (dfs(board, i, j, word))
                    return true;
        return false;
    }

    bool dfs(vector<vector<char>>& board, int i, int j, string& word) {
        if (!word.size())
            return true;
        if (i<0 || i>=board.size() || j<0 || j>=board[0].size() || board[i][j] != word[0])
            return false;
        char c = board[i][j];
        board[i][j] = '*';
        string s = word.substr(1);
        bool ret = dfs(board, i-1, j, s) || dfs(board, i+1, j, s) || dfs(board, i, j-1, s) || dfs(board, i, j+1, s);
        board[i][j] = c;
        return ret;
    }
};

int main()
{
    return 0;
}
