#include <vector>
#include <iostream>

using namespace std;

//time out
class Solution {
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
