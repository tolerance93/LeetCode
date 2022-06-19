/**
 * Runtime: 3 ms, faster than 52.97% of C++ online submissions for House Robber.
 * Memory Usage: 7.6 MB, less than 75.50% of C++ online submissions for House Robber.
 */

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = (int) nums.size();
        if (n == 1) return nums[0];
        
        int rob = nums[0];
        int notRob = 0;
        
        int temp = 0;

        for (int i = 1; i < n; i++)
        {
            temp = notRob;
            notRob = max(rob, notRob);
            rob = temp + nums[i];
            
        }
        return max(rob, notRob);
    }
};

int main()
{
    vector<int> input = {1,2,3,1};
    Solution sol;
    cout << sol.rob(input) << endl;
    return 0;
}
