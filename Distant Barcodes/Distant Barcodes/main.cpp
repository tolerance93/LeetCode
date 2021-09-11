/**
 * Runtime: 87 ms, faster than 68.11% of C++ online submissions for Distant Barcodes.
 * Memory Usage: 40.1 MB, less than 90.54% of C++ online submissions for Distant Barcodes.
 */

#include <vector>
#include <queue>

using namespace std;

// O(n)
class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        vector<int> count(10001, 0);
        int maxValue = 0;
        int maxPos = -1;
        
        for (auto num : barcodes)
        {
            count[num]++;
            if (count[num] > maxValue)
            {
                maxValue = count[num];
                maxPos = num;
            }
        }
        
        int pos = 0;
        for (int i = 0; i < count.size(); i++)
        {
            int cur = i == 0 ? maxPos : i;
            if (count[cur] > 0)
            {
                while (count[cur])
                {
                    barcodes[pos] = cur;
                    count[cur]--;
                    pos += 2;
                    if (pos >= barcodes.size()) pos = 1;
                }
            }
        }
        return barcodes;
    }
};

// O(nlogn)
class Solution2 {
public:
    
    struct cmp {
        bool operator()(pair<int, int>&a, pair<int, int>&b) {
            return a.second <= b.second;
        }
    };

    
    void swap(vector<int>& barcodes, int i, int j)
    {
        int temp = barcodes[i];
        barcodes[i] = barcodes[j];
        barcodes[j] = temp;
    }
    
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        vector<int> count(10001, 0);
        priority_queue<pair<int,int>,vector<pair<int,int>>, cmp> pq;
        int n = barcodes.size();
        vector<int> ans(n);
        
        for (int i = 0; i < barcodes.size(); i++)
        {
            count[barcodes[i]]++;
        }
        
        for (int i = 0; i < count.size(); i++)
        {
            if (count[i] != 0)
            {
                pq.push(make_pair(i, count[i]));
            }
        }
        int pos = 0;
        
        int soFar = 0;
        while (soFar < n)
        {
            pair<int, int> cur = pq.top();
            pq.pop();
            int num = cur.first;
            int count = cur.second;
            
            while (count)
            {
                ans[pos] = num;
                pos += 2;
                count--;
                soFar++;
                if (soFar == n) return ans;
                if (pos >= n) pos = 1;
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> input = {1,1,2};
    Solution sol;
    sol.rearrangeBarcodes(input);
    return 0;
}
