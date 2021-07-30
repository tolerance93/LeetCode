
/**
 * Runtime: 4 ms, faster than 74.98% of C++ online submissions for Search in Rotated Sorted Array.
 * Memory Usage: 11.1 MB, less than 73.88% of C++ online submissions for Search in Rotated Sorted Array.
 */
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s = 0;
        int e = nums.size() - 1;
        
        while (s <= e)
        {
            int mid = s + (e - s) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }
            
            if (nums[s] <= nums[mid])
            {
                if (target >= nums[s] && target < nums[mid])
                {
                    e = mid - 1;
                }
                else
                {
                    s = mid + 1;
                }
            }
            else
            {
                if (target > nums[mid] && target <= nums[e])
                {
                    s = mid + 1;
                }
                else
                {
                    e = mid - 1;
                }
            }
        }
        return -1;
    }
};

int main()
{
    return 0;
}
