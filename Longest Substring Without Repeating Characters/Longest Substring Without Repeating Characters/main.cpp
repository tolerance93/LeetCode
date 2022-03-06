#include <string>
#include <unordered_set>
#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) return 0;
        int left = 0;
        unordered_set<char> set;
        
        int maxLen = 0;
        
        for (int right = 0; right < s.size(); right++)
        {
            if (set.find(s[right]) == set.end())
            {
                set.insert(s[right]);
            }
            else
            {
                while (s[left] != s[right])
                {
                    set.erase(s[left]);
                    left++;
                }
                left++;
            }
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};

int main()
{
    string s= "abcabcbb";
    Solution sol;
    cout << sol.lengthOfLongestSubstring(s) << endl;
    return 0;
}
