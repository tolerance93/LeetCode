/**
 * Runtime: 20 ms, faster than 69.70% of C++ online submissions for Merge Intervals.
 * Memory Usage: 14.2 MB, less than 82.61% of C++ online submissions for Merge Intervals.
 *
 * Time complexity: O(nlogn)
 * Space complexity: O(n)
 */

#include <vector>

using namespace std;

class Solution {
public:
    
    static bool cmp(vector<int>& a, vector<int>& b)
    {
        if (a[0] < b[0]) return true;
        else if (a[0] == b[0] && a[1] < b[1]) return true;
        return false;
    }
    
    bool isOverlap(int s1, int e1, int s2)
    {
        if (s2 >= s1 && s2 <= e1)
        {
            return true;
        }
        return false;
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        
        sort(intervals.begin(), intervals.end(), cmp);
        
        int start = intervals[0][0];
        int end = intervals[0][1];
        
        for (int i = 1; i < intervals.size(); i++)
        {
            int curStart = intervals[i][0];
            int curEnd = intervals[i][1];
            
            if (isOverlap(start, end, curStart))
            {
                end = max(end, curEnd);
            }
            else
            {
                ans.push_back({start, end});
                start = curStart;
                end = curEnd;
            }
        }
        if (ans.size() == 0 || ans[ans.size() - 1][0] != start || ans[ans.size() - 1][1] != end)
        {
            ans.push_back({start, end});
        }
        return ans;
    }
};

int main()
{
    vector<vector<int>> input;
    input.push_back({1,4});
    input.push_back({4,5});
    
    Solution sol;
    sol.merge(input);
    
    return 0;
}
