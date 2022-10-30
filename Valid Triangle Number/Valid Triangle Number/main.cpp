/**
 * Runtime: 512 ms, faster than 25.57% of C++ online submissions for Valid Triangle Number.
 * Memory Usage: 12.9 MB, less than 51.94% of C++ online submissions for Valid Triangle Number.
 */

#include <vector>
using namespace std;

class Solution {
public:
    
    int binarySearch(int sum, int start, int end, vector<int>& nums)
    {
        if (sum > nums[end]) return end;
        int ans = -1;
        while (start <= end)
        {
            int mid = (start + end) / 2;
            if (nums[mid] >= sum)
            {
                end = mid - 1;
            }
            else
            {
                ans = mid;
                start = mid + 1;;
            }
        }
        return ans;
    }
    
    int triangleNumber(vector<int>& nums) {
        int size = nums.size();
        if (size < 3)
        {
            return 0;
        }
        //정렬
        sort(nums.begin(), nums.end());
        int res = 0;
        //삼각형의 결정 조건은 가장 긴 변의 길이가 나머지 두 변의 길이의 합 보다 작아야 한다.
        //nums는 오름차순으로 정렬되어 있으므로, nums[i], nums[j]가 작은 두 변.
        //삼각형의 결정조건을 만족하는 가장 긴 index를 binary search로 찾아 갯수 계산
        for (int i = 0; i < size - 2; i++)
        {
            for (int j = i + 1; j < size - 1; j++)
            {
                int maxIndex = binarySearch(nums[i] + nums[j], j + 1, nums.size() - 1, nums);
                if (maxIndex != -1) res += maxIndex - j;
            }
        }
        return res;
    }
};

int main()
{
    vector<int> input = {2,2,3,4};
    Solution sol;
    sol.triangleNumber(input);
    return 0;
}
