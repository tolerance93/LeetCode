#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int score = 0;
        sort(tokens.begin(), tokens.end());
        int head = 0;
        int tail = tokens.size() - 1;
        int res = 0;
        while (head <= tail)
        {
            if (power >= tokens[head])
            {
                score += 1;
                res = max(res, score);
                power -= tokens[head];
                head++;
            }
            else if (score > 0)
            {
                score -= 1;
                power += tokens[tail];
                tail--;
            }
            else
            {
                break;
            }
        }
        return res;
    }
};