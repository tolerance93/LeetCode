/**
 * Runtime: 58 ms, faster than 17.49% of C++ online submissions for Non-decreasing Array.
 * Memory Usage: 27 MB, less than 53.01% of C++ online submissions for Non-decreasing Array.
 */

#include <vector>

using namespace std;


class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int reverse = 0;
        
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i - 1] > nums[i])
            {
                reverse++;
                if(i - 2 < 0 || nums[i - 2] <= nums[i])
                {
                    nums[i-1] = nums[i];
                }
                else
                {
                    nums[i] = nums[i-1];
                }
            }
        }
        return reverse <= 1;
    }
};

int main()
{
    // [3,4,2,3]
    return 0;
}
