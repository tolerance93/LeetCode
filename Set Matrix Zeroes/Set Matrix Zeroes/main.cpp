#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int nRow = matrix.size();
        int nCol = matrix[0].size();
        
        set<int> zeroRows;
        set<int> zeroCols;
        
        for (int row = 0; row < nRow; row++)
        {
            for (int col = 0; col < nCol; col++)
            {
                if (matrix[row][col] == 0)
                {
                    zeroRows.insert(row);
                    zeroCols.insert(col);
                }
            }
        }
        
        for (auto row : zeroRows)
        {
            for (int col = 0; col < nCol; col++)
            {
                matrix[row][col] = 0;
            }
        }
        
        for (auto col : zeroCols)
        {
            for (int row = 0; row < nRow; row++)
            {
                matrix[row][col] = 0;
            }
        }
    }
};
