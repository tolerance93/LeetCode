/**
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions for Find Minimum in Rotated Sorted Array.
 * Memory Usage: 10.1 MB, less than 95.94% of C++ online submissions for Find Minimum in Rotated Sorted Array.
 */

#include <vector>
#include <iostream>

using namespace std;

class MySolution {
public:
    int findMin(vector<int>& nums) {
        int s = 0;
        int e = nums.size() - 1;
        
        if (nums[s] <= nums[e]) return nums[s];
        
        while (s <= e)
        {
            int mid = s + (e - s) / 2;
            if (nums[mid] >= nums[s])
            {
                if (nums[s] >= nums[0])
                {
                    s = mid + 1;
                }
                else
                {
                    e = mid - 1;
                }
            }
            else
            {
                e = mid - 1;
            }
            if (mid > 0 && nums[mid - 1] > nums[mid]) return nums[mid];
        }
        return -1;
    }
};

class Solution {
public:
    int findMin(vector<int>& nums) {
        int s = 0;
        int n = nums.size();
        int e = n - 1;
        
        while (s <= e)
        {
            int mid = (s + e) / 2;
            int next = (mid + 1) % n;
            int prev = (mid - 1 + n) % n;
            
            if (nums[mid] <= nums[prev] && nums[mid] <= nums[next])
            {
                return nums[mid];
            }
            else if (nums[mid] <= nums[e])
            {
                e = mid - 1;
            }
            else if (nums[mid] >= nums[s])
            {
                s = mid + 1;
            }
        }
        return -1;
    }
};


int main()
{
    Solution sol;
    vector<int> input = {2, 1};
    cout << sol.findMin(input) << endl;
    return 0;
}
