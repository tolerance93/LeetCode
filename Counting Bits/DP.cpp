/*
 * Runtime: 4 ms, faster than 97.44% of C++ online submissions for Counting Bits.
 * Memory Usage: 7.8 MB, less than 96.63% of C++ online submissions for Counting Bits.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res(num + 1);
        res[0] = 0;
        if (num == 0)
        {
            return res;
        }
        res[1] = 1;
        
        int end = 4;
        int pos = 2;
        
        while (pos <= num)
        {
            int adder = 0;
            while (pos < end)
            {
                res[pos] = res[0 + adder] + 1;
                adder++;
                pos++;
                if (pos > num) break;
            }
            end *= 2;
        }
        return res;
    }
};

class ShrotSolution
{
public:
    vector<int> countBits(int num)
    {
        vector<int> res(num + 1);
        res[0] = 0;
        for (int i = 0; i <= num; i++)
        {
            res[i] = res[i>>1] + (i&1);
        }
        return res;
    }
};
