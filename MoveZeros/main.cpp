/**
 * Runtime: 4 ms, faster than 98.12% of C++ online submissions for Move Zeroes.
 * Memory Usage: 9 MB, less than 99.98% of C++ online submissions for Move Zeroes.
 */

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        nonZeroPos = 0;
        zeroCount = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0) zeroCount++;
            else nums[nonZeroPos++] = nums[i];
        }
        for (int i = nonZeroPos; i < nums.size(); i++)
        {
            nums[i] = 0;
        }
    }
private:
    int zeroCount;
    int nonZeroPos;
};
