/**
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions for Unique Paths.
 * Memory Usage: 5.9 MB, less than 63.10% of C++ online submissions for Unique Paths.
 */

class Solution {
public:
    int uniquePaths(int m, int n) {
        long long ans = 1;
        
        for (int i = n; i <= n + m - 2; i++)
        {
            ans = ans * i;
            ans = ans / (i - n + 1);
        }
        return ans;
    }
};
