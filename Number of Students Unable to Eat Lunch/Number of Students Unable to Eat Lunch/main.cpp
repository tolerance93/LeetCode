/**
 * Runtime: 4 ms, faster than 56.85% of C++ online submissions for Number of Students Unable to Eat Lunch.
 * Memory Usage: 8.7 MB, less than 86.37% of C++ online submissions for Number of Students Unable to Eat Lunch.
 */
#include <vector>

using namespace std;

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int zeroStudentCount = 0;
        int oneStudentCount = 0;
        int zeroSandCount = 0;
        int oneSandCount = 0;
        
        for (int i = 0; i < students.size(); i++)
        {
            if (students[i] == 0)
            {
                zeroStudentCount++;
            }
            else if (students[i] == 1)
            {
                oneStudentCount++;
            }
            
            if (sandwiches[i] == 0)
            {
                zeroSandCount++;
            }
            else if (sandwiches[i] == 1)
            {
                oneSandCount++;
            }
        }
        
        if (zeroStudentCount == zeroSandCount) return 0;
        
        if (zeroSandCount > zeroStudentCount)
        {
            zeroSandCount = 0;
            for (int i = 0; i < sandwiches.size(); i++)
            {
                if (sandwiches[i] == 0) zeroSandCount++;
                if (zeroSandCount == zeroStudentCount + 1)
                {
                    return sandwiches.size() - i + 1;
                }
            }
        }
        else
        {
            oneSandCount = 0;
            for (int i = 0; i < sandwiches.size(); i++)
            {
                if (sandwiches[i] == 1) oneSandCount++;
                if (oneSandCount == oneStudentCount + 1)
                {
                    return sandwiches.size() - i + 1;
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
