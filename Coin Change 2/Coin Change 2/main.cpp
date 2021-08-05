/**
 * Runtime: 44 ms, faster than 21.05% of C++ online submissions for Coin Change 2.
 * Memory Usage: 18.4 MB, less than 30.52% of C++ online submissions for Coin Change 2.
 */

#include <vector>

using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        if (amount == 0) return 1;
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= amount; j++)
            {
                int up =  i > 0 ? dp[i - 1][j] : 0;
                int left = j - coins[i] > 0 ? dp[i][j - coins[i]] : 0;
                int adder = coins[i] == j ? 1 : 0;
                dp[i][j] = up + left + adder;
            }
        }
        return dp[n - 1][amount];
    }
};

int main()
{
    return 0;
}
