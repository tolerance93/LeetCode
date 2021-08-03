/**
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions for Climbing Stairs.
 * Memory Usage: 5.9 MB, less than 81.32% of C++ online submissions for Climbing Stairs.
 */

class Solution {
public:
    int climbStairs(int n) {
        int dp[n + 1];
        dp[0] = 1;
        dp[1] = 1;
        
        for (int i = 2; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        
        return dp[n];
    }
};
