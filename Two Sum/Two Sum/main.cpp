/**
 * Runtime: 16 ms, faster than 54.74% of C++ online submissions for Two Sum.
 * Memory Usage: 12 MB, less than 10.44% of C++ online submissions for Two Sum.
 */

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int, int> map;
        
        for (int i = 0; i < nums.size(); i++)
        {
            int search = target - nums[i];
            if (map.find(search) == map.end())
            {
                map[nums[i]] = i;
            }
            else
            {
                ans.push_back(i);
                ans.push_back(map[search]);
            }
        }
        return ans;
    }
};

int main()
{
    return 0;
}
