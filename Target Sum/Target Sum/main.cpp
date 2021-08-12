/** Recursive Solution
 * Runtime: 1160 ms, faster than 13.30% of C++ online submissions for Target Sum.
 * Memory Usage: 9.1 MB, less than 72.82% of C++ online submissions for Target Sum.
 */

#include <vector>

using namespace std;

class Solution {
public:
    void recurse(vector<int>& nums, int pos, int target, int& count, int cur)
    {
        if (pos == nums.size() - 1)
        {
            if (cur == target) count++;
            return;
        }
        recurse(nums, pos + 1, target, count, cur + nums[pos + 1]);
        recurse(nums, pos + 1, target, count, cur - nums[pos + 1]);
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int count = 0;
        recurse(nums, 0, target, count, nums[0]);
        recurse(nums, 0, target, count, -nums[0]);
        return count;
    }
};

int main()
{
    return 0;
}
