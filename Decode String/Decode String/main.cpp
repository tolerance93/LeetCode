/**
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions for Decode String.
 * Memory Usage: 6.8 MB, less than 22.31% of C++ online submissions for Decode String.
 */

#include <string>
#include <stack>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isDigit(char c)
    {
        int deter = c - '0';
        if (deter >= 0 && deter <= 9) return true;
        return false;
        
    }
    
    string decodeString(string s) {
        string ans = "";
        stack<int> nums;
        
        for (int i = 0; i < s.size(); i++)
        {
            if (isDigit(s[i]))
            {
                if (nums.empty())
                {
                    nums.push(s[i] - '0');
                }
                else
                {
                    int temp = nums.top();
                    nums.pop();
                    nums.push(temp * 10 + s[i] - '0');
                }
            }
            else if (s[i] == '[')
            {
                int leftCount = 1;
                for (int j = i + 1; j < s.size(); j++)
                {
                    if (s[j] == '[') leftCount++;
                    else if (s[j] == ']')
                    {
                        leftCount--;
                        if (leftCount == 0)
                        {
                            string temp = decodeString(s.substr(i + 1, j - i - 1));
                            int n = nums.top();
                            nums.pop();
                            
                            for (int k = 0; k < n; k++)
                            {
                                ans += temp;
                            }
                            
                            i = j;
                            break;
                        }
                    }
                }
            }
            else
            {
                ans += s[i];
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    string s = "3[a2[c]]";
    cout << sol.decodeString(s) << endl;
    return 0;
}
