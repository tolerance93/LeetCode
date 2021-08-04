/**
 * Runtime: 24 ms, faster than 46.36% of C++ online submissions for Course Schedule.
 * Memory Usage: 13.9 MB, less than 50.68% of C++ online submissions for Course Schedule.
 */

#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> graph;
        vector<int> indegree(numCourses, 0);
        
        for (int i = 0; i < prerequisites.size(); i++)
        {
            int ai = prerequisites[i][0];
            int bi = prerequisites[i][1];
            graph[bi].push_back(ai);
            indegree[ai]++;
        }
        
        queue<int> q;
        for (int i = 0; i < indegree.size(); i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }
        
        int finished = 0;
        while (q.size() > 0)
        {
            int node = q.front();
            q.pop();
            finished++;
            
            vector<int> children = graph[node];
            for (int i = 0; i < children.size(); i++)
            {
                indegree[children[i]]--;
                if (indegree[children[i]] == 0)
                {
                    q.push(children[i]);
                }
            }
        }
        return finished == numCourses;
        
    }
};
