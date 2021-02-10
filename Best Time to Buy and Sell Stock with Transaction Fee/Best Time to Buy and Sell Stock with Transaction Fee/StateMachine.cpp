/**
 * Runtime: 88 ms, faster than 93.42% of C++ online submissions for Best Time to Buy and Sell Stock with Transaction Fee.
 * Memory Usage: 55.3 MB, less than 66.79% of C++ online submissions for Best Time to Buy and Sell Stock with
 * Transaction Fee.
 */

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

int main()
{
    vector<int> input = {7,1,5,3,6,4};
    Solution sol;
    cout <<sol.maxProfit(input) << endl;
    return 0;
}
