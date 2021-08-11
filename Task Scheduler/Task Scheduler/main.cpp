/**
 * Runtime: 56 ms, faster than 84.14% of C++ online submissions for Task Scheduler.
 * Memory Usage: 34.4 MB, less than 61.76% of C++ online submissions for Task Scheduler.
 */

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int alpha[26];
        for (int i = 0; i < 26; i++)
        {
            alpha[i] = 0;
        }
        
        int maxCount = 0;
        for (int i = 0; i < tasks.size(); i++)
        {
            alpha[tasks[i] - 'A']++;
            maxCount = max(maxCount, alpha[tasks[i] - 'A']);
        }
        
        int numOfMaxs = 0;
        for (int i = 0; i < 26; i++)
        {
            if (alpha[i] == maxCount) numOfMaxs++;
        }
        
        int idles = (n - numOfMaxs + 1) * (maxCount - 1);
        idles -= (tasks.size() - numOfMaxs * maxCount);
        if (idles < 0) return tasks.size();
        return idles + tasks.size();
    }
};

int main()
{
    vector<char> input = {'A', 'A', 'A', 'B', 'B', 'B'};
    Solution sol;
    sol.leastInterval(input, 2);
    return 0;
}
