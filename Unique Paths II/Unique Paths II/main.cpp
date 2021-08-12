/**
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions for Unique Paths II.
 * Memory Usage: 7.9 MB, less than 31.81% of C++ online submissions for Unique Paths II.
 */

#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        vector<vector<int>> paths(m, vector<int>(n, 0));
        bool obstacleFound = false;
        
        for (int i = 0; i < m; i++)
        {
            if (obstacleGrid[i][0] == 1)
            {
                obstacleFound = true;
            }
            paths[i][0] = obstacleFound ? 0 : 1;
        }
        obstacleFound = false;
        for (int i = 0; i < n; i++)
        {
            if (obstacleGrid[0][i] == 1)
            {
                obstacleFound = true;
            }
            paths[0][i] = obstacleFound ? 0 : 1;
        }
        
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (obstacleGrid[i][j] == 1)
                {
                    paths[i][j] = 0;
                }
                else
                {
                    paths[i][j] = paths[i - 1][j] + paths[i][j - 1];
                }
            }
        }
        return paths[m - 1][n - 1];
    }
};

int main()
{
    return 0;
}
