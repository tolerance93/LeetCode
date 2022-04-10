/**
 * Runtime: 952 ms, faster than 5.04% of C++ online submissions for Smallest String With Swaps.
 * Memory Usage: 48.4 MB, less than 86.34% of C++ online submissions for Smallest String With Swaps.
 */

#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int findHead(vector<int>& unionFind, int index)
    {
        if (index == unionFind[index])
            return index;
        else
            return unionFind[index] = findHead(unionFind, unionFind[index]);
    }

    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        
        int n = (int) s.length();
        vector<int> unionFind(n);
        for (int i = 0; i < n; i++)
        {
            unionFind[i] = i;
        }
        
        for (auto& e : pairs)
        {
            int a = findHead(unionFind, e[0]);
            int b = findHead(unionFind, e[1]);
            if (a != b) unionFind[b] = a;
        }
        
        vector<vector<char>> connectedComponents(n, vector<char>());
        
        for (int i = 0; i < n; i++)
        {
            connectedComponents[findHead(unionFind,i)].push_back(s[i]);
        }
        
        for (int i = 0; i < n; i++)
        {
            if (connectedComponents[i].size() > 1)
            {
                sort(connectedComponents[i].begin(), connectedComponents[i].end(), less<char>());
            }
        }
        
        string res = "";
        for (int i = 0; i < n; i++)
        {
            res += connectedComponents[unionFind[i]][0];
            connectedComponents[unionFind[i]].erase(connectedComponents[unionFind[i]].begin());
        }
        
        return res;
    }
};

int main()
{
    
    //"pwqlmqm"
    //[[5,3],[3,0],[5,1],[1,1],[1,5],[3,0],[0,2]]
    string s = "dcab";
    vector<vector<int>> pairs;
    pairs.push_back({0, 3});
    pairs.push_back({1, 2});
    pairs.push_back({0, 2});
    Solution sol;
    cout << sol.smallestStringWithSwaps(s, pairs) << endl;
    
    return 0;
}
