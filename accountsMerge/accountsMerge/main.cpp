/**
 * Runtime: 128 ms, faster than 84.81% of C++ online submissions for Accounts Merge.
 * Memory Usage: 46.3 MB, less than 33.84% of C++ online submissions for Accounts Merge.
 */

#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    
    void dfs(string& email, unordered_map<string, vector<string>>& adjList, unordered_set<string>& visited, vector<string>& connectedComponents)
    {
        visited.insert(email);
        connectedComponents.push_back(email);
        for (auto& node : adjList[email])
        {
            if (visited.find(node) == visited.end())
            {
                dfs(node, adjList, visited, connectedComponents);
            }
        }
        
    }
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> adjList;
        unordered_set<string> visited;
        
        for (auto& account : accounts)
        {
            auto& firstEmail = account[1];
            for (int i = 2; i < account.size(); i++)
            {
                auto email = account[i];
                adjList[firstEmail].push_back(email);
                adjList[email].push_back(firstEmail);
            }
        }
        
        for (int i = 0; i < accounts.size(); i++)
        {
            for (int j = 1; j < accounts[i].size(); j++)
            {
                if (visited.find(accounts[i][j]) == visited.end())
                {
                    vector<string> connectedComponents;
                    dfs(accounts[i][j], adjList, visited, connectedComponents);
                    sort(connectedComponents.begin(), connectedComponents.end());
                    connectedComponents.insert(connectedComponents.begin(), accounts[i][0]);
                    res.push_back(connectedComponents);
                }
            }
        }
        return res;
    }
};

int main()
{
    return 0;
}


