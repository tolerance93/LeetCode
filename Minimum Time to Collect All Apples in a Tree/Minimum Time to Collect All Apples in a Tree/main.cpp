/**
 * Runtime: 195 ms, faster than 91.45% of C++ online submissions for Minimum Time to Collect All Apples in a Tree.
 * Memory Usage: 60.2 MB, less than 98.08% of C++ online submissions for Minimum Time to Collect All Apples in a Tree.
 */

#include <vector>

using namespace std;

class Solution {
public:
    
    int res = 0;
    
    bool findApple(int cur, vector<int> adjList[], vector<bool>& hasApple, int n, int parent)
    {
        if (hasApple[cur]) return true;
        for (auto& child : adjList[cur])
        {
            if (child == parent) continue;
            if (findApple(child, adjList, hasApple, n, cur)) return true;
        }
        return false;
    }
    
    void dfs(int cur, vector<int> adjList[], vector<bool>& hasApple, int n, int parent)
    {
        
        for (auto& child : adjList[cur])
        {
            if (child == parent) continue;
            if (findApple(child, adjList, hasApple, n, cur))
            {
                res += 2;
                dfs(child, adjList,hasApple, n, cur);
            }
        }
    }
    
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<int> adjList[n];
        for (auto& edge : edges)
        {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
        dfs(0, adjList, hasApple, n, -1);
        return res;
    }
};

int main()
{
//Input: n = 7, edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], hasApple = [false,false,true,false,true,true,false]
    int n = 7;
    vector<vector<int>> edges;
    edges.push_back({0, 1});
    edges.push_back({0, 2});
    edges.push_back({1, 4});
    edges.push_back({1, 5});
    edges.push_back({2, 3});
    edges.push_back({2, 6});
    vector<bool> hasApple = {false, false, true, false, true, true, false};
    Solution sol;
    sol.minTime(n, edges, hasApple);
    
    return 0;
}
