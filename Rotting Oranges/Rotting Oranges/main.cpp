/**
 * Runtime: 8 ms, faster than 60.45% of C++ online submissions for Rotting Oranges.
 * Memory Usage: 13.4 MB, less than 30.11% of C++ online submissions for Rotting Oranges.
 */

#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    
    struct cell {
        int x;
        int y;
        int time;
    };
    
    int orangesRotting(vector<vector<int>>& grid) {
        int dx[4] = {0, -1, 1, 0};
        int dy[4] = {-1, 0, 0, 1};
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<cell> q;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push({j, i, 0});
                    // queue에 넣을때 visited check!
                    visited[i][j] = true;
                }
            }
        }
        
        int time = 0;
        while (!q.empty())
        {
            // front()와 pop()은 짝으로 다님
            cell t = q.front();
            q.pop();
            
            time = max(time, t.time);
            for (int i = 0; i < 4; i++)
            {
                int x = t.x + dx[i];
                int y = t.y + dy[i];
                if (x >= 0 && x < n && y >= 0 && y < m && grid[y][x] == 1 && !visited[y][x])
                {
                    q.push({x, y, t.time + 1});
                    visited[y][x] = true;
                    grid[y][x] = 2;
                }
            }
        }
        
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    return -1;
                }
            }
        }
        
        return time;
    }
};

int main()
{
    return 0;
}
