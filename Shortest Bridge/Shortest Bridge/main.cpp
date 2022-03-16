/**
 * Runtime: 48 ms, faster than 85.02% of C++ online submissions for Shortest Bridge.
 * Memory Usage: 18.4 MB, less than 90.26% of C++ online submissions for Shortest Bridge.
 */

#include <vector>
#include <queue>
#include <utility>
#include <iostream>

using namespace std;

class Solution {
public:
    
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};
    
    bool isInBoard(int x, int y, int n)
    {
        if (x < 0 || x >= n) return false;
        if (y < 0 || y >= n) return false;
        return true;
    }
    
    void dfs(int x, int y, queue<pair<int, int>>& boundary, vector<vector<int>>& grid, int n)
    {
        grid[y][x] = 2;
        for (int i = 0; i < 4; i++)
        {
            if (isInBoard(x + dx[i], y + dy[i], n) && grid[y + dy[i]][x + dx[i]] == 0)
            {
                boundary.push(pair(y, x));
                break;
            }
        }
        
        for (int i = 0; i < 4; i++)
        {
            if (isInBoard(x + dx[i], y + dy[i], n) && grid[y + dy[i]][x + dx[i]] == 1)
            {
                dfs(x + dx[i], y + dy[i], boundary, grid, n);
            }
        }
    }
    
    int shortestBridge(vector<vector<int>>& grid) {
        int n = (int) grid.size();
        queue<pair<int,int>> boundary;
        int ans = 0;
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    dfs(j, i, boundary, grid, n);
                    i = n;
                    j = n;
                    
                }
            }
        }
        
        pair<int, int> level = {-1, -1};
        boundary.push({-1, -1});
        while (!boundary.empty())
        {
            pair<int, int> cur = boundary.front();
            boundary.pop();
            
            if (cur.first == -1 && cur.second == -1)
            {
                boundary.push(level);
                ans += 1;
                continue;;
            }
            
            for (int i = 0; i < 4; i++)
            {
                int nextX = cur.second + dx[i];
                int nextY = cur.first + dy[i];
                if (isInBoard(nextX, nextY, n))
                {
                    if (grid[nextY][nextX] == 1) return ans;
                    else if (grid[nextY][nextX] == 0)
                    {
                        grid[nextY][nextX] = 2;
                        boundary.push({nextY, nextX});
                    }
                }
            }
        }
        return ans;
    }
};

int main()
{
    //[[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]
    vector<vector<int>> input;
    input.push_back({1,1,1,1,1});
    input.push_back({1,0,0,0,1});
    input.push_back({1,0,1,0,1});
    input.push_back({1,0,0,0,1});
    input.push_back({1,1,1,1,1});
    Solution sol;
    cout << sol.shortestBridge(input) << endl;
    return 0;
}
