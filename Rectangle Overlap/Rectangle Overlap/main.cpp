/**
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions for Rectangle Overlap.
 * Memory Usage: 8.3 MB, less than 66.70% of C++ online submissions for Rectangle Overlap.
 */

#include <vector>

using namespace std;

class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        
       
        
        int x1 = rec1[0];
        int y1 = rec1[1];
        int x2 = rec1[2];
        int y2 = rec1[3];
        
        int x3 = rec2[0];
        int y3 = rec2[1];
        int x4 = rec2[2];
        int y4 = rec2[3];
        
        //If either is not rectangle
        if (x1 == x2 || y1 == y2) return false;
        if (x3 == x4 || y3 == y4) return false;
        
        //Does overlap?
        if (x1 >= x4 || x2 <= x3) return false;
        if (y1 >= y4 || y2 <= y3) return false;
        
        return true;
    }
};
