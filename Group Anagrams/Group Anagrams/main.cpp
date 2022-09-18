/*
 * Runtime: 180 ms, faster than 9.61% of C++ online submissions for Group Anagrams.
 * Memory Usage: 30.5 MB, less than 7.72% of C++ online submissions for Group Anagrams.
 */

#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    
    string vecToStr(vector<int>& arr)
    {
        string res;
        for (int i = 0; i < arr.size(); i++)
        {
            res.append(to_string(arr[i]));
            res.push_back(',');
            
        }
        return res;
    
    }
    
    void dfs(int cur,vector<string>& strs, unordered_map<int, vector<int>>& adjList, unordered_set<int>& visited, vector<string>& cc)
    {
        visited.insert(cur);
        cc.push_back(strs[cur]);
        for (auto adj : adjList[cur])
        {
            if (visited.find(adj) == visited.end())
            {
                dfs(adj, strs, adjList, visited, cc);
            }
        }
    }
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> rootNodes;
        unordered_map<int, vector<int>> adjList;
        unordered_set<int> visited;
        vector<vector<string>> res;
        
        for (int i = 0; i < strs.size(); i++)
        {
            string& s = strs[i];
            vector<int> charCount(26,0);
            for (auto c : s)
            {
                charCount[c - 'a']++;
            }
            string index = vecToStr(charCount);
            if (rootNodes.find(index) == rootNodes.end())
            {
                rootNodes[index] = i;
            }
            else
            {
                adjList[i].push_back(rootNodes[index]);
                adjList[rootNodes[index]].push_back(i);
            }
        }
        for (int i = 0; i < strs.size(); i++)
        {
            if (visited.find(i) == visited.end())
            {
                vector<string> cc;
                dfs(i, strs, adjList, visited, cc);
                res.push_back(cc);
            }
        }
        return res;
    }
};

int main()
{
    vector<string> input = {"eat","tea","tan","ate","nat","bat"};
    Solution sol;
    sol.groupAnagrams(input);
    return 0;
}
