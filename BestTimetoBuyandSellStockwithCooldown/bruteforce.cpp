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

//time out
class Solution2 {
public:
    void recur(vector<int>& prices, int pos, int size, int sum, int buy)
    {
        if (pos >= size)
        {
            if (sum > res) res = sum;
            return;
        }
        if (buy != -1)
        {
            if (prices[pos] > prices[buy])
            {
                int profit = prices[pos] - prices[buy];
                recur(prices, pos + 2, size, sum + profit, -1);
                recur(prices, pos + 1, size, sum, buy);
            }
        }
        else
        {
            recur(prices, pos + 1, size, sum, pos);
            recur(prices, pos + 1, size, sum, -1);
        }
        
    }
    int maxProfit(vector<int>& prices) {
        recur(prices, 0, prices.size(), 0, -1);
        return res;
    }
private:
    int res;
};

int main()
{
    Solution sol;
    vector<int> input = {1,2,3,0,2};
    cout << sol.maxProfit(input) << endl;
}
