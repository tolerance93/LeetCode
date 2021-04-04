/**
 * Runtime: 288 ms, faster than 11.79% of C++ online submissions for Cherry Pickup.
 * Memory Usage: 38.6 MB, less than 18.08% of C++ online submissions for Cherry Pickup.
 *
 * [Time Complexity]
 * O(n^4): need to figure out all element of dp[n][n][n][n]
 *
 * [Space Complexity]
 * O(n^4) need to figure out all element of dp[n][n][n][n]
 */

#include <vector>

using namespace std;

class Solution {
private:
    int dp[51][51][51][51];
public:

    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int k = 0; k < n; k++)
                {
                    for (int l = 0; l < n; l++)
                    {
                        dp[i][j][k][l] = -987654321;
                    }
                }
            }
        }
        return max(0, cherryPickup(grid, n, 0, 0, 0, 0));
    }
    
    int cherryPickup(vector<vector<int>>& grid, int n, int r1, int c1, int r2, int c2)
    {
        if (r1 >= n || c1 >= n || r2 >= n || c2 >= n || grid[r1][c1] == -1 || grid[r2][c2] == -1)
        {
            return -987654321;
        }
        
        if (dp[r1][c1][r2][c2] != -987654321)
        {
            return dp[r1][c1][r2][c2];
        }
        
        if (r1 == n - 1 && c1 == n - 1)
        {
            return grid[r1][c1];
        }
        
        if (r2 == n - 1 && c2 == n - 1)
        {
            return grid[r2][c2];
        }
        
        int cherries;
        
        if (r1 == r2 && c1 == c2)
        {
            cherries = grid[r1][c1];
        }
        else
        {
            cherries = grid[r1][c1] + grid[r2][c2];
        }
        
        cherries += max(
                        max(cherryPickup(grid, n, r1 + 1, c1, r2 + 1, c2), cherryPickup(grid, n, r1 + 1, c1, r2, c2 + 1)),
                        max(cherryPickup(grid, n, r1, c1 + 1, r2 + 1, c2), cherryPickup(grid, n, r1, c1 + 1, r2, c2 + 1))
                        );
        dp[r1][c1][r2][c2] = cherries;
        return dp[r1][c1][r2][c2];
    }
};
