/**
 * Runtime: 44 ms, faster than 21.36% of C++ online submissions for Add Two Numbers.
 * Memory Usage: 71.5 MB, less than 46.40% of C++ online submissions for Add Two Numbers.
 */

  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

 
class Solution {
public:
    
    ListNode* addTwoNumbers2(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;
        
        int carry = 0;
        
        ListNode* head = nullptr;
        while (l1 != nullptr && l2 != nullptr)
        {
            int sum = l1->val + l2->val + carry;
            ListNode *n = new ListNode(sum % 10);
            n->next = head;
            head = n;
            carry = sum / 10;
            
            l1 = l1->next;
            l2 = l2->next;
        }
        
        while (l1 != nullptr)
        {
            int sum = l1->val + carry;
            ListNode *n = new ListNode(sum % 10);
            n->next = head;
            head = n;
            carry = sum / 10;
            l1 = l1->next;
        }
        
        while (l2 != nullptr)
        {
            int sum = l2->val + carry;
            ListNode *n = new ListNode(sum % 10);
            n->next = head;
            head = n;
            carry = sum / 10;
            l2 = l2->next;
        }
        
        if (carry)
        {
            ListNode *n = new ListNode(carry);
            n->next = head;
            head = n;
        }
        
        //Reverse
        ListNode* prev = nullptr;
        ListNode* curr = head;
        
        while (curr)
        {
            ListNode* n = curr->next;
            curr->next = prev;
            prev = curr;
            curr = n;
        }
        head = prev;
        return head;
        
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* cur = new ListNode(0, 0);
        ListNode* res = cur;
        
        int a,b,sum;
        int carry = 0;
        
        while (true)
        {
            if (!l1 && !l2) break;
            
            a = 0;
            b = 0;
            sum = 0;
            
            if (l1) a = l1->val;
            if (l2) b = l2->val;
            
            sum = (a + b + carry) % 10;
            carry = (a + b + carry) / 10;
            
            cur->val = sum;
            
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
            
            if ((l1 || l2) || carry)
            {
                cur->next = new ListNode(carry, 0);
                cur = cur->next;
            }
        }
        return cur;
    }
};


#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
