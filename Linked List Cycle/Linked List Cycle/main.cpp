/**
 * Runtime: 17 ms, faster than 16.96% of C++ online submissions for Linked List Cycle.
 * Memory Usage: 8 MB, less than 80.44% of C++ online submissions for Linked List Cycle.
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <unordered_map>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};


class Solution {
public:
    bool hasCycle2(ListNode *head) {
        unordered_map<ListNode*, bool> mymap;
        while (head != nullptr)
        {
            if (mymap.count(head)) {
                return true;
            }
            mymap[head] = true;
            head = head->next;
        }
        return false;
    }
    
    bool hasCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
            if (slow == fast) return true;
        }
        return false;
    }
};

int main()
{
    return 0;
}
