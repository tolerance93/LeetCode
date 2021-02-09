#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;
        
        int state_can_buy[n];
        int state_can_sell[n];
        int res = 0;
        
        state_can_buy[0] = 0;
        state_can_sell[0] = -prices[0];
        
        for (int i = 1; i < n; i++)
        {
            state_can_buy[i] = max(state_can_buy[i - 1], state_can_sell[i - 1] + prices[i]);
            state_can_sell[i] = max(state_can_sell[i - 1], state_can_buy[i - 1] - prices[i]);
        }
        res = max(res, state_can_buy[n - 1]);
        
        return res;
    }
};
