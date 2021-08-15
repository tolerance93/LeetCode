/**
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions for Valid Parenthesis String.
 * Memory Usage: 6.1 MB, less than 79.81% of C++ online submissions for Valid Parenthesis String.
 */

#include <string>

using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        int lowerBound = 0;
        int upperBound = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                lowerBound++;
                upperBound++;
            }
            else if (s[i] == ')')
            {
                if (lowerBound > 0) lowerBound--;
                upperBound--;
            }
            else
            {
                if (lowerBound > 0) lowerBound--;
                upperBound++;
            }
            if (upperBound < 0) return false;
        }
        return lowerBound == 0;
    }
};

int main()
{
    return 0;
}
