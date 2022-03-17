/**
 * Runtime: 8 ms, faster than 82.24% of C++ online submissions for Edit Distance.
 * Memory Usage: 7.3 MB, less than 62.75% of C++ online submissions for Edit Distance.
 */

#include <string>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = (int) word1.size();
        int n = (int) word2.size();
        int dp[m + 1][n + 1];
        
        for (int i = 0; i <= m; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                if (i == 0)
                {
                    dp[i][j] = j;
                }
                else if (j == 0)
                {
                    dp[i][j] = i;
                }
                else if (word1[i - 1] == word2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else
                {
                    int insert = dp[i][j - 1];
                    int del = dp[i - 1][j];
                    int replace = dp[i - 1][j - 1];
                    dp[i][j] = 1 + min(insert, min(del, replace));
                    
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
