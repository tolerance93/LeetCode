#include <vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = (int) height.size();
        int leftIdx = 0;
        int rightIdx = n - 1;
        int leftMax = 0;
        int rightMax = 0;
        int result = 0;
        
        while (leftIdx <= rightIdx)
        {
            if (leftMax <= rightMax)
            {
                if (height[leftIdx] > leftMax) leftMax = height[leftIdx];
                else result += leftMax - height[leftIdx];
                leftIdx++;
            }
            else
            {
                if (height[rightIdx] > rightMax) rightMax = height[rightIdx];
                else result += rightMax - height[rightIdx];
                rightIdx--;
            }
        }
        return result;
    }
};

