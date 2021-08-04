/**
 * Runtime: 16 ms, faster than 82.96% of C++ online submissions for Max Area of Island.
 * Memory Usage: 23.8 MB, less than 44.97% of C++ online submissions for Max Area of Island.
 */

#include <vector>

using namespace std;

class Solution {
public:
    
    void dfs(vector<vector<int>>& grid, int i, int j, vector<vector<bool>> &visited, int &area)
    {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size())
        {
            return;
        }
        
        if (grid[i][j] == 0)
        {
            return;
        }
        
        if (visited[i][j])
        {
            return;
        }
        
        visited[i][j] = true;
        area++;
        dfs(grid, i + 1, j, visited, area);
        dfs(grid, i - 1, j, visited, area);
        dfs(grid, i, j + 1, visited, area);
        dfs(grid, i, j - 1, visited, area);
        
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int maxArea = 0;
        
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1 && !visited[i][j])
                {
                    int area = 0;
                    dfs(grid, i, j, visited, area);
                    maxArea = max(maxArea, area);
                }
            }
        }
        return maxArea;
    }
};
