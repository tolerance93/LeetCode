/**
 * https://leetcode.com/problems/couples-holding-hands/discuss/113362/JavaC%2B%2B-O(N)-solution-using-cyclic-swapping
 * 복습하기!
 */

#include <vector>

using namespace std;

class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int res = 0, N = row.size();
            
        vector<int> ptn(N, 0);
        vector<int> pos(N, 0);
            
        for (int i = 0; i < N; i++) {
            ptn[i] = (i % 2 == 0 ? i + 1 : i - 1);
            pos[row[i]] = i;
        }
        
        for (int i = 0; i < N; i++) {
            for (int j = ptn[pos[ptn[row[i]]]]; i != j; j = ptn[pos[ptn[row[i]]]]) {
                swap(row[i], row[j]);
                swap(pos[row[i]], pos[row[j]]);
                res++;
            }
        }
            
        return res;
    }
};

int main()
{
    return 0;
}
