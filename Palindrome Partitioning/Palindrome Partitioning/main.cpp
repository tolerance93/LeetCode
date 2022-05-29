/**
 * Runtime: 97 ms, faster than 96.53% of C++ online submissions for Palindrome Partitioning.
 * Memory Usage: 49.4 MB, less than 81.05% of C++ online submissions for Palindrome Partitioning.
 */

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    
    bool isPalindrome(string str)
    {
        int i = 0;
        int j = (int) str.size() - 1;
        while (i < j)
        {
            if (str[i] != str[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    
    void backtrack(string& s, vector<vector<string>>& ans, int start, vector<string>& cur)
    {
        if (start == s.size())
        {
            ans.push_back(cur);
            return;
        }
        
        for (int l = 1; start + l <= s.size(); l++)
        {
            if (isPalindrome(s.substr(start, l)))
            {
                cur.push_back(s.substr(start, l));
                backtrack(s, ans, start + l, cur);
                cur.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> cur;
        backtrack(s, ans, 0, cur);
        return ans;
    }
};

int main()
{
    string input = "aab";
    Solution sol;
    sol.partition(input);
    return 0;
}
