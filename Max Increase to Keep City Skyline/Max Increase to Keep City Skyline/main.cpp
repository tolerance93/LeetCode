/**
 * Runtime: 8 ms, faster than 74.27% of C++ online submissions for Max Increase to Keep City Skyline.
 * Memory Usage: 10.1 MB, less than 24.71% of C++ online submissions for Max Increase to Keep City Skyline.
 */

#include <vector>

using namespace std;

class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size();
        
        int ans = 0;
        vector<int> horizon(n, 0);
        vector<int> vertical(n, 0);
        for (int i = 0; i < n; i++)
        {
            int hor = 0;
            int ver = 0;
            for (int j = 0; j < n; j++)
            {
                hor = max(hor, grid[i][j]);
                ver = max(ver, grid[j][i]);
            }
            horizon[i] = hor;
            vertical[i] = ver;
        }
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                ans += min(horizon[i], vertical[j]) - grid[i][j];
            }
        }
        
        return ans;
    }
};

int main()
{
    return 0;
}
