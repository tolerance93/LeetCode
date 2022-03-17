/**
 * Runtime: 4 ms, faster than 97.26% of C++ online submissions for Validate Stack Sequences.
 * Memory Usage: 15.3 MB, less than 59.03% of C++ online submissions for Validate Stack Sequences.
 */

#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int popIndex = 0;
        stack<int> s;
        
        for (auto e : pushed)
        {
            s.push((e));
            while (!s.empty() && s.top() == popped[popIndex])
            {
                s.pop();
                popIndex++;
            }
        }
        return s.size() == 0;
    }
};

int main()
{
    
    //[1,2,3,4,5]
    //[4,3,5,1,2]
    vector<int> push = {1,0};
    vector<int> pop = {1,0};
    Solution sol;
    sol.validateStackSequences(push, pop);
    return 0;
}
