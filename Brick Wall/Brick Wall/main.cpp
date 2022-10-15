/**
 * Runtime: 106 ms, faster than 37.00% of C++ online submissions for Brick Wall.
 * Memory Usage: 21.5 MB, less than 94.58% of C++ online submissions for Brick Wall.
 */

#include <vector>
#include <unordered_map>
#include <utility>

using namespace std;

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> passCountMap;
        int width = 0;
        
        for (auto& curWidth : wall[0])
        {
            width += curWidth;
        }
        
        for (int i = 0; i < wall.size(); i++)
        {
            int curPass = 0;
            for (int j = 0; j < wall[i].size(); j++)
            {
                curPass += wall[i][j];
                if (curPass == width) continue;
                    
                if (passCountMap.find(curPass) == passCountMap.end())
                {
                    passCountMap[curPass] = 1;
                }
                else
                {
                    passCountMap[curPass] += 1;
                }
            }
        }
        int cross = 0;
        for (pair<int, int> element : passCountMap)
        {
            cross = max(cross, element.second);
        }
        return wall.size() - cross;
    }
};

int main()
{
    vector<vector<int>> input
    {
        {1,2,2,1},
        {3,1,2},
        {1,3,2},
        {2,4},
        {3,1,2},
        {1,3,1,1}
    };
    Solution sol;
    sol.leastBricks(input);
    return 0;
}
