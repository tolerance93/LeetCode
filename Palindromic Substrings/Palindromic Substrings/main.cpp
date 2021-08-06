/**
 * Runtime: 152 ms, faster than 13.31% of C++ online submissions for Palindromic Substrings.
 * Memory Usage: 6.3 MB, less than 88.47% of C++ online submissions for Palindromic Substrings.
 */

#include <string>

using namespace std;

class Solution {
public:
    
    bool isPalindrome(string& s, int start, int end)
    {
        if ((end - start) % 2 == 0)
        {
            while (start != end)
            {
                if (s[start] != s[end]) return false;
                start++;
                end--;
            }
            return true;
        }
        else
        {
            while (start < end)
            {
                if (s[start] != s[end]) return false;
                start++;
                end--;
            }
            return true;
        }
    }
    
    int countSubstrings(string s) {
        int count = 0;
        for (int len = 1; len <= s.size(); len++)
        {
            for (int start = 0; start < s.size(); start++)
            {
                int end = start + len - 1;
                if (end >= s.size()) break;
                if (isPalindrome(s, start, end))
                    count++;
            }
        }
        return count;
    }
};

int main()
{
    Solution sol;
    string s = "aaa";
    sol.countSubstrings(s);
    return 0;
}
