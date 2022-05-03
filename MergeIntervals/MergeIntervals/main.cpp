/**
 * Runtime: 49 ms, faster than 53.46% of C++ online submissions for Merge Intervals.
 * Memory Usage: 18.9 MB, less than 85.41% of C++ online submissions for Merge Intervals.
 */

#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [&](vector<int>& a, vector<int>& b) {
            if (a[0] < b[0]) return true;
            else if (a[0] == b[0] && a[1] < b[1]) return true;
            return false;
        });
        vector<vector<int>> ans;
        ans.push_back({intervals[0][0], intervals[0][1]});
        int endIndex = 0;
        
        for (int i = 1; i < intervals.size(); i++)
        {
            if (ans[endIndex][0] <= intervals[i][0] && intervals[i][0] <= ans[endIndex][1])
            {
                ans[endIndex][1] = max(ans[endIndex][1], intervals[i][1]);
            }
            else
            {
                ans.push_back(intervals[i]);
                endIndex++;
            }
        }
        return ans;
    }
};

int main()
{
    //[[1,3],[2,6],[8,10],[15,18]]
    Solution sol;
    vector<vector<int>> input;
    input.push_back({1,3});
    input.push_back({2,6});
    input.push_back({8,10});
    input.push_back({15,18});
    sol.merge(input);
    return 0;
}
