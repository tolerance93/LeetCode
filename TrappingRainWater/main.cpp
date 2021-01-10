#include "vector"
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() == 0) return 0;
        int n = height.size();
        int heightAfterRain[n];
        int curMax = 0;
        int res = 0;
        
        for (int i = 0; i < n; i++)
        {
            if (height[i] > curMax) curMax = height[i];
            heightAfterRain[i] = curMax;
        }
        
        curMax = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (height[i] > curMax) curMax = height[i];
            heightAfterRain[i] = curMax > heightAfterRain[i] ? heightAfterRain[i] : curMax;
            res += heightAfterRain[i] - height[i];
        }
        return res;
    }
};
