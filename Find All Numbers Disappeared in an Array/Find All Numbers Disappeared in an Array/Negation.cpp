/**
 * Runtime: 56 ms, faster than 76.23% of C++ online submissions for Find All Numbers Disappeared in an Array.
 * Memory Usage: 33.8 MB, less than 68.15% of C++ online submissions for Find All Numbers Disappeared in an Array.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        
        for (int i = 0; i < n; i++)
        {
            int pos = abs(nums[i]) - 1;
            nums[pos] = nums[pos] > 0 ? -nums[pos] : nums[pos];
        }
        
        for (int i = 0; i < n; i++)
        {
            if (nums[i] > 0) res.push_back(i + 1);
        }
        return res;
    }
};
