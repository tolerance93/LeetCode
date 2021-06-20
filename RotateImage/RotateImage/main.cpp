/**
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions for Rotate Image.
 * Memory Usage: 7 MB, less than 71.50% of C++ online submissions for Rotate Image.
 */

#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int cur_len = n;
        
        for (int pos = 0; pos < n / 2; pos++)
        {
            for (int i = 0; i < cur_len - 1; i++)
            {
                int temp = matrix[pos][pos + i];
                matrix[pos][pos + i] = matrix[pos + cur_len - 1 - i][pos];
                matrix[pos + cur_len - 1 - i][pos] = matrix[pos + cur_len - 1][pos + cur_len - 1 - i];
                matrix[pos + cur_len - 1][pos + cur_len - 1 - i] = matrix[pos + i][pos + cur_len - 1];
                matrix[pos + i][pos + cur_len - 1] = temp;
            }
            cur_len -= 2;
        }
    }
};
