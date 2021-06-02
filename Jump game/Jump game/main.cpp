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
