/**
  * Runtime: 4 ms, faster than 98.86% of C++ online submissions for Trapping Rain Water.
  * Memory Usage: 14.5 MB, less than 51.93% of C++ online submissions for Trapping Rain Water.
  *
  * Time Complexity: O(n), n: number of elementes in input vector
  * - read input vector twice. From left to right and right to left
  *
  * Space Complexity: O(n)
  * - need additional array of size n to keep track of heightAfterRain
  *
  * algorithm
  * - heightAfterRain[i] = min(max(Height, 0...i), max(Height, (i + 1)..<n))
*/

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
