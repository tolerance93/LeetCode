/**
 * Runtime: 136 ms, faster than 20.04% of C++ online submissions for Best Time to Buy and Sell Stock.
 * Memory Usage: 97.2 MB, less than 5.01% of C++ online submissions for Best Time to Buy and Sell
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;
        vector<int> maxPositioins(n);
        maxPositioins[n - 1] = n - 1;
        int res = 0;
        
        for (int i = n - 2; i >= 0; i--)
        {
            if (prices[i] > prices[maxPositioins[i + 1]])
            {
                maxPositioins[i] = i;
            }
            else
            {
                maxPositioins[i] = maxPositioins[i + 1];
            }
            res = max(res, prices[maxPositioins[i]] - prices[i]);
        }
        return res;
    }
};
