#include <vector>
#include <unordered_set>
#include <iostream>

using namespace std;

class Solution {
public:
    bool done = false;
    
    int getGridNum(int row, int col)
    {
        if (row >=0 && row <= 2)
        {
            if (col >= 0 && col <=2) return 0;
            else if (col > 2 && col <= 5) return 1;
            else return 2;
        }
        else if (row > 2 && row <= 5)
        {
            if (col >= 0 && col <=2) return 3;
            else if (col > 2 && col <= 5) return 4;
            else return 5;
        }
        else
        {
            if (col >= 0 && col <=2) return 6;
            else if (col > 2 && col <= 5) return 7;
            else return 8;
        }
    }
    
    void backTrack(vector<vector<char>>& board, vector<unordered_set<char>>& rowSet, vector<unordered_set<char>>& colSet, vector<unordered_set<char>>& gridSet, int row, int col)
    {
        if (row == 9) done = true;
        if (done) return;
        if (col == 9) backTrack(board, rowSet, colSet, gridSet, row + 1, 0);
        
        if (board[row][col] == '.')
        {
            for (int i = 1; i <= 9; i++)
            {
                if (rowSet[row].find('0' + i) == rowSet[row].end() &&
                    colSet[col].find('0' + i) == colSet[col].end() &&
                    gridSet[getGridNum(row, col)].find('0' + i) == gridSet[getGridNum(row, col)].end())
                {
                    rowSet[row].insert('0' + i);
                    colSet[col].insert('0' + i);
                    gridSet[getGridNum(row, col)].insert('0' + i);
                    board[row][col] = '0' + i;
                    
                    if (col == 8)
                    {
                        backTrack(board, rowSet, colSet, gridSet, row + 1, 0);
                    }
                    else
                    {
                        backTrack(board, rowSet, colSet, gridSet, row, col + 1);
                    }
                    if (done) return;
                    
                    rowSet[row].erase('0' + i);
                    colSet[col].erase('0' + i);
                    gridSet[getGridNum(row, col)].erase('0' + i);
                    board[row][col] = '.';
                }
            }
        }
        else
        {
            if (col == 8)
            {
                backTrack(board, rowSet, colSet, gridSet, row + 1, 0);
            }
            else
            {
                backTrack(board, rowSet, colSet, gridSet, row, col + 1);
            }
        }
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> rowSet(9, unordered_set<char>());
        vector<unordered_set<char>> colSet(9, unordered_set<char>());
        vector<unordered_set<char>> gridSet(9, unordered_set<char>());
        
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != '.')
                {
                    rowSet[i].insert(board[i][j]);
                    colSet[j].insert(board[i][j]);
                    gridSet[getGridNum(i, j)].insert(board[i][j]);
                }
            }
        }
        
        backTrack(board, rowSet, colSet, gridSet, 0, 0);
    }
};

class Solution2
{
    bool check(vector<vector<char>> &board, int i, int j, char val)
    {
        int row = i - i%3, column = j - j%3;
        for(int x=0; x<9; x++) if(board[x][j] == val) return false;
        for(int y=0; y<9; y++) if(board[i][y] == val) return false;
        for(int x=0; x<3; x++)
        for(int y=0; y<3; y++)
            if(board[row+x][column+y] == val) return false;
        return true;
    }
    bool solveSudoku(vector<vector<char>> &board, int i, int j)
    {
        if(i==9) return true;
        if(j==9) return solveSudoku(board, i+1, 0);
        if(board[i][j] != '.') return solveSudoku(board, i, j+1);

        for(char c='1'; c<='9'; c++)
        {
            if(check(board, i, j, c))
            {
                board[i][j] = c;
                if(solveSudoku(board, i, j+1)) return true;
                board[i][j] = '.';
            }
        }
            
        return false;
    }
    
public:void solveSudoku(vector<vector<char>> &board)
    {
        solveSudoku(board, 0, 0);
    }
};

int main()
{
    vector<vector<char>> input;
    input.push_back({'5','3','.','.','7','.','.','.','.'});
    input.push_back({'6','.','.','1','9','5','.','.','.'});
    input.push_back({'.','9','8','.','.','.','.','6','.'});
    input.push_back({'8','.','.','.','6','.','.','.','3'});
    input.push_back({'4','.','.','8','.','3','.','.','1'});
    input.push_back({'7','.','.','.','2','.','.','.','6'});
    input.push_back({'.','6','.','.','.','.','2','8','.'});
    input.push_back({'.','.','.','4','1','9','.','.','5'});
    input.push_back({'.','.','.','.','8','.','.','7','9'});
    Solution sol;
    sol.solveSudoku(input);
    return 0;
}
