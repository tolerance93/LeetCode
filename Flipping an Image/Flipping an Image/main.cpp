/**
 * Runtime: 3 ms, faster than 88.71% of C++ online submissions for Flipping an Image.
 * Memory Usage: 8.8 MB, less than 74.48% of C++ online submissions for Flipping an Image.
 */

#include <vector>

using namespace std;

class Solution {
public:
    void swapAndInvert(vector<int>& image, int i, int j)
    {
        int temp = image[i];
        image[i] = 1 - image[j];
        image[j] = 1 - temp;
    }
    
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        vector<vector<int>> ans;
        int n = image.size();
        int m = image[0].size();
        
        int mid = m % 2 == 0 ? (m / 2) - 1 : m / 2;
        
        for (int i = 0; i < n; i++)
        {
            int pos = 0;
            while (pos <= mid)
            {
                swapAndInvert(image[i], pos, m - pos  - 1);
                pos++;
            }
        }
        return image;
    }
};

int main()
{
    return 0;
}
