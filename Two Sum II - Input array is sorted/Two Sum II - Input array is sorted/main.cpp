/**
 * Runtime: 4 ms, faster than 89.48% of C++ online submissions for Two Sum II - Input array is sorted.
 * Memory Usage: 9.7 MB, less than 43.74% of C++ online submissions for Two Sum II - Input array is sorted.
 */

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int s = 0;
        int e = numbers.size() - 1;
        vector<int> ans;
        
        while (numbers[s] + numbers[e] != target)
        {
            if (numbers[s] + numbers[e] > target) e--;
            else if (numbers[s] + numbers[e] < target) s++;
        }
        ans.push_back(s + 1);
        ans.push_back(e + 1);
        return ans;
    }
};
