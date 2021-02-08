/**
 * Runtime: 128 ms, faster than 90.53% of C++ online submissions for Best Time to Buy and Sell Stock III.
 * Memory Usage: 78.4 MB, less than 49.45% of C++ online submissions for Best Time to Buy and Sell Stock III.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;
        
        vector<int> maxArray(n);
        int maxValue = 0;
        int maxPos = n - 1;
        maxArray[n - 1] = 0;
        
        int minPos = 0;
        
        for (int i = n - 2; i >= 0; i--)
        {
            if (prices[i] > prices[maxPos]) maxPos = i;
            maxValue = max(maxValue, prices[maxPos] - prices[i]);
            maxArray[i] = maxValue;
        }
        
        maxValue = 0;
        int res = 0;
        
        for (int i = 0; i < n - 1; i++)
        {
            if (prices[i] < prices[minPos]) minPos = i;
            maxValue = max(maxValue, prices[i] - prices[minPos]);
            maxArray[i + 1] += maxValue;
            res = max(res, maxArray[i]);
        }
        
        res = max(res, maxArray[n - 1]);
        return res;
    }
};


int main()
{
    vector<int> input = {3,3,5,0,0,3,1,4};
    Solution sol;
    cout << sol.maxProfit(input) << endl;
    
}
