#include <string>
#include <stack>
#include <iostream>

using namespace std;

class Solution {
public:
    
    bool backspaceCompare_fromback(string S, string T) {
        int i = (int)S.length() - 1, j = (int)T.length() - 1, back;
        while (true) {
            back = 0;
            while (i >= 0 && (back > 0 || S[i] == '#')) {
                back += S[i] == '#' ? 1 : -1;
                i--;
            }
            back = 0;
            while (j >= 0 && (back > 0 || T[j] == '#')) {
                back += T[j] == '#' ? 1 : -1;
                j--;
            }
            if (i >= 0 && j >= 0 && S[i] == T[j]) {
                i--;
                j--;
            } else {
                break;
            }
        }
        return i == -1 && j == -1;
    }
    
    bool backspaceCompare(string s, string t) {
        stack<char> sStack;
        stack<char> tStack;
        
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != '#') sStack.push(s[i]);
            else
            {
                if (!sStack.empty()) sStack.pop();
            }
        }
        
        for (int j = 0; j < t.size(); j++)
        {
            if (t[j] != '#') tStack.push(t[j]);
            else
            {
                if (!tStack.empty()) tStack.pop();
            }
        }
        
        if (sStack.size() != tStack.size()) return false;
        while (!sStack.empty())
        {
            if (sStack.top() != tStack.top()) return false;
            sStack.pop();
            tStack.pop();
        }
        return true;
    }
};

int main()
{
    Solution sol;
    string s = "abc##abc##";
    string t = "aabc##";
    //string s = "e##e#o##oyof##q";
    //string t = "e##e#fq##o##oyof##q";
    cout << sol.backspaceCompare_fromback(s, t) << endl;
    return 0;
}
