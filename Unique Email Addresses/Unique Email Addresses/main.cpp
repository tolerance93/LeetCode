/**
 * Runtime: 16 ms, faster than 99.15% of C++ online submissions for Unique Email Addresses.
 * Memory Usage: 15 MB, less than 30.76% of C++ online submissions for Unique Email Addresses.
 */

#include <vector>
#include <string>
#include <unordered_set>
#include <iostream>

using namespace std;

class Solution {
public:
    
    int findAtPosition(string& email)
    {
        for (int i = 0; i < email.length(); i++)
        {
            if (email[i] == '@')
            {
                return i;
            }
        }
        return -1;
    }
    
    string extractDomainWithAtPostion(string& email, int i)
    {
        return email.substr(i + 1, email.length());
    }
    
    string extractLocalWithAtPostion(string& email, int i)
    {
        return email.substr(0, i);
    }
    
    string extractUniqueLocal(string& local)
    {
        string uniqueLocal;
        for (char c : local) {
            if (c == '+') {
                break;
            }
            else if (c == '.') {
                continue;
            }
            else
            {
                uniqueLocal.push_back(c);
            }
        }
        return uniqueLocal;
    }
    
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> set;
        string domain;
        string local;
        string uniqueEmail;
        for (string& email : emails)
        {
            int atPosition = findAtPosition(email);
            domain = extractDomainWithAtPostion(email, atPosition);
            local = extractLocalWithAtPostion(email, atPosition);
            uniqueEmail = extractUniqueLocal(local) + '@' + domain;
            set.insert(uniqueEmail);
        }
        return (int) set.size();
    }
};

int main()
{
    vector<string> input = {"test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"};
    Solution sol;
    cout << sol.numUniqueEmails(input) << endl;
    return 0;
}
