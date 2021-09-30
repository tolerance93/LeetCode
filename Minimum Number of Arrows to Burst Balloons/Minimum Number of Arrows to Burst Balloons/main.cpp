/**
 * Runtime: 420 ms, faster than 46.45% of C++ online submissions for Minimum Number of Arrows to Burst Balloons.
 * Memory Usage: 89.8 MB, less than 22.45% of C++ online submissions for Minimum Number of Arrows to Burst Balloons.
 *
 * Time Complexity: O(nlogn)
 * Space Complexity: O(n) if consider input size
 */

#include <vector>

using namespace std;

class Solution {
public:
    
    static bool compare(vector<int>& a, vector<int>& b)
    {
        if (a[1] != b[1])
        {
            return a[1] < b[1];
        }
        else
        {
            return a[0] < b[0];
        }
    }
    
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), compare);
        int count = 0;
        int checker = points[0][1];
        for (int i = 1; i < points.size(); i++)
        {
            if (points[i][0] > checker) {
                count++;
                checker = points[i][1];
            }
        }
        return count + 1;
    }
};

int main()
{
    vector<vector<int>> input;
    input.push_back({10,16});
    input.push_back({2,8});
    input.push_back({1,6});
    input.push_back({1,7});
    input.push_back({7,12});
    Solution sol;
    sol.findMinArrowShots(input);
    
    return 0;
}
