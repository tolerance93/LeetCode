/**
 * Runtime: 8 ms, faster than 34.09% of C++ online submissions for Wiggle Subsequence.
 * Memory Usage: 7.3 MB, less than 32.63% of C++ online submissions for Wiggle Subsequence.
 *
 * Time Complexity: O(n^2)
 * Space Complexity: O(n)
 */

#include <vector>

using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = (int) nums.size();
        vector<int> biggerThanBefore = vector<int>(n, 1);
        vector<int> smallerThanBefore = vector<int>(n, 1);
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j])
                {
                    biggerThanBefore[i] = max(smallerThanBefore[j] + 1, biggerThanBefore[i]);
                }
                else if (nums[i] < nums[j])
                {
                    smallerThanBefore[i] = max(biggerThanBefore[j] + 1, smallerThanBefore[i]);
                }
            }
        }
        return max(biggerThanBefore[n - 1], smallerThanBefore[n - 1]);
    }
};
