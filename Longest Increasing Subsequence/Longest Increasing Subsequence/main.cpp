/**
 * Runtime: 4 ms, faster than 99.01% of C++ online submissions for Longest Increasing Subsequence.
 * Memory Usage: 10.6 MB, less than 36.40% of C++ online submissions for Longest Increasing Subsequence.
 *
 * Time Complexity: O(nlogn)
 * Space Complexity: O(logn)
 *
 * Algorithm
 * tail 배열에 현재까지 발견한 nums배열의 원소로 구성된 최소값 수열을 담습니다.
 * num배열을 읽어가며 tail 배열에 있는 숫자와 바꿔치기하거나,  tail 배열의 모든 숫자보다 큰 경우 맨 뒤에추가합니다.
 * - 바꿔치기의 경우 이진탐색을 통해 교체할 tail 원소의 위치를 찾습니다.
 * - tail배열에 추가할 경우 정답의 길이를 1칸 늘립니다.
 * tail 배열에 LIS가 담기는 것은 아닙니다!
 */

#include <vector>

using namespace std;

class Solution
{
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> tail(n, 987654321);
        int size = 0;
        
        for (int i = 0; i < n; i++)
        {
            int start = 0;
            int end = size;
            int m = 0;
            while (start < end)
            {
                m = (start + end) / 2;
                if (nums[i] <= tail[m])
                {
                    end = m;
                }
                else
                {
                    start = m + 1;
                }
            }
            tail[start] = nums[i];
            if (start == size) size++;
        }
        return size;
    }
};


int main()
{
    vector<int> nums = {10,9,2,5,1,3,7,101,18};
    Solution sol;
    sol.lengthOfLIS(nums);
    return 0;
}
