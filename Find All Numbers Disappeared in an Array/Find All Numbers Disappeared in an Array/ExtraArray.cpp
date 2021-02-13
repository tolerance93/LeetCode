#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size() + 1;
        vector<int> res(n);
        vector<int> ret;
        
        for (int i = 0; i < res.size(); i++)
        {
            res[i] = 0;
        }
        
        for (int i = 0; i < nums.size(); i++)
        {
            res[nums[i]] = 1;
        }
        
        for (int i = 1; i < res.size(); i++)
        {
            if (res[i] == 0) ret.push_back(i);
        }
        return ret;
    }
};
