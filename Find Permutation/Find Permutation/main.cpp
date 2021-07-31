#include <vector>
#include <string>

using namespace std;

class Solution
{
    vector<int> findPerm(const string str, int n)
    {
        vector<int> ans(n);
        int s = 1, e = n;
        
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == 'D')
            {
                ans[i] = e;
                e--;
            }
            else
            {
                ans[i] = s;
                s++;
            }
        }
        ans[n - 1] = s;
        return ans;
    }
    
};

int main()
{
    return 0;
}
