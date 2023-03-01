#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        vector<int> l2r(n, 0);
        vector<int> r2l(n, 0);
        //left to right
        for (int i = 1; i < n; i++)
        {
            if (seats[i] == 1) continue;
            if (seats[i - 1] == 1)
            {
                l2r[i] = 1;
            }
            else
            {
                l2r[i] = l2r[i - 1] + 1;
            }
        }

        //right to left
        for (int i = n - 2; i >= 0; i--)
        {
            if (seats[i] == 1) continue;
            if (seats[i + 1] == 1)
            {
                r2l[i] = 1;
            }
            else
            {
                r2l[i] = r2l[i + 1] + 1;
            }
        }
        int res = 0;
        int cur = 987654321;
        for (int i = 0; i < n; i++)
        {
            if (seats[i] == 1) continue;
            cur = min(l2r[i], r2l[i]);
            res = max(cur, res);
        }
        return res;
    }
};

int main()
{
    //vector<int> input{1,0,0,0,1,0,1};
    vector<int> input{1,0,0,0};
    Solution sol;
    int res = sol.maxDistToClosest(input);
    cout << res << endl;
    return 0;
}