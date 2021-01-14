/**
 * Runtime: 4 ms, faster than 99.99% of C++ online submissions for Find the Duplicate Number.
 * Memory Usage: 11 MB, less than 100.00% of C++ online submissions for Find the Duplicate Number.
 */

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int rabit = 0;
        int turtle = 0;
        
        do
        {
            rabit = nums[nums[rabit]];
            turtle = nums[turtle];
        }
        while (rabit != turtle);
        
        turtle = 0;
        
        while (rabit != turtle)
        {
            rabit = nums[rabit];
            turtle = nums[turtle];
        }
        
        return rabit;
    }
};

int main()
{
    Solution sol;
    vector<int> input = {1,3,4,2,2};
    cout << sol.findDuplicate(input) << endl;
}
