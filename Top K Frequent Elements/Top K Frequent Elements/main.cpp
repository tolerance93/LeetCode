/**
 * Runtime: 16 ms, faster than 65.92% of C++ online submissions for Top K Frequent Elements.
 * Memory Usage: 13.8 MB, less than 38.70% of C++ online submissions for Top K Frequent Elements.
 */

#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    
    struct element
    {
        int num;
        int count;
    };
    
    struct cmp {
        bool operator()(element &a, element &b) {
            if (a.count > b.count) return false;
            return true;
        }
    };
    
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int, int> map;
        priority_queue<element, vector<element>, cmp> pq;
        
        for (int i = 0; i < nums.size(); i++)
        {
            if (map.find(nums[i]) != map.end())
            {
                map[nums[i]]++;
            }
            else
            {
                map[nums[i]] = 1;
            }
        }
        
        for (auto& num : map)
        {
            pq.push({num.first, num.second});
        }
        
        for (int i = 0; i < k; i++)
        {
            ans.push_back(pq.top().num);
            pq.pop();
        }
        return ans;
    }
};


int main()
{
    
    return 0;
}
