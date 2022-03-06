#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = (int)height.size() - 1;
        int maxArea = (j - i) * min(height[i], height[j]);
        
        while (i < j)
        {
            if (height[i] < height[j])
            {
                i = i + 1;
            }
            else
            {
                j = j - 1;
            }
            maxArea = max(maxArea, (j - i) * min(height[i], height[j]));
        }
        return maxArea;
    }
};

int main()
{
    return 0;
}
