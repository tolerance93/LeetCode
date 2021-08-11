/**
 * Runtime: 24 ms, faster than 87.19% of C++ online submissions for Rotate Array.
 * Memory Usage: 25 MB, less than 70.97% of C++ online submissions for Rotate Array.
 */

#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int start = 0;
        int cur, temp, prev;
        int count = 0;
        
        int n = int(nums.size());
        k = k % n;
        
        while (count < nums.size())
        {
            cur = start;
            temp = nums[cur];
            prev = (cur - k + n) % n;
            
            while (prev != start)
            {
                nums[cur] = nums[prev];
                cur = prev;
                prev = (prev - k + n) % n;
                count++;
            }
            nums[cur] = temp;
            count++;
            start++;
        }
    }
};

int main()
{
    return 0;
}
