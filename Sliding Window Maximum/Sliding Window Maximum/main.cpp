/**
 * Runtime: 184 ms, faster than 98.41% of C++ online submissions for Sliding Window Maximum.
 * Memory Usage: 133.8 MB, less than 31.96% of C++ online submissions for Sliding Window Maximum.
 */

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        
        vector<int> res(n - k + 1, 0);
        vector<int> left(n, -98765421);
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
