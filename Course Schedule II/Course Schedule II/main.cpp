/**
 * Runtime: 30 ms, faster than 16.61% of C++ online submissions for Course Schedule II.
 * Memory Usage: 14.2 MB, less than 46.69% of C++ online submissions for Course Schedule II.
 */

#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> graph;
        vector<int> indegree(numCourses, 0);
        vector<int> ans;
        
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
        
        while (q.size() > 0)
        {
            int node = q.front();
            ans.push_back(node);
            q.pop();
            
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
        if (ans.size() == numCourses) return ans;
        return vector<int>();
    }
};

int main()
{
    return 0;
}
