/**
 * Runtime: 12 ms, faster than 95.25% of C++ online submissions for Longest Increasing Subsequence.
 * Memory Usage: 10.6 MB, less than 93.84% of C++ online submissions for Longest Increasing Subsequence.
 */

class Solution
{
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int* tail = new int[n];
        for (int i = 0; i < n; i++)
        {
            tail[i] = 987654321;
        }
        
        int size = 0;
        
        for (int i = 0; i < n; i++)
        {
            int start = 0;
            int end = size;
            int m = 0;
            while (start < end)
            {
                m = (start + end) / 2;
                if (nums[i] <= tail[m])
                {
                    end = m;
                }
                else
                {
                    start = m + 1;
                }
            }
            tail[start] = nums[i];
            if (start == size) size++;
        }
        delete[] tail;
        return size;
    }
};
