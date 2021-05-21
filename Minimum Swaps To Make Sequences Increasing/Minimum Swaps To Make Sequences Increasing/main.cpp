#include <vector>

using namespace std;

class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        int n = A.size();
        int res = 0;
        for (int i = n - 1; i > 0; i--)
        {
            if (A[i] <= A[i - 1] || B[i] <= B[i - 1])
            {
                int temp = A[i - 1];
                A[i - 1] = B[i - 1];
                B[i - 1] = temp;
                res++;
            }
        }
        return res;
    }
};
