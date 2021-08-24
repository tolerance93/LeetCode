/**
 * Runtime: 16 ms, faster than 98.69% of C++ online submissions for Maximum Number of Vowels in a Substring of Given Length.
 * Memory Usage: 10 MB, less than 60.83% of C++ online submissions for Maximum Number of Vowels in a Substring of Given Length.
 */

#include <string>

using namespace std;

class Solution {
public:
    
    bool isVowel(char c)
    {
        if (c == 'a' || c == 'e' ||
            c == 'i' || c == 'o' ||
            c == 'u')
        {
            return true;
        }
        return false;
    }
    
    int maxVowels(string s, int k) {
        int ans = 0;
        int cur = 0;
        
        for (int i = 0; i < k; i++)
        {
            cur += isVowel(s[i]) ? 1 : 0;
        }
        
        ans = max(ans, cur);
        
        for (int i = 1; i <= s.size() - k; i++)
        {
            cur -= isVowel(s[i - 1]) ? 1 : 0;
            cur += isVowel(s[i + k - 1]) ? 1 : 0;
            ans = max(ans, cur);
        }
        return ans;
    }
};

int main()
{
    return 0;
}
