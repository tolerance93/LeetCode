/**
 * Runtime: 12 ms, faster than 97.02% of C++ online submissions for Jump Game II.
 * Memory Usage: 16.6 MB, less than 52.06% of C++ online submissions for Jump Game II.
 */

#include <vector>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int size = nums.size();
        int res = 0;
        int cur = 0;
        int curWindow = nums[0];
        int nextWindow = -1;
        
        while (cur < size - 1)
        {
            for (int j = cur + 1; j <= curWindow && j < size; j++)
            {
                if (j + nums[j] > nextWindow) nextWindow = j + nums[j];
                cur = j;
            }
            res++;
            curWindow = nextWindow;
        }
        return res;
    }
};

int main()
{
    return 0;
}
