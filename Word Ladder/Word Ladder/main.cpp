/**
 * Runtime: 156 ms, faster than 57.86% of C++ online submissions for Word Ladder.
 * Memory Usage: 15.5 MB, less than 46.32% of C++ online submissions for Word Ladder.
 */

#include <string>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    
    struct node {
        string word;
        int dist;
    };
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> validWordList(wordList.begin(), wordList.end());
        unordered_set<string> visited;
        queue<node> q;
        q.push({beginWord, 1});
        visited.insert(beginWord);
        
        while (!q.empty())
        {
            node t = q.front();
            q.pop();
            if (t.word == endWord)
            {
                return t.dist;
            }
            for (int i = 0; i < t.word.size(); i++)
            {
                for (int j = 0; j < 26; j++)
                {
                    string newWord = t.word;
                    newWord[i] = 'a' + j;
                    if (validWordList.find(newWord) != validWordList.end() && visited.find(newWord) == visited.end())
                    {
                        q.push({newWord, t.dist + 1});
                        visited.insert(newWord);
                    }
                }
            }
        }
        return 0;
    }
};

int main()
{
    return 0;
}
