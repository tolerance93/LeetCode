#include <iostream>
#include <vector>

using namespace std;

/**
 * Brute force: Time out
 */

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        if (n == 0) return 0;
        int res = 0;
        
        for (int i = 0; i < n; i++)
        {
            if (heights[i] > res) res = heights[i];
        }
        
        for (int i = 0; i < n; i++)
        {
            int width = 1;
            for (int j = i + 1; j < n; j++)
            {
                if (heights[j] >= heights[i]) width++;
                else break;
            }
            for (int j = i - 1; j >= 0; j--)
            {
                if (heights[j] >= heights[i]) width++;
                else break;
            }
            if (res < width * heights[i]) res = width * heights[i];
        }
        
        return res;
    }
};
