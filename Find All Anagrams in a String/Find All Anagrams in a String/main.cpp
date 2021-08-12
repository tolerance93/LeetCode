/**
 * Runtime: 12 ms, faster than 83.68% of C++ online submissions for Find All Anagrams in a String.
 * Memory Usage: 8.5 MB, less than 99.08% of C++ online submissions for Find All Anagrams in a String.
 */

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    
    bool isSame(vector<int>& pAlpha, vector<int>& sAlpha)
    {
        for (int i = 0; i < 26; i++)
        {
            if (pAlpha[i] != sAlpha[i]) return false;
        }
        return true;
    }
    
    vector<int> findAnagrams(string s, string p) {
        
        vector<int> ans;
        if (s.size() < p.size()) return ans;
        vector<int> pAlpha(26, 0);
        vector<int> sAlpha(26, 0);
        
        for (int i = 0; i < p.size(); i++)
        {
            pAlpha[p[i] - 'a']++;
            sAlpha[s[i] - 'a']++;
        }
        if (isSame(pAlpha, sAlpha)) ans.push_back(0);
        
        for (int i = 0; i < s.size() - p.size(); i++)
        {
            sAlpha[s[i] - 'a']--;
            sAlpha[s[i + p.size()] - 'a']++;
            if (isSame(pAlpha, sAlpha)) ans.push_back(i - 1);
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    string s = "cbaebabacd";
    string p = "abc";
    sol.findAnagrams(s, p);
    
    return 0;
}
