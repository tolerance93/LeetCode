/**
 * Runtime: 24 ms, faster than 68.15% of C++ online submissions for Remove All Adjacent Duplicates in String II.
 * Memory Usage: 10.2 MB, less than 69.61% of C++ online submissions for Remove All Adjacent Duplicates in String II.
 */

#include <string>
#include <stack>
#include <utility>

using namespace std;

class Solution {
public:
    string removeDuplicates(string A, int k) {
        stack<pair<char, int>> s;
        for (int i = 0; i < A.size(); i++) {
            if (s.empty() || A[i] != s.top().first) {
                s.push(make_pair(A[i], 1));
            } else {
                s.top().second++;
                int count = s.top().second;
                if (count == k) {
                    s.pop();
                }
            }
        }
        
        string ans = "";
        while (!s.empty()) {
            int count = s.top().second;
            while (count--) {
                ans.push_back(s.top().first);
            }
            s.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    return 0;
}
