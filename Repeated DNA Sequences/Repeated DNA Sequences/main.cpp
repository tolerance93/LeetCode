/**
 * Runtime: 76 ms, faster than 78.14% of C++ online submissions for Repeated DNA Sequences.
 * Memory Usage: 19.5 MB, less than 83.17% of C++ online submissions for Repeated DNA Sequences.
 */

#include <vector>
#include <string>
#include <unordered_set>
#include <iostream>
using namespace std;


class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<string> foundDNASeqs;
        unordered_set<string> answerSeqs;
        vector<string> res;
        if (s.size() < 10) return res;
        for (int i = 0; i <= s.size() - 10; i++)
        {
            string curDNA = s.substr(i,10);
            if (foundDNASeqs.find(curDNA) == foundDNASeqs.end())
            {
                foundDNASeqs.insert(curDNA);
            }
            else
            {
                if (answerSeqs.find(curDNA) == answerSeqs.end())
                {
                    answerSeqs.insert(curDNA);
                }
            }
        }
        for (auto seq : answerSeqs)
        {
            res.push_back(seq);
        }
        return res;
    }
};


int main()
{
    return 0;
}
