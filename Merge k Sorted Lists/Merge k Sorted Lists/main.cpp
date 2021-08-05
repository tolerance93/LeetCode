/**
 * Runtime: 24 ms, faster than 63.58% of C++ online submissions for Merge k Sorted Lists.
 * Memory Usage: 13.3 MB, less than 75.06% of C++ online submissions for Merge k Sorted Lists.
 */

#include <queue>
#include <vector>

using namespace std;


struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    
    struct mycmp {
        bool operator()(ListNode* a, ListNode* b)
        {
            return a->val > b->val;
        }
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, mycmp> pq;
        for (int i = 0; i < lists.size(); i++)
        {
            if (lists[i] != nullptr)
            {
                pq.push(lists[i]);
            }
        }
        
        ListNode* head = nullptr;
        ListNode* tail = nullptr;
        
        while (!pq.empty())
        {
            ListNode* temp = pq.top();
            pq.pop();
            
            if (head == nullptr)
            {
                head = temp;
                tail = temp;
            }
            else
            {
                tail->next = temp;
                tail = temp;
            }
            
            if (tail->next)
            {
                pq.push(tail->next);
            }
        }
        return head;
    }
};

int main()
{
    return 0;
}
