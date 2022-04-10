#include <vector>
#include <queue>
#include <utility>
#include <iostream>

using namespace std;

/**
 * Runtime: 62 ms, faster than 39.99% of C++ online submissions for Cheapest Flights Within K Stops.
 * Memory Usage: 13.5 MB, less than 61.82% of C++ online submissions for Cheapest Flights Within K Stops.
 */
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<int>> distance(n, vector(n + 2, 987654321));
        vector<vector<pair<int, int>>> edges(n, vector<pair<int, int>>());
        distance[src][0] = 0;
        
        for (auto& e : flights)
        {
            edges[e[0]].push_back({e[1], e[2]});
        }
        
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        pq.push({0, src, 0});
        
        while (!pq.empty())
        {
            auto [cost, vertex, jump] = pq.top();
            pq.pop();
            if (jump - 1 > k) continue;
            if (vertex == dst) return cost;
            for (auto& e : edges[vertex])
            {
                auto& [to, curCost] = e;
                if (distance[to][jump + 1] > cost + curCost)
                {
                    distance[to][jump + 1] = cost + curCost;
                    pq.push({cost + curCost, to, jump + 1});
                }
            }
        }
        return -1;
    }
};


// Timeout
class Solution2 {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> distance(n, -1);
        vector<vector<pair<int, int>>> edges(n, vector<pair<int, int>>());
        int curLevel = 0;
        distance[src] = 0;
        queue<int> q;
        
        q.push(src);
        q.push(-1);
        
        for (auto& e : flights)
        {
            edges[e[0]].push_back({e[1], e[2]});
        }
        
        vector<int> tempDist(n, 987654321);
        
        while (!q.empty())
        {
            int cur = q.front();
            q.pop();
            
            if (cur == -1)
            {
                curLevel++;
                for (int i = 0; i < n; i++)
                {
                    if (tempDist[i] != 987654321) distance[i] = tempDist[i];
                }
                if (curLevel > k) break;
                q.push(-1);
                continue;
            }
            
            for (auto& edge: edges[cur])
            {
                int dist = distance[cur] + edge.second;
                if (distance[edge.first] == -1) tempDist[edge.first] = dist;
                else tempDist[edge.first] = min(dist, min(tempDist[edge.first], distance[edge.first]));
                q.push(edge.first);
            }
            
        }
        return distance[dst];
    }
};

int main()
{
    //4
    //[[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]]
    //0
    //3
    //1
    
    Solution sol;
    vector<vector<int>> flights;
    flights.push_back({0,1,100});
    flights.push_back({1,2,100});
    flights.push_back({2,0,100});
    flights.push_back({1,3,600});
    flights.push_back({2,3,200});
    cout << sol.findCheapestPrice(4, flights, 0, 3, 1) << endl;
    return 0;
}


