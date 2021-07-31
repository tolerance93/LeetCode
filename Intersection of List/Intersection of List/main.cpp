/**
 * Runtime: 40 ms, faster than 86.23% of C++ online submissions for Intersection of Two Linked Lists.
 * Memory Usage: 14.6 MB, less than 70.43% of C++ online submissions for Intersection of Two Linked Lists.
 */

#include <stddef.h>
#include <unordered_map>

using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL){}
};

class Solution {
public:
    
    int length(ListNode* head)
    {
        int count = 0;
        while (head != NULL)
        {
            count++;
            head = head->next;
        }
        return count;
    }
    
    // List Length
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        int m = length(headA);
        int n = length(headB);
        
        int d = abs(n - m);
        if (m > n) swap(headA, headB);
        
        for (int i = 0; i < d; i++)
        {
            headB = headB->next;
        }
        
        while (headA != NULL && headB != NULL)
        {
            if (headA == headB)
                return headA;
            headA = headA->next;
            headB = headB->next;
        }
        
        return NULL;
    }
    
    //unordered map
    ListNode *getIntersectionNode2(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode*, bool> map;
        while (headB != NULL)
        {
            map[headB] = true;
            headB = headB->next;
        }
        
        while (headA != NULL)
        {
            if (map.count(headA)) return headA;
            headA = headA->next;
        }
        return NULL;
    }
};

int main()
{
    return 0;
}
