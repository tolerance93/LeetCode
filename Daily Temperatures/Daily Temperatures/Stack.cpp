#include <vector>
#include <iostream>
#include <stack>

using namespace std;

class Solution3 {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int n = T.size();
        stack<int> stack;
        vector<int> res(n);
        
        for (int i = 0; i < n; i++)
        {
            if (stack.empty())
            {
                stack.push(i);
                continue;
            }
            while (!stack.empty() && T[stack.top()] < T[i])
            {
                res[stack.top()] = i - stack.top();
                stack.pop();
            }
            stack.push(i);
        }
        while (!stack.empty())
        {
            res[stack.top()] = 0;
            stack.pop();
        }
        return res;
    }
};

int main()
{
    vector<int> input = {73,74,75,71,69,72,76,73};
    Solution3 sol;
    vector<int> res = sol.dailyTemperatures(input);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << endl;
    }
    return 0;
}
