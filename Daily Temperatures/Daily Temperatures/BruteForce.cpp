#include <vector>
#include <iostream>

using namespace std;

/**
 * Brute force: Time out!!
 */

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int n = T.size();
        vector<int> res;
        
        for (int i = 0; i < n ; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (T[j] > T[i])
                {
                    res.push_back(j - i);
                    break;
                }
            }
            if (res.size() == i) res.push_back(0);
        }
        return res;
    }
};

int main123()
{
    vector<int> input = {73,74,75,71,69,72,76,73};
    Solution sol;
    vector<int> res = sol.dailyTemperatures(input);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << endl;
    }
    return 0;
}
