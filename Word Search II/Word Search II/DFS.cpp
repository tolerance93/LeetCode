/**
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions for Word Search II.
 * Memory Usage: 8.5 MB, less than 81.39% of C++ online submissions for Word Search II.
 */

#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <iostream>

using namespace std;

class Solution {
private:
    bool found;
    int nRow;
    int nCol;
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};
    
public:
    bool isInBoard(int x, int y)
    {
        if (x >= 0 && x < nCol && y >= 0 && y < nRow) return true;
        return false;
    }
    
    void dfs(int row, int col, int& idx, vector<vector<bool>>& visited, vector<string>& res, vector<vector<char>>& board, string& word)
    {
        if (idx > 10) return;
        if (idx == word.size() - 1)
        {
            if (!found)
            {
                res.push_back(word);
                found = true;
            }
            return;
        }
        
        visited[row][col] = true;
        idx++;
        for (int i = 0; i < 4; i++)
        {
            if (isInBoard(col + dx[i], row + dy[i]) &&
                !visited[row + dy[i]][col + dx[i]] &&
                board[row + dy[i]][col + dx[i]] == word[idx])
            {
                dfs(row + dy[i], col + dx[i], idx, visited, res, board, word);
            }
        }
        visited[row][col] = false;
        idx--;
    }
    
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        nRow = board.size();
        nCol = board[0].size();
        
        vector<string> res;
        
        for (int wordIdx = 0; wordIdx < words.size(); wordIdx++)
        {
            found = false;
            for (int row = 0; row < nRow; row++)
            {
                for (int col = 0; col < nCol; col++)
                {
                    if (board[row][col] == words[wordIdx][0])
                    {
                        int idx = 0;
                        vector<vector<bool>> visited(nRow, vector<bool>(nCol));
                        dfs(row, col, idx, visited, res, board, words[wordIdx]);
                    }
                    if (found) break;
                }
                if (found) break;
            }
        }
        return res;
    }
};

int main()
{
    vector<char> row_zero = {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'};
    vector<vector<char>> board;
    for (int i = 0 ; i < 12; i++)
    {
        board.push_back(row_zero);
    }
    
    vector<string> words = {"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
    Solution sol;
    vector<string> res = sol.findWords(board, words);
    
    for (auto s : res)
    {
        cout << s << endl;
    }
    return 0;
}
