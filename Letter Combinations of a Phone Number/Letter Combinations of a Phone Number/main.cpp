/**
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions for Letter Combinations of a Phone Number.
 * Memory Usage: 6.6 MB, less than 63.18% of C++ online submissions for Letter Combinations of a Phone Number.
 */

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    
    void recurse(string& digits, int pos, vector<string>& ans, unordered_map<int, string>& keypad, string cur)
    {
        if (pos == digits.size())
        {
            ans.push_back(cur);
            return;
        }
        string keys = keypad[digits[pos] - '0'];
        
        for (int i = 0; i < keys.size(); i++)
        {
            cur += keys[i];
            recurse(digits, pos + 1, ans, keypad, cur);
            cur.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if (digits.size() == 0) return ans;
        
        unordered_map<int, string> keypad;
        keypad[2] = "abc";
        keypad[3] = "def";
        keypad[4] = "ghi";
        keypad[5] = "jkl";
        keypad[6] = "mno";
        keypad[7] = "pqrs";
        keypad[8] = "tuv";
        keypad[9] = "wxyz";
        
        recurse(digits, 0, ans, keypad, "");
        return ans;
    }
};

int main()
{
    string input = "23";
    Solution sol;
    sol.letterCombinations(input);
    return 0;
}
