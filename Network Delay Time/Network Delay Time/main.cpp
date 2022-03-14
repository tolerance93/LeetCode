/**
 * Runtime: 108 ms, faster than 93.92% of C++ online submissions for Network Delay Time.
 * Memory Usage: 37.4 MB, less than 92.02% of C++ online submissions for Network Delay Time.
 */

#include <vector>
#include <queue>
#include <utility>

using namespace std;

class Solution {
public:
    int networkDelayTime2(vector<vector<int>>& times, int n, int k) {
        vector<vector<int>> adjMatrix = vector(n + 1, vector(n + 1, -1));
        vector<int> minTimes = vector(n + 1 , 987654321);
        queue<int> vertex;
        
        for (auto& edge : times) adjMatrix[edge[0]][edge[1]] = edge[2];
        
        vertex.push(k);
        minTimes[k] = 0;
        
        while (!vertex.empty())
        {
            int curVertex = vertex.front();
            vertex.pop();
            for (int i = 1; i <= n; i++)
            {
                if (adjMatrix[curVertex][i] != -1)
                {
                    int curMin = min(minTimes[i], adjMatrix[curVertex][i] + minTimes[curVertex]);
                    if (curMin < minTimes[i])
                    {
                        vertex.push(i);
                        minTimes[i] = curMin;
                    }
                }
            }
        }
        
        int maxTime = 0;
        for (int i = 1; i < minTimes.size(); i++)
        {
            if (minTimes[i] == 987654321) return -1;
            maxTime = max(maxTime, minTimes[i]);
        }
        return maxTime;
    }
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        auto compare = [](pair<int, int>& a, pair<int, int>& b)
        {
            if (a.second > b.second) return true;
            return false;
        };
        vector<vector<int>> adjMatrix = vector(n + 1, vector(n + 1, -1));
        vector<int> minTimes = vector(n + 1 , 987654321);
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(compare)> pq(compare);
        
        for (auto& edge : times) adjMatrix[edge[0]][edge[1]] = edge[2];
        
        pq.push(pair(k, 0));
        while (!pq.empty())
        {
            auto curVertex = pq.top();
            pq.pop();
            if (minTimes[curVertex.first] != 987654321) continue;
            minTimes[curVertex.first] = curVertex.second;
            
            for (int i = 1; i <= n; i++)
            {
                if (adjMatrix[curVertex.first][i] != -1)
                {
                    int distance = curVertex.second + adjMatrix[curVertex.first][i];
                    pq.push(pair(i, distance));
                }
            }
        }
        
        int res = 0;
        for (int i = 1; i <= n; i++)
        {
            if (minTimes[i] == 987654321) return -1;
            res = max(res, minTimes[i]);
        }
        
        return res;
    }
};

int main()
{
    
    
    vector<vector<int>> e = {{1, 2, 1}, {2, 3, 2}, {1, 3, 4}};
    Solution sol;
    sol.networkDelayTime(e, 3, 1);
    return 0;
}
