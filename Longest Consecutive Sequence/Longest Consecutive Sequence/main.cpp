/**
 * Runtime: 192 ms, faster than 42.52% of C++ online submissions for Longest Consecutive Sequence.
 * Memory Usage: 39.5 MB, less than 5.27% of C++ online submissions for Longest Consecutive Sequence.
 */

#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> total;
        unordered_set<int> visited;
        int ans = 0;
        int cur = 0;
        
        for (int i = 0; i < nums.size(); i++)
        {
            total.insert(nums[i]);
        }
        
        for (int i = 0; i < nums.size(); i++)
        {
            if (visited.find(nums[i]) == visited.end())
            {
                cur = 1;
                visited.insert(nums[i]);
                int left = nums[i] - 1;
                int right = nums[i] + 1;
                
                while (total.find(left) != total.end())
                {
                    visited.insert(left);
                    cur++;
                    left--;
                }
                
                while (total.find(right) != total.end())
                {
                    visited.insert(right);
                    cur++;
                    right++;
                }
                ans = max(ans, cur);
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> input = {0,3,7,2,5,8,4,6,0,1};
    Solution sol;
    sol.longestConsecutive(input);
    return 0;
}
