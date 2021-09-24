/**
 * Runtime: 4 ms, faster than 53.06% of C++ online submissions for Number of Ways to Paint N × 3 Grid.
 * Memory Usage: 7.1 MB, less than 37.05% of C++ online submissions for Number of Ways to Paint N × 3 Grid.
 */

#include <vector>
#define MODULO 1000000007

using namespace std;

class Solution {
public:
    
    int numOfWays(int n) {
        vector<int> abc(n + 1,0);
        vector<int> aba(n + 1,0);
        aba[1] = 6;
        abc[1] = 6;
        
        for (int i = 2; i <= n; i++)
        {
            abc[i] = (abc[i - 1] * 2 % MODULO + aba[i - 1] * 2 % MODULO) % MODULO;
            aba[i] = (abc[i] + aba[i - 1]) % MODULO;
        }
        return (abc[n] + aba[n]) % MODULO;
    }
};

int main()
{
    return 0;
}
