#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int getPalindromeSize(string& s, int left, int right)
    {
        while (left >= 0 && right < s.size())
        {
            if (s[left] != s[right]) break;
            left--;
            right++;
        }
        return right - left + 1 - 2;
    }
    
    string longestPalindrome(string s) {
        string res = "";
        
        int oddLen = 0;
        int evenLen = 0;
        int curMaxLen = 0;
        int maxLen = 0;
        int radius = 0;
        
        for (int center = 0; center < s.size(); center++)
        {
            oddLen = getPalindromeSize(s, center, center);
            evenLen = getPalindromeSize(s, center, center + 1);
            curMaxLen = max(oddLen, evenLen);
            if (curMaxLen > maxLen)
            {
                maxLen = curMaxLen;
                radius = maxLen / 2;
                if (maxLen % 2 == 0) res = s.substr(center - radius + 1, maxLen);
                else res = s.substr(center - radius, maxLen);
            }
        }
        
        return res;
    }
};

int main()
{
    string s = "cbbd";
    Solution sol;
    cout << sol.longestPalindrome(s) << endl;
    return 0;
}
