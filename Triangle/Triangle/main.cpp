/**
 * Runtime: 4 ms, faster than 92.93% of C++ online submissions for Triangle.
 * Memory Usage: 8.7 MB, less than 33.27% of C++ online submissions for Triangle.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n). actually, num of elements in last row of triangle * 2
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    
    void swap(vector<int>& a, vector<int>& b)
    {
        vector<int>& temp = a;
        a = b;
        b = temp;
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int level = (int) triangle.size();
        if (level == 1) return triangle[0][0];
        int lastLevelWidth = (int) triangle[level - 1].size();
        
        vector<int> up(lastLevelWidth, 0);
        vector<int> down(lastLevelWidth, 0);
        
        up[0] = triangle[0][0];
        down[0] = triangle[1][0] + triangle[0][0];
        down[1] = triangle[1][1] + triangle[0][0];
        
        for (int i = 2; i < level; i++)
        {
            swap(up, down);
            int curWidth = (int) triangle[i].size();
            for (int j = 0; j < curWidth; j++)
            {
                if (j == 0)
                {
                    down[j] = up[j] + triangle[i][j];
                }
                else if (j == curWidth - 1)
                {
                    down[j] = up[j - 1] + triangle[i][j];
                }
                else
                {
                    down[j] = min(up[j - 1], up[j]) + triangle[i][j];
                }
            }
        }
        int res = 987654321;
        for (int i = 0; i < down.size(); i++)
        {
            res = min(res, down[i]);
        }
        return res;
    }
};

int main()
{
    vector<vector<int>> input;
    input.push_back({1});
    input.push_back({2,3});
    input.push_back({4,5,6});
    Solution sol;
    cout << sol.minimumTotal(input) << endl;
    return 0;
}

