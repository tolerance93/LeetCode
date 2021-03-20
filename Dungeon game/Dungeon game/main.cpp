/**
 * Runtime: 4 ms, faster than 98.99% of C++ online submissions for Dungeon Game.
 * Memory Usage: 8.8 MB, less than 86.42% of C++ online submissions for Dungeon Game.
 *
 * [Time Complexity]
 * O(MN) where M: # of input row, N: # of input col
 *
 * [Space Complexity]
 * O(MN). can be reduced O(N) because we only see last row value of hp[][]
 *
 * [Algorithm]
 * Iterate from end to start.
 * curHP <= 0: enough to go form this node to end with current node's value.
 * This means if player touches this node, it ensures that player can reach to the end with current value.
 * curHP > 0: player need at least curHP to reach to the end.
 * Player can only go to right and down, considering right and down of hp[][] is enough
 */

#include <vector>

using namespace std;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int row = dungeon.size();
        int col = dungeon[0].size();
        
        if (row == 0 || col == 0) return 1;
        
        int hp[row + 1][col + 1];
        for (int i = 0; i < row + 1; i++)
        {
            for (int j = 0; j < col + 1; j++)
            {
                hp[i][j] = 987654321;
            }
        }
        
        hp[row - 1][col] = 1;
        hp[row][col - 1] = 1;
        
        for (int i = row - 1; i >= 0; i--)
        {
            for (int j = col - 1; j >= 0; j--)
            {
                int curHP = min(hp[i + 1][j], hp[i][j + 1]) - dungeon[i][j];
                hp[i][j] = curHP <= 0 ? 1 : curHP;
            }
        }
        return hp[0][0];
    }
};
