#include <vector>

using namespace std;

// Naive Solution
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        bool res = true;
        int zeroPos = -1;
        
        if (nums.size() == 1 && nums[0] == 0) return true;
        
        for (int i = n - 1; i >= 0; i--)
        {
            if (nums[i] == 0 && res)
            {
                res = false;
                zeroPos = i;
                continue;
            }
            if (!res)
            {
                if (nums[i] > zeroPos - i || ((nums[i] == zeroPos - i) && (zeroPos == n - 1)))
                {
                    res = true;
                }
            }
        }
        return res;
    }
};

/**
 * Runtime: 56 ms, faster than 32.87% of C++ online submissions for Jump Game.
 * Memory Usage: 48.4 MB, less than 9.13% of C++ online submissions for Jump Game.
 * 비슷함..
 */
class Solution2
{
public:
    bool canJump(vector<int>& nums)
    {
        int jump = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            jump--;
            jump = nums[i] > jump ? nums[i] : jump;
            if (nums[i] == 0 && jump <= 0)
            {
                if (i == nums.size() - 1) return true;
                else return false;
            }
        }
        return true;
    }
};
