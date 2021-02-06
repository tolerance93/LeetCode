/**
 * Runtime: 8 ms, faster than 37.99% of C++ online submissions for Partition Labels.
 * Memory Usage: 6.5 MB, less than 90.22% of C++ online submissions for Partition Labels.
 */

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string S) {
        int n = S.size();
        int end[n];
        vector<int> res;
        
        for (int i = 0; i < n; i++)
        {
            char c = S[i];
            for (int j = n - 1; j >= i; j--)
            {
                if (S[j] == c)
                {
                    end[i] = j;
                    break;
                }
            }
        }
        
        int start = 0;
        while (start < n)
        {
            int e = end[start];
            for (int i = start; i < e; i++)
            {
                if (end[i] > e) e = end[i];
            }
            res.push_back(e + 1);
            start = e + 1;
        }
        for (int i = res.size() - 1; i > 0; i--)
        {
            res[i] = res[i] - res[i - 1];
        }
        return res;
    }
};
