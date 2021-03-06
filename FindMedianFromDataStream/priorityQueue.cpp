/*
 * Runtime: 160 ms, faster than 95.39% of C++ online submissions for Find Median from Data Stream.
 * Memory Usage: 47.4 MB, less than 38.08% of C++ online submissions for Find Median from Data Stream.
 *
 *
 * [Time Complexity]
 * - addNum(): O(logn), n: number of elements in DataStream.
 * At worst case, 2 push operations and 1 pop operation.
 * total 3logn + c where c is for other constant-time operation.
 * - findMedian(): O(1)
 *
 * [Space Complexity]
 * - O(n): leftPQ and rightPQ have total (n - 1) elements except median.
 *
 * [Algorithm]
 * leftPQ is max heap with elements less than or equal to median.
 * rightPQ is min heap with elements greater than median.
 * -addNum()
 * compare input num to median and add corresponding PQ.
 * update median under condition of parity.
 * - findMedian()
 * read or calculate return value under condition of parity.
 */

#include <iostream>
#include <queue>

using namespace std;

class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        while (!rightPQ.empty()) rightPQ.pop();
        while (!leftPQ.empty()) leftPQ.pop();
        median = 0;
        size = 0;
    }
    
    void addNum(int num) {
        if (!size)
        {
            median = num;
        }
        else
        {
            if (median >= num)
            {
                leftPQ.push(num);
                if (size % 2 != 0)
                {
                    rightPQ.push(median);
                    median = leftPQ.top();
                    leftPQ.pop();
                }
            }
            else
            {
                rightPQ.push(num);
                if (size % 2 == 0)
                {
                    leftPQ.push(median);
                    median = rightPQ.top();
                    rightPQ.pop();
                }
            }
        }
        size++;
    }
    
    double findMedian() {
        if (size % 2 == 0)
        {
            double res = median + rightPQ.top();
            return res / 2;
        }
        else return median;
    }
    
private:
    priority_queue<int, vector<int>, greater<int>> rightPQ;
    priority_queue<int, vector<int>, less<int>> leftPQ;
    int median;
    int size;
};
