/**
 * Runtime: 12 ms, faster than 79.31% of C++ online submissions for Number of Closed Islands.
 * Memory Usage: 9.8 MB, less than 29.39% of C++ online submissions for Number of Closed Islands.
 */

#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};
    
    void fillLand(vector<vector<int>>& grid, int y, int x)
    {
        if (y < 0 || y >= grid.size() || x < 0 || x >= grid[0].size())
        {
            return;
        }
        
        if (grid[y][x] == 1)
        {
            return;
        }
        
        if (grid[y][x] == 0)
        {
            grid[y][x] = 1;
        }
        
        for (int i = 0; i < 4; i++)
        {
            fillLand(grid, y + dy[i], x + dx[i]);
        }
    }
    
    void dfs(vector<vector<int>>& grid, int y, int x, vector<vector<bool>>& visited)
    {
        if (y < 0 || y >= grid.size() || x < 0 || x >= grid[0].size())
        {
            return;
        }
        
        if (grid[y][x] == 1)
        {
            return;
        }
        
        if (visited[y][x])
        {
            return;
        }
        
        visited[y][x] = true;
        for (int i = 0; i < 4; i++)
        {
            dfs(grid, y + dy[i], x + dx[i], visited);
        }
        
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // convert land to water
        for (int i = 0; i < m; i++)
        {
            if (grid[i][0] == 0)
            {
                fillLand(grid, i, 0);
            }
            if (grid[i][n - 1] == 0)
            {
                fillLand(grid, i, n - 1);
            }
        }
        
        for (int i = 0; i < n; i++)
        {
            if (grid[0][i] == 0)
            {
                fillLand(grid, 0, i);
            }
            if (grid[m - 1][i] == 0)
            {
                fillLand(grid, m - 1, i);
            }
        }
        
        
        // DFS
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int count = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 0 && !visited[i][j])
                {
                    dfs(grid, i, j, visited);
                    count++;
                }
            }
        }
        return count;
    }
};

int main()
{
    return 0;
}
