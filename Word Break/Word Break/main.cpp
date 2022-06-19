/**
 * Runtime: 19 ms, faster than 51.04% of C++ online submissions for Word Break.
 * Memory Usage: 13.2 MB, less than 45.02% of C++ online submissions for Word Break.
 * Refer discussion. recusion solution timeout..
 */

#include <string>
#include <vector>
#include <unordered_set>
#include <iostream>

using namespace std;
class Solution {
public:
        
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> isPossibleSubstring(s.size() + 1, false);
        unordered_set<string> set;
        isPossibleSubstring[0] = true;
        for (auto s : wordDict)
        {
            set.insert(s);
        }
        
        for (int i = 1; i <= s.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (isPossibleSubstring[j] && set.find(s.substr(j, i - j)) != set.end())
                {
                    isPossibleSubstring[i] = true;
                    break;
                }
            }
        }
        return isPossibleSubstring[s.size()];
    }
};

int main()
{
    Solution sol;

    string s = "leetcode";
    vector<string> wordDict = {"leet", "code"};
    
    sol.wordBreak(s, wordDict);
    return 0;
}
