/**
 * Runtime: 17 ms, faster than 70.00% of C++ online submissions for Rank Teams by Votes.
 * Memory Usage: 10.2 MB, less than 100.00% of C++ online submissions for Rank Teams by Votes.
 */

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    
    struct Team
    {
        int team;
        int* voteCount;
        
        Team(int team, int* voteCount) : team(team), voteCount(voteCount) {}
        
        bool operator > (const Team& other) const
        {
            for (int i = 0; i < 26; i++)
            {
                if (voteCount[i] > other.voteCount[i])
                {
                    return true;
                }
                else if (voteCount[i] < other.voteCount[i])
                {
                    return false;
                }
            }
            if (team < other.team) return true;
            return false;
                
        }
    };
    
    string rankTeams(vector<string>& votes) {
        
        int n = 26;
        int m = votes[0].size();
        
        // init
        int count[n][m];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                count[i][j] = 0;
            }
        }
        
        // count
        for (auto& str : votes)
        {
            for (int i = 0; i < str.size(); i++)
            {
                int ch = str[i] - 'A';
                count[ch][i]++;
            }
        }
        
        //sort
        vector<Team> teams;
        string& sample = votes[0];
        int team;
        
        for (int i = 0; i < sample.size(); i++)
        {
            team = sample[i] - 'A';
            teams.push_back({team, count[team]});
        }
        
        sort(teams.begin(), teams.end(), greater<Team>());
        string res;
        for (auto& c : teams)
        {
            res.push_back((char) c.team + 'A');
        }
        
        return res;
    }
};

int main()
{
    vector<string> input = {"ABC","ACB","ABC","ACB","ACB"};
    Solution sol;
    sol.rankTeams(input);
    return 0;
}
