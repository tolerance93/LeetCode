/**
 * Runtime: 100 ms, faster than 49.62% of C++ online submissions for Largest Rectangle in Histogram.
 * Memory Usage: 62.4 MB, less than 34.21% of C++ online submissions for Largest Rectangle in Histogram.
 */

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        if (n == 0) return 0;
    
        vector<int> leftEnd(n, 0);
        leftEnd[0] = -1;
        
        for (int i = 1; i < n; i++)
        {
            int j =  i - 1;
            while (j >= 0 && heights[j] >= heights[i])
            {
                j = leftEnd[j];
            }
            leftEnd[i] = j;
        }
        
        vector<int> rightEnd(n, 0);
        rightEnd[n - 1] = n;
        
        for (int i = n - 2; i >= 0; i--)
        {
            int j = i + 1;
            while (j < n && heights[i] <= heights[j])
            {
                j = rightEnd[j];
            }
            rightEnd[i] = j;
        }
        
        int res = 0;
        
        for (int i = 0; i < n; i++)
        {
            res = max(res, heights[i] * (rightEnd[i] - leftEnd[i] - 1));
        }
        
        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> input = { 2,1,5,6,2,3 };
    cout << sol.largestRectangleArea(input) << endl;
}
