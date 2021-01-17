/**
 * Runtime: 196 ms, faster than 64.35% of C++ online submissions for Longest Increasing Subsequence.
 * Memory Usage: 10.6 MB, less than 94.85% of C++ online submissions for Longest Increasing Subsequence.
 */

#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return n;
        int* lis = new int[n];
        for (int i = 0; i < n; i++)
        {
            lis[i] = 0;
        }
        int res = 0;
        
        lis[n - 1] = 1;
        for (int i = n - 2; i >= 0; i--)
        {
            int curMax = 0;
            for (int j = i + 1; j < n; j++)
            {
                if (nums[j] > nums[i] && lis[j] > curMax) curMax = lis[j];
            }
            lis[i] = curMax + 1;
            res = lis[i] > res ? lis[i] : res;
        }
        delete[] lis;
        return res;
    }
};


