/**
 * Runtime: 64 ms, faster than 74.73% of C++ online submissions for Coin Change.
 * Memory Usage: 9.9 MB, less than 95.68% of C++ online submissions for Coin Change.
 *
 * res[]에 저장된 모든 값을 볼 필요없이, 코인의 값을 이용하여, 가능한 위치만 조사할 수 있다.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int dp[10001];
        
        for (int i = 0; i < amount + 1; i++)
        {
            dp[i] = 987654321;
        }
        
        dp[0] = 0;
        
        for (int i = 0; i < coins.size(); i++)
        {
            if (coins[i] <= amount) dp[coins[i]] = 1;
        }
        
        for (int i = 1; i <= amount; i++)
        {
            for (int j = 0; j < coins.size(); j++)
            {
                if (dp[i] == 1) continue;
                if (i - coins[j] < 0) continue;
                dp[i] = dp[i] > dp[i - coins[j]] + 1 ? dp[i - coins[j]] + 1 : dp[i];
            }
        }
        if (dp[amount] == 987654321) return -1;
        else return dp[amount];
    }
};
