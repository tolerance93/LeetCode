/**
 * Runtime: 16 ms, faster than 60.64% of C++ online submissions for Count Negative Numbers in a Sorted Matrix.
 * Memory Usage: 10.4 MB, less than 45.75% of C++ online submissions for Count Negative Numbers in a Sorted Matrix.
 */

#include <vector>

using namespace std;

class Solution {
public:
    
    int binarySearch(vector<int>& input)
    {
        int s = 0;
        int e = input.size() - 1;
        int mid;
        while (s < e)
        {
            int mid = (s + e) / 2;
            if (input[mid] >= 0) s = mid + 1;
            else if (input[mid] < 0) e = mid - 1;
        }
        return s;
    }
    
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int pos = binarySearch(grid[i]);
            if (grid[i][pos] < 0) ans += m - pos;
        }
        return ans;
    }
};

int main()
{
    return 0;
}
