/**
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions for Spiral Matrix.
 * Memory Usage: 6.9 MB, less than 67.61% of C++ online submissions for Spiral Matrix.
 */

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int m = matrix.size();
        if (m == 0) return ans;
        int n = matrix[0].size();
        if (n == 0) return ans;
        
        int sr = 0, er = m - 1, sc = 0, ec = n - 1;
        int count = 0;
        
        while (sr <= er && sc <= ec)
        {
            for (int i = sc; i <= ec; i++)
            {
                ans.push_back(matrix[sr][i]);
                count++;
            }
            sr++;
            if (count == m * n) return ans;
            
            for (int i = sr; i <= er; i++)
            {
                ans.push_back(matrix[i][ec]);
                count++;
            }
            ec--;
            
            for (int i = ec; i >= sc; i--)
            {
                ans.push_back(matrix[er][i]);
                count++;
            }
            er--;
            if (count == m * n) return ans;
            
            for (int i = er; i >= sr; i--)
            {
                ans.push_back(matrix[i][sc]);
                count++;
            }
            sc++;
            if (count == m * n) return ans;
        }
        return ans;
    }
};
