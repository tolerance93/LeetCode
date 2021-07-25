#include <iostream>
#include <algorithm>

using namespace std;

//Time out
class Solution {
public:
    int superEggDrop(int k, int n){
        
        int T[k + 1][n + 1];
        for (int i = 0; i < k + 1; i++)
        {
            for (int j = 0; j < n + 1; j++)
            {
                T[i][j] = 0;
            }
        }
        
        int c = 0;
        for(int i = 0; i <= n; i++){
            T[1][i] = i;
        }
        
        for(int e = 2; e <= k; e++){
            for(int f = 1; f <= n; f++){
                T[e][f] = 987654321;
                for(int k = 1; k <= f ; k++){
                    c = 1 + max(T[e-1][k-1], T[e][f-k]);
                    if(c < T[e][f]){
                        T[e][f] = c;
                    }
                }
            }
        }
        return T[k][n];
    }
};

int main()
{
    Solution sol;
    cout << sol.superEggDrop(7, 10000) << endl;
}

