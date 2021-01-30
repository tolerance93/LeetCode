#include <iostream>
#include <vector>
/**
 * Runtime: 16 ms, faster than 100.00% of C++ online submissions for Maximal Rectangle.
 * Memory Usage: 10.9 MB, less than 97.06% of C++ online submissions for Maximal Rectangle.
 *
 *  [Time Complexity]
 *  O(n * m) where n, m are input matrix's number of rows and columns respectively
 *  Precisely, ~ 2nm
 *
 *  [Space Complexity]
 *  O(m)
 *  Precisely, ~3m
 *
 *  [Algorithm]
 *  Let block be a candidate rectangle with max height at current position.
 *  variables explanined below contain prior row's information.
 *  update variable row by row.
 *
 *  height[i] denotes number of consecutive 1's destined upward. namely block's height.
 *  left[i] denotes left boundary of current block.
 *  right[i] denotes right boundary of current block.
 *
 *  check all blocks to update answer rectangle.
 */
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int nRow = matrix.size();
        if (nRow == 0) return 0;
        int nCol = matrix[0].size();
        int res = 0;
        
        int height[nCol];
        int left[nCol];
        int right[nCol];
        
        for (int i = 0; i < nCol; i++)
        {
            height[i] = 0;
            left[i] = 0;
            right[i] = nCol;
        }
        
        for (int row = 0; row < nRow; row++)
        {
            int curLeft = 0;
            for (int col = 0; col < nCol; col++)
            {
                if (matrix[row][col] == '1')
                {
                    height[col]++;
                    left[col] = max(left[col], curLeft);
                }
                else
                {
                    height[col] = 0;
                    curLeft = col + 1;
                    left[col] = 0;
                }
            }
            
            int curRight = nCol;
            for (int col = nCol - 1; col >= 0; col--)
            {
                if (matrix[row][col] == '1')
                {
                    right[col] = min(right[col], curRight);
                    res = max(res, (right[col] - left[col]) * height[col]);
                }
                else
                {
                    curRight = col;
                    right[col] = nCol;
                }
            }
        }
        return res;
    }
};

int main()
{
    return 0;
}
