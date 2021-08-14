/**
 * Runtime: 476 ms, faster than 6.97% of C++ online submissions for Partition Equal Subset Sum.
 * Memory Usage: 17.9 MB, less than 32.87% of C++ online submissions for Partition Equal Subset Sum.
 */

#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        bool ans = false;
        
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
        }
        
        if (sum % 2 == 1) return false;
        
        int target = sum / 2;
        
        int m = nums.size();
        int dp[target + 1][m + 1];
        for (int i = 0; i <= target; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                dp[i][j] = 0;
            }
        }
        
        for (int j = m - 1; j >= 0; j--)
        {
            for (int i = target; i >= 0; i--)
            {
                if (i - nums[j] >= 0) dp[i][j] = max(dp[i][j + 1], dp[i - nums[j]][j + 1]);
                else dp[i][j] = dp[i][j + 1];
                if (i == nums[j]) dp[i][j] = max(dp[i][j], 1);
                
            }
        }
        return dp[target][0] > 0;
    }
};

int main()
{
    Solution sol;
    vector<int> input = {1,2,5};
    sol.canPartition(input);
    return 0;
}
