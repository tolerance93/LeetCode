/**
 * Runtime: 3 ms, faster than 67.54% of C++ online submissions for Restore IP Addresses.
 * Memory Usage: 6.5 MB, less than 87.80% of C++ online submissions for Restore IP Addresses.
 */

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    
    bool isCorrectSize(int strLen, int thirdDotIndex)
    {
        if (strLen - thirdDotIndex > 4 || thirdDotIndex > strLen - 2) return false;
        return true;
    }
    
    bool isCorrectIP(string& s, int first, int second, int third)
    {
        int ip1 = std::stoi(s.substr(0, first + 1));
        if ((ip1 > 0 && s[0] == '0') || ip1 > 255 || (ip1 == 0 && first > 0)) return false;
        
        int ip2 = std::stoi(s.substr(first + 1, second - first));
        if ((ip2 > 0 && s[first + 1] ==  '0') || ip2 > 255 || (ip2 == 0 && second - first > 1)) return false;
        
        int ip3 = std::stoi(s.substr(second + 1, third - second));
        if ((ip3 > 0 && s[second + 1] ==  '0') || ip3 > 255 || (ip3 == 0 && third - second > 1)) return false;
        
        int ip4 = std::stoi(s.substr(third + 1, s.size() - third - 1));
        if ((ip4 > 0 && s[third + 1] ==  '0') || ip4 > 255 || (ip4 == 0 && s.size() - third - 1 > 1)) return false;
        
        return true;
    }
    
    
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        int strLen = (int) s.size();
        
        if (s.size() < 4)
        {
            return ans;
        }
        
        for (int first = 0; first < 3; first++)
        {
            for (int second = first + 1; second < first + 4; second++)
            {
                for (int third = second + 1; third < second + 4; third++)
                {
                    if (isCorrectSize(strLen, third))
                    {
                        if (isCorrectIP(s, first, second, third))
                        {
                            ans.push_back(s.substr(0, first + 1) + "."
                                          + s.substr(first + 1, second - first) + "."
                                          + s.substr(second + 1, third - second) + "."
                                          + s.substr(third + 1, s.size() - third));
                        }
                    }
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    string input = "010010";
    sol.restoreIpAddresses(input);
    return 0;
}
