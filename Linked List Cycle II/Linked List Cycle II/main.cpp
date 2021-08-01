/**
 * Runtime: 8 ms, faster than 84.97% of C++ online submissions for Linked List Cycle II.
 * Memory Usage: 7.5 MB, less than 89.38% of C++ online submissions for Linked List Cycle II.
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            
            if (slow == fast)
            {
                break;
            }
        }
        
        if (fast == nullptr || fast->next == nullptr) return nullptr;
        slow = head;
        while (slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};
