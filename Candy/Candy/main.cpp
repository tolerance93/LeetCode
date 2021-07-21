/**
 * Runtime: 16 ms, faster than 92.37% of C++ online submissions for Candy.
 * Memory Usage: 17.8 MB, less than 37.38% of C++ online submissions for Candy.
 */

#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if (n == 1) return 1;
        int res = 0;

        vector<int> candies = vector<int>(n, 0);
        //Is local minimum?
        for (int i = 1; i < n - 1; i++)
        {
            if (ratings[i - 1] >= ratings[i] && ratings[i] <= ratings[i + 1]) candies[i] = 1;
        }
        //end point
        if (ratings[1] >= ratings[0]) candies[0] = 1;
        if (ratings[n - 2] >= ratings[n - 1]) candies[n - 1] = 1;
        //left to right. Is increasing?
        for (int i = 1; i < n; i++)
        {
            if (candies[i - 1] != 0 && ratings[i] > ratings[i - 1]) candies[i] = candies[i - 1] + 1;
        }
        //right to left. Is increasing? take max since candy subject to LTR also.
        for (int i = n - 2; i >= 0; i--)
        {
            if (candies[i + 1] != 0 && ratings[i] > ratings[i + 1]) candies[i] = max(candies[i],candies[i + 1] + 1);
            res += candies[i];
        }
        res += candies[n - 1];
        return res;
    }
};

int main()
{
    Solution sol;
    return 0;
}
