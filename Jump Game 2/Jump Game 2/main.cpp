/**
 * Runtime: 12 ms, faster than 88.80% of C++ online submissions for Jump Game II.
 * Memory Usage: 16.4 MB, less than 62.04% of C++ online submissions for Jump Game II.
 */

#include <vector>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;
        if (nums[0] == 0) return -1;
        
        int ladder = nums[0];
        int stair = nums[0];
        int jump = 1;
        
        for (int i = 1; i < n; i++)
        {
            if (i == n - 1) return jump;
            
            if (i + nums[i] > ladder)
                ladder = i + nums[i];
            
            stair--;
            
            if (stair == 0)
            {
                jump++;
                if (i > ladder) return -1;
                stair = ladder - i;
            }
        }
        return -1;
    }
};
