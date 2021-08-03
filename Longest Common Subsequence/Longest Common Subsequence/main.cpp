/**
 * Runtime: 8 ms, faster than 93.43% of C++ online submissions for Longest Common Subsequence.
 * Memory Usage: 10.6 MB, less than 85.89% of C++ online submissions for Longest Common Subsequence.
 */

#include <string>

using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        
        int m = text1.size();
        int n = text2.size();
        int dp[m + 1][n + 1];
        
        for (int i = 0; i <= m; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                if (i == 0 || j == 0)
                {
                    dp[i][j] = 0;
                }
                else if (text1[i - 1] == text2[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        
        return dp[m][n];
    }
};

int main()
{
    return 0;
}
