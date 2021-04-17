/**
 * Runtime: 184 ms, faster than 98.41% of C++ online submissions for Sliding Window Maximum.
 * Memory Usage: 133.8 MB, less than 31.96% of C++ online submissions for Sliding Window Maximum.
 *
 * [Time Complexity]
 * O(n): Iterate input nums array three times to build up left, right, res vector
 * left, right vector keeps max value at corresponding window.
 *
 * [Space Complexity]
 * O(n): res, left, right vector occupies theta(n) spaces respectively
 *
 * [Algorithm]
 * 1. Divide input array with window size
 * 2. Build left & right array which keeps max value at divided window from left or right
 * 3. Calculate max value with: res[i] = max(right[i], left[i + k - 1]);
 *  - current window must intersect with divided window or same as divided window
 *  - max(right[i], left[i + k - 1]) gives max value of either side which is divided by (1)
 */

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        
        vector<int> res(n - k + 1, 0);
        vector<int> left(n, -987654321);
        vector<int> right(n, -987654321);
        
        int wMax;
        for (int i = 0; i < n; i++)
        {
            if (i % k == 0) wMax = nums[i];
            if (nums[i] > wMax) wMax = nums[i];
            left[i] = wMax;
        }
        
        wMax = nums[n - 1];
        for (int i = n - 1; i > 0; i--)
        {
            if ((i + 1) % k == 0) wMax = nums[i];
            if (nums[i] > wMax) wMax = nums[i];
            right[i] = wMax;
        }
        
        for (int i = 0; i < n - k + 1; i++)
        {
            res[i] = max(right[i], left[i + k - 1]);
        }
        return res;
    }
};
