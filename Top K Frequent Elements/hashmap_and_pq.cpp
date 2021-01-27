/**
 * Runtime: 16 ms, faster than 92.04% of C++ online submissions for Top K Frequent Elements.
 * Memory Usage: 13.4 MB, less than 99.29% of C++ online submissions for Top K Frequent Elements.
 */

#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

struct Element
{
    int key;
    int value;
    Element(int key, int value) : key(key), value(value) {};
    
};

struct cmp{
    bool operator()(Element t, Element u){
        return t.value < u.value;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hashMap;
        priority_queue<Element, vector<Element>, cmp> pq;
        
        for (int i = 0; i < nums.size(); i++)
        {
            if (hashMap.find(nums[i]) != hashMap.end())
            {
                hashMap[nums[i]]++;
            }
            else
            {
                hashMap[nums[i]] = 0;
            }
        }
        
        for (auto e : hashMap)
        {
            pq.push(Element(e.first, e.second));
        }
        
        vector<int> res;
        
        for (int i = 0; i < k; i++)
        {
            res.push_back(pq.top().key);
            pq.pop();
        }
        
        return res;
    }
};

