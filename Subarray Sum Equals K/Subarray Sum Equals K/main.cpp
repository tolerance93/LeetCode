/**
 * Runtime: 72 ms, faster than 74.24% of C++ online submissions for Subarray Sum Equals K.
 * Memory Usage: 36 MB, less than 84.56% of C++ online submissions for Subarray Sum Equals K.
 */

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        int accmul = 0;
        map[0] = 1;
        int count = 0;
        
        for (int i = 0; i < nums.size(); i++)
        {
            accmul += nums[i];
            if (map.find(accmul - k) != map.end())
            {
                count += map[accmul - k];
            }
            if (map.find(accmul) != map.end()) map[accmul]++;
            else map[accmul] = 1;
        }
        return count;
    }
    
    // Timeout
    int subarraySum2(vector<int>& nums, int k) {
        vector<int> accmul = vector<int>(nums.size(), 0);
        accmul[0] = nums[0];
        
        int res = accmul[0] == k ? 1 : 0;
        
        for (int i = 1; i < nums.size(); i++)
        {
            accmul[i] = accmul[i - 1] + nums[i];
            if (accmul[i] == k) res++;
        }
        
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (accmul[i] - accmul[j] == k) res++;
            }
        }
        return res;
    }
};

int main()
{
    return 0;
}
