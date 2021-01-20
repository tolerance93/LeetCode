#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;
        
        vector<int> canBuy(n, 0);
        vector<int> canSell(n, 0);
        vector<int> rest(n, 0);
        
        canBuy[0] = 0;
        canSell[0] = -prices[0];
        rest[0] = -987654321;
        
        for (int i = 1; i < n; i++)
        {
            canBuy[i] = max(canBuy[i - 1], rest[i - 1]);
            canSell[i] = max(canSell[i - 1], canBuy[i - 1] - prices[i]);
            rest[i] = canSell[i - 1] + prices[i];
        }
        return max(canBuy[n - 1], rest[n - 1]);
    }
};
